/*
 * Copyright (C) 2019,2020 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "ogs-sctp.h"

#include "ngap-path.h"
// #include "sgx_api.h"
#include "App.h"
#include <unistd.h>



#if HAVE_USRSCTP
static void usrsctp_recv_handler(struct socket *socket, void *data, int flags);
#else
static void lksctp_accept_handler(short when, ogs_socket_t fd, void *data);
#endif

void ngap_accept_handler(ogs_sock_t *sock);
void ngap_recv_handler(ogs_sock_t *sock);

ogs_sock_t *ngap_server(ogs_socknode_t *node)
{
    char buf[OGS_ADDRSTRLEN];
    ogs_sock_t *sock = NULL;
#if !HAVE_USRSCTP
    ogs_poll_t *poll = NULL;
#endif

    ogs_assert(node);

#if HAVE_USRSCTP
    sock = ogs_sctp_server(SOCK_SEQPACKET, node->addr, node->option);
    if (!sock) return NULL;
    usrsctp_set_non_blocking((struct socket *)sock, 1);
    usrsctp_set_upcall((struct socket *)sock, usrsctp_recv_handler, NULL);
#else
    sock = ogs_sctp_server(SOCK_STREAM, node->addr, node->option);
    if (!sock) return NULL;
    poll = ogs_pollset_add(ogs_app()->pollset,
            OGS_POLLIN, sock->fd, lksctp_accept_handler, sock);
    ogs_assert(node);

    node->poll = poll;
#endif

    node->sock = sock;
    node->cleanup = ogs_sctp_destroy;

    ogs_info("ngap_server() [%s]:%d",
            OGS_ADDR(node->addr, buf), OGS_PORT(node->addr));

    return sock;
}

void ngap_recv_upcall(short when, ogs_socket_t fd, void *data)
{
    // ogs_error("start ngap_recv_upcall fd=%d", fd);
    // int ret = start_dtls_server(fd);
    // ogs_error("after start_dtls_server ret =%d", ret);
    ogs_sock_t *sock = NULL;

    ogs_assert(fd != INVALID_SOCKET);
    sock = data;
    ogs_assert(sock);

    ngap_recv_handler(sock);
}

#if HAVE_USRSCTP
static void usrsctp_recv_handler(struct socket *socket, void *data, int flags)
{
    int events;

    while ((events = usrsctp_get_events(socket)) &&
           (events & SCTP_EVENT_READ)) {
        ngap_recv_handler((ogs_sock_t *)socket);
    }
}
#else
static void lksctp_accept_handler(short when, ogs_socket_t fd, void *data)
{
    ogs_assert(data);
    ogs_assert(fd != INVALID_SOCKET);

    ngap_accept_handler(data);
}
#endif
int is_up = 0;

void ngap_accept_handler(ogs_sock_t *sock)
{
    char buf[OGS_ADDRSTRLEN];
    ogs_sock_t *new = NULL;

    ogs_assert(sock);

    new = ogs_sock_accept(sock);
    if (new) {

        ogs_sockaddr_t *addr = NULL;

        addr = ogs_calloc(1, sizeof(ogs_sockaddr_t));
        ogs_assert(addr);
        memcpy(addr, &new->remote_addr, sizeof(ogs_sockaddr_t));

        ogs_error("gNB-N2 accepted[%s]:%d in ng-path module",
            OGS_ADDR(addr, buf), OGS_PORT(addr));

        ngap_event_push(AMF_EVENT_NGAP_LO_ACCEPT,
                new, addr, NULL, 0, 0);

        int ret = 0;
        //ret = start_dtls_server(new->fd);
        ogs_error("after start_dtls_server ret =%d fd=%d", ret, new->fd);
        // is_up = 1;
    } else {
        ogs_log_message(OGS_LOG_ERROR, ogs_socket_errno, "accept() failed");
    }
}


void ngap_recv_handler(ogs_sock_t *sock)
{
    // if(is_up)
    // {
    //     // dtls_recv_handler(sock->fd);
    //     ogs_ngap_message_t ngap_message;
    //     // sgx_dtls_recv_and_ngap_decode(&ngap_message, sock->fd);
    // void *retval = ogs_malloc(sizeof(ogs_ngap_message_t));
    // ogs_error("calling ecall_dtls_recv_and_ngap_decode" );
    // dtls_recv_handler2(retval, sock->fd);
    // ogs_error("returned ecall_dtls_recv_and_ngap_decode" );
    // ngap_message = *(ogs_ngap_message_t *)retval;
    // if(ngap_message.choice.initiatingMessage->value.choice.AMFConfigurationUpdate.protocolIEs.list.count == 0)
    //     ngap_message = *(ogs_ngap_message_t *)retval;
    // // ogs_error("The number is : %d %s.\n",retval,ali );
    //     // int rc = sgx_ngap_decode(&ngap_message, pkbuf);

    //     // dtls_recv_handler(sock->fd);

    //     return;
    // }

    ogs_pkbuf_t *pkbuf;
    int size;
    ogs_sockaddr_t *addr = NULL;
    ogs_sockaddr_t from;
    ogs_sctp_info_t sinfo;
    int flags = MSG_PEEK;

    ogs_assert(sock);

    pkbuf = ogs_pkbuf_alloc(NULL, OGS_MAX_SDU_LEN);
    ogs_assert(pkbuf);
    ogs_pkbuf_put(pkbuf, OGS_MAX_SDU_LEN);
    
    //size = dtls_recv_handler(sock->fd);
    size = ogs_sctp_recvmsg(
           sock, pkbuf->data, pkbuf->len, &from, &sinfo, &flags);
           
    if (size < 0 || size >= OGS_MAX_SDU_LEN) {
        ogs_error("ogs_sctp_recvmsg(%d) failed(%d:%s)",
                size, errno, strerror(errno));
        ogs_pkbuf_free(pkbuf);
        return;
    }

    if (flags & MSG_NOTIFICATION) {
        union sctp_notification *not =
            (union sctp_notification *)pkbuf->data;

        switch(not->sn_header.sn_type) {
        case SCTP_ASSOC_CHANGE :
            ogs_debug("SCTP_ASSOC_CHANGE:"
                    "[T:%d, F:0x%x, S:%d, I/O:%d/%d]", 
                    not->sn_assoc_change.sac_type,
                    not->sn_assoc_change.sac_flags,
                    not->sn_assoc_change.sac_state,
                    not->sn_assoc_change.sac_inbound_streams,
                    not->sn_assoc_change.sac_outbound_streams);

            if (not->sn_assoc_change.sac_state == SCTP_COMM_UP) {
                ogs_debug("SCTP_COMM_UP");

                addr = ogs_calloc(1, sizeof(ogs_sockaddr_t));
                ogs_assert(addr);
                memcpy(addr, &from, sizeof(ogs_sockaddr_t));
                    // ogs_msleep(10000);

                int ret = start_dtls_server(sock->fd);
                ogs_error("after start_dtls_server ret =%d", ret);
                is_up = 1;
                //size = dtls_recv_handler(sock->fd);

                ngap_event_push(AMF_EVENT_NGAP_LO_SCTP_COMM_UP,
                        sock, addr, NULL,
                        not->sn_assoc_change.sac_inbound_streams,
                        not->sn_assoc_change.sac_outbound_streams);
            } else if (not->sn_assoc_change.sac_state == SCTP_SHUTDOWN_COMP ||
                    not->sn_assoc_change.sac_state == SCTP_COMM_LOST) {

                if (not->sn_assoc_change.sac_state == SCTP_SHUTDOWN_COMP)
                    ogs_debug("SCTP_SHUTDOWN_COMP");
                if (not->sn_assoc_change.sac_state == SCTP_COMM_LOST)
                    ogs_debug("SCTP_COMM_LOST");

                addr = ogs_calloc(1, sizeof(ogs_sockaddr_t));
                ogs_assert(addr);
                memcpy(addr, &from, sizeof(ogs_sockaddr_t));

                ngap_event_push(AMF_EVENT_NGAP_LO_CONNREFUSED,
                        sock, addr, NULL, 0, 0);
            }
            break;
        case SCTP_SHUTDOWN_EVENT :
            ogs_debug("SCTP_SHUTDOWN_EVENT:[T:%d, F:0x%x, L:%d]",
                    not->sn_shutdown_event.sse_type,
                    not->sn_shutdown_event.sse_flags,
                    not->sn_shutdown_event.sse_length);
            addr = ogs_calloc(1, sizeof(ogs_sockaddr_t));
            ogs_assert(addr);
            memcpy(addr, &from, sizeof(ogs_sockaddr_t));

            ngap_event_push(AMF_EVENT_NGAP_LO_CONNREFUSED,
                    sock, addr, NULL, 0, 0);
            break;

        case SCTP_SEND_FAILED :
#if HAVE_USRSCTP
            ogs_error("SCTP_SEND_FAILED:[T:%d, F:0x%x, S:%d]",
                    not->sn_send_failed_event.ssfe_type,
                    not->sn_send_failed_event.ssfe_flags,
                    not->sn_send_failed_event.ssfe_error);
#else
            ogs_error("SCTP_SEND_FAILED:[T:%d, F:0x%x, S:%d]",
                    not->sn_send_failed.ssf_type,
                    not->sn_send_failed.ssf_flags,
                    not->sn_send_failed.ssf_error);
#endif
            break;

        case SCTP_PEER_ADDR_CHANGE:
            ogs_warn("SCTP_PEER_ADDR_CHANGE:[T:%d, F:0x%x, S:%d]", 
                    not->sn_paddr_change.spc_type,
                    not->sn_paddr_change.spc_flags,
                    not->sn_paddr_change.spc_error);
            break;
        case SCTP_REMOTE_ERROR:
            ogs_warn("SCTP_REMOTE_ERROR:[T:%d, F:0x%x, S:%d]", 
                    not->sn_remote_error.sre_type,
                    not->sn_remote_error.sre_flags,
                    not->sn_remote_error.sre_error);
            break;
        default :
            ogs_error("Discarding event with unknown flags:0x%x type:0x%x",
                    flags, not->sn_header.sn_type);
            break;
        }
    } else if (flags & MSG_EOR) {
        ogs_pkbuf_trim(pkbuf, size);

        addr = ogs_calloc(1, sizeof(ogs_sockaddr_t));
        ogs_assert(addr);
        memcpy(addr, &from, sizeof(ogs_sockaddr_t));
        ogs_error("MSG_EOR");
        dtls_recv_handler(sock->fd, pkbuf->data, pkbuf->len);

        ngap_event_push(AMF_EVENT_NGAP_MESSAGE, sock, addr, pkbuf, 0, 0);
        return;
    } else {
        if (ogs_socket_errno != OGS_EAGAIN) {
            ogs_fatal("ogs_sctp_recvmsg(%d) failed(%d:%s-0x%x)",
                    size, errno, strerror(errno), flags);
            ogs_assert_if_reached();
        } else {
            ogs_error("ogs_sctp_recvmsg(%d) failed(%d:%s-0x%x)",
                    size, errno, strerror(errno), flags);
        }
    }

    ogs_pkbuf_free(pkbuf);
}
