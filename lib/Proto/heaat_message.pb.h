/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.2-dev */

#ifndef PB_EMBEDDEDMESSAGES_HEAAT_MESSAGE_PB_H_INCLUDED
#define PB_EMBEDDEDMESSAGES_HEAAT_MESSAGE_PB_H_INCLUDED
#include "pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _HeaatMessage {
    int32_t red;
    int32_t green;
    int32_t blue;
    int32_t brightness;
} HeaatMessage;


/* Initializer values for message structs */
#define HeaatMessage_init_default                {0, 0, 0, 0}
#define HeaatMessage_init_zero                   {0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define HeaatMessage_red_tag                     1
#define HeaatMessage_green_tag                   2
#define HeaatMessage_blue_tag                    3
#define HeaatMessage_brightness_tag              4

/* Struct field encoding specification for nanopb */
#define HeaatMessage_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    red,               1) \
X(a, STATIC,   SINGULAR, INT32,    green,             2) \
X(a, STATIC,   SINGULAR, INT32,    blue,              3) \
X(a, STATIC,   SINGULAR, INT32,    brightness,        4)
#define HeaatMessage_CALLBACK NULL
#define HeaatMessage_DEFAULT NULL

extern const pb_msgdesc_t HeaatMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define HeaatMessage_fields &HeaatMessage_msg

/* Maximum encoded size of messages (where known) */
#define HeaatMessage_size                        44

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
