/* command_packet_stream.h
 * By Ron Bowes
 * Created May, 2014
 *
 * A class for handling streams of command packets.
 */
#ifndef __COMMAND_PACKET_STREAM_H__
#define __COMMAND_PACKET_STREAM_H__

#include <stdlib.h>

#include "command_packet.h"

#ifdef WIN32
#include "pstdint.h"
#else
#include <stdint.h>
#endif

typedef struct
{
  buffer_t *buffer;
  NBBOOL    is_request;
} command_packet_stream_t;

command_packet_stream_t *command_packet_stream_create();

void              command_packet_stream_feed(command_packet_stream_t *stream, uint8_t *data, uint16_t length);
NBBOOL            command_packet_stream_ready(command_packet_stream_t *stream);
command_packet_t *command_packet_stream_read(command_packet_stream_t *stream);

#endif
