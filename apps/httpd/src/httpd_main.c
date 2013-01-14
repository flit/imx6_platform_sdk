/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "sdk.h"
#include "platform_init.h"
#include "iomux_config.h"
#include "timer/timer.h"
#include "httpd.h"
#include "fs.h"
#include "fsdata.h"
#include "httpd_structs.h"

#include "lwip/opt.h"
#include "lwip/init.h"
#include "lwip/raw.h"
#include "lwip/debug.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/sys.h"
#include "lwip/stats.h"
#include "lwip/ip.h"
#include "lwip/ip_frag.h"
#include "lwip/udp.h"
#include "lwip/snmp_msg.h"
#include "lwip/tcp_impl.h"
#include "lwip/dhcp.h"
#include "lwip/dns.h"
#include "lwip/autoip.h"

#include "mx6_lwip.h"

#define CLOCKTICKS_PER_MS (1)

struct netif g_netif;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void netif_status_callback(struct netif *netif)
{
    char buf[64];
    bool isUp = (g_netif.flags & NETIF_FLAG_UP);
    printf("netif: %s (ip=%s)\n",
        isUp ? "up" : "down",
        ipaddr_ntoa_r(&g_netif.ip_addr, buf, sizeof(buf)));
}

void netif_link_status_callback(struct netif *netif)
{
    printf("netif: link %s\n", (g_netif.flags & NETIF_FLAG_LINK_UP) ? "up" : "down");
}

void init_lwip(void)
{
    lwip_init();

    ip_addr_t addr;
    ip_addr_t netmask;
    ip_addr_t gw;
    IP4_ADDR(&addr, 10, 81, 4, 142); //192, 168, 10, 159);
    IP4_ADDR(&netmask, 255, 255, 255, 0);
    IP4_ADDR(&gw, 10, 81, 7, 254); //192, 168, 10, 200);

#if LWIP_NETIF_HOSTNAME
    g_netif.hostname = "lwip";
#endif

    netif_add(&g_netif, &addr, &netmask, &gw, NULL, enet_init, ethernet_input);
    netif_set_status_callback(&g_netif, netif_status_callback);
    netif_set_link_callback(&g_netif, netif_link_status_callback);
    netif_set_default(&g_netif);

    dns_init();

    // DHCP
    if (0)
    {
        dhcp_start(&g_netif);
    }
    // Auto IP
    else if (0)
    {
        autoip_start(&g_netif);
    }
    // Static IP address
    else
    {
        netif_set_up(&g_netif);
    }
    
    httpd_init();

    printf("TCP/IP initialized.\n");
}

void run(void)
{
    uint32_t last_arp_time = 0;
    uint32_t last_time = 0;
    uint32_t last_dhcp_coarse_time = 0;
    uint32_t last_dhcp_fine_time = 0;
    
    while (true)
    {
        // Poll for incoming packet.
        enet_poll_for_packet(&g_netif);

        // Call timers.
        if (sys_now() - last_arp_time >= ARP_TMR_INTERVAL * CLOCKTICKS_PER_MS)  
        {  
            etharp_tmr();  
            last_arp_time = sys_now();  
        }  
        if (sys_now() - last_time >= TCP_TMR_INTERVAL * CLOCKTICKS_PER_MS)
        {  
            tcp_tmr();  
            last_time = sys_now();  
        }
        if (sys_now() - last_dhcp_coarse_time >= DHCP_COARSE_TIMER_MSECS * CLOCKTICKS_PER_MS)
        {  
            dhcp_coarse_tmr();  
            last_dhcp_coarse_time = sys_now();  
        }
        if (sys_now() - last_dhcp_fine_time >= DHCP_FINE_TIMER_MSECS * CLOCKTICKS_PER_MS)
        {  
            dhcp_fine_tmr();  
            last_dhcp_fine_time = sys_now();  
        }
    }
}

void main(void)
{
    platform_init();
    init_lwip();

    run();

    // Disable Ethernet.
//     imx_enet_stop(dev0);
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
