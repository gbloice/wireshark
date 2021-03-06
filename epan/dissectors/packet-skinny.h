/* Do not modify this file. Changes will be overwritten */
/* Generated Automatically                              */
/* packet-skinny.h                                      */

/* packet-skinny.h
 * Dissector for the Skinny Client Control Protocol
 *   (The "D-Channel"-Protocol for Cisco Systems' IP-Phones)
 *
 * Author: Diederik de Groot <ddegroot@user.sf.net>, Copyright 2014
 * Rewritten to support newer skinny protocolversions (V0-V22)
 * Based on previous versions/contributions:
 *  - Joerg Mayer <jmayer@loplof.de>, Copyright 2001
 *  - Paul E. Erkkila (pee@erkkila.org) - fleshed out the decode
 *    skeleton to report values for most message/message fields.
 *    Much help from Guy Harris on figuring out the wireshark api.
 *  - packet-aim.c by Ralf Hoelzer <ralf@well.com>, Copyright 2000
 *  - Wireshark - Network traffic analyzer,
 *    By Gerald Combs <gerald@wireshark.org>, Copyright 1998
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*
 * Generated Automatically Using (from wireshark base directory):
 *   cog.py -D xmlfile=tools/SkinnyProtocolOptimized.xml -d -c -o epan/dissectors/packet-skinny.c epan/dissectors/packet-skinny.c.in
 */

#include <epan/wmem/wmem.h>

/* request response tracking */
typedef struct _skinny_req_resp_t {
  guint32                request_frame;
  guint32                response_frame;
  nstime_t               request_time;
} skinny_req_resp_t;

/* begin conversaton  info*/
typedef enum _skinny_message_type_t {
  SKINNY_MSGTYPE_EVENT    = 0,
  SKINNY_MSGTYPE_REQUEST  = 1,
  SKINNY_MSGTYPE_RESPONSE = 2,
} skinny_message_type_t;

typedef struct _skinny_conv_info_t {
  skinny_message_type_t   mtype;
  wmem_map_t            * pending_req_resp;
  wmem_map_t            * requests;
  wmem_map_t            * responses;
  gint32                  lineId;
  //guint32                 callId;
  //guint32                 passThruId;
  //guint32                 transactionId;
  //guint32                 callState;
} skinny_conv_info_t;
/* end conversation info */

/* Containers for tapping relevant data */
/* WIP: will be (partially) replaced in favor of conversionation, dependents: ui/voip_calls.c */
typedef struct _skinny_info_t
{
  guint32                 messId;
  guint32                 maxProtocolVersion;
  gint32                  lineId;
  guint32                 callId;
  guint32                 passThruId;
  const gchar           * messageName;
  guint32                 callState;
  gboolean                hasCallInfo;
  gchar                 * callingParty;
  gchar                 * calledParty;
  gint32                  mediaReceptionStatus;
  gint32                  mediaTransmissionStatus;
  gint32                  multimediaReceptionStatus;
  gint32                  multimediaTransmissionStatus;
  gint32                  multicastReceptionStatus;
  //skinny_conv_info_t    * skinny_conv;
} skinny_info_t;

/*
 * Editor modelines  -  http://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 2
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=2 tabstop=8 expandtab:
 * :indentSize=2:tabSize=8:noTabs=true:
 */
