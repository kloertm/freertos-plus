/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Simon Goldschmidt
 *
 */
#ifndef LWIP_HDR_LWIPOPTS_H__
#define LWIP_HDR_LWIPOPTS_H_

// Don't change:
#define NO_SYS                              1
#define NO_SYS_NO_TIMERS                    0
#define LWIP_NETIF_TX_SINGLE_PBUF           1
#define LWIP_ESP                            1
#define PBUF_RSV_FOR_WLAN                   1
#define ICACHE_FLASH                        1
#define EBUF_LWIP                           1

// Leave unchanged unless you really know what you're doing:
#define MEM_ALIGNMENT                       4
#define TCP_MSS                             1460
#define TCP_SND_BUF                         (2*TCP_MSS)
#define MEMP_MEM_MALLOC                     1
#define MEM_LIBC_MALLOC                     1

#define LWIP_RAND()                         rand()

// Tweakable:
#define ESP_TIMEWAIT_THRESHOLD              10000

#define TCP_TMR_INTERVAL                    125
#define TCP_KEEPIDLE_DEFAULT                3000
#define TCP_KEEPINTVL_DEFAULT               1000
#define TCP_KEEPCNT_DEFAULT                 3

#define LWIP_NETCONN                        0
#define LWIP_SOCKET                         0
#define MEMP_NUM_SYS_TIMEOUT                8

#define TCP_LOCAL_PORT_RANGE_START          0x1000
#define TCP_LOCAL_PORT_RANGE_END            0x7fff
#define UDP_LOCAL_PORT_RANGE_START          0x1000
#define UDP_LOCAL_PORT_RANGE_END            0x7fff

#define ARP_QUEUEING                        1
#define ETHARP_TRUST_IP_MAC                 1
#define IP_FRAG                             0
#define IP_REASSEMBLY                       0
#define IP_FRAG_USES_STATIC_BUF             1
#define TCP_QUEUE_OOSEQ                     0
#define LWIP_TCP_KEEPALIVE                  1
#define LWIP_STATS                          0

#ifdef LWIP_OUR_IF
  #define LWIP_NETIF_HOSTNAME               1 // our eagle_lwip_if.o required
  #define LWIP_NETIF_HOSTNAME_PREFIX        "esp8266-"
#endif

//

#define LWIP_PROVIDE_ERRNO 1
#define LWIP_TIMEVAL_PRIVATE 0
#define MEMP_OVERFLOW_CHECK 1
#define MEMP_SANITY_CHECK 1
#define ARP_QUEUEING 1
#define ETHARP_SUPPORT_VLAN 1
#define IP_FORWARD 1
#define IP_SOF_BROADCAST 1
#define IP_SOF_BROADCAST_RECV 1
#define LWIP_RANDOMIZE_INITIAL_LOCAL_PORTS 1
#define LWIP_AUTOIP 1
#define LWIP_DHCP_AUTOIP_COOP 1
#define LWIP_SNMP 1
#define LWIP_IGMP 1
#define LWIP_DNS 1
#define LWIP_UDPLITE 1
#define LWIP_NETBUF_RECVINFO 1
#define LWIP_NETIF_HOSTNAME 1
#define LWIP_NETIF_API 1
#define LWIP_NETIF_LINK_CALLBACK        1
#define LWIP_NETIF_REMOVE_CALLBACK      1
#define LWIP_NETIF_HWADDRHINT           1
#define LWIP_NETIF_LOOPBACK             1
#define LWIP_HAVE_LOOPIF                1
#define LWIP_HAVE_SLIPIF                0 //not working because sio_* functions missing ==> TODO
#define LWIP_IPV6                       0 //not working with ip_addr_t* in tcp_helper.c ==> TODO


/* Prevent having to link sys_arch.c (we don't test the API layers in unit tests) */
#define NO_SYS                          0
#define LWIP_NETCONN                    1
#define LWIP_SOCKET                     1

/* Enable DHCP to test it, disable UDP checksum to easier inject packets */
#define LWIP_DHCP                       1

/* Minimal changes to opt.h required for tcp unit tests: */
#define MEM_SIZE                        16000
#define TCP_SND_QUEUELEN                40
#define MEMP_NUM_TCP_SEG                TCP_SND_QUEUELEN
#define TCP_SND_BUF                     (12 * TCP_MSS)
#define TCP_WND                         (10 * TCP_MSS)
#define LWIP_WND_SCALE                  1
#define TCP_RCV_SCALE                   0
#define PBUF_POOL_SIZE                  400 // pbuf tests need ~200KByte

/* Minimal changes to opt.h required for etharp unit tests: */
#define ETHARP_SUPPORT_STATIC_ENTRIES   1

#endif /* LWIP_HDR_LWIPOPTS_H__ */
