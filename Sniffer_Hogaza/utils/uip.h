#ifndef _UIP_H_
#define _UIP_H_

#ifndef HTONS
#   if UIP_BYTE_ORDER == UIP_BIG_ENDIAN
#      define HTONS(n) (n)
#      define HTONL(n) (n)
#   else /* UIP_BYTE_ORDER == UIP_BIG_ENDIAN */
#      define HTONS(n) (u16_t)((((u16_t) (n)) << 8) | (((u16_t) (n)) >> 8))
#      define HTONL(n) (((u32_t)HTONS(n) << 16) | HTONS((u32_t)(n) >> 16))
#   endif /* UIP_BYTE_ORDER == UIP_BIG_ENDIAN */
#else
#error "HTONS already defined!"
#endif /* HTONS */

/**
 * Convert 16-bit quantity from host byte order to network byte order.
 *
 * This function is primarily used for converting variables from host
 * byte order to network byte order. For converting constants to
 * network byte order, use the HTONS() macro instead.
 */
#ifndef htons
uint16_t htons(uint16_t val);
#endif /* htons */
#ifndef ntohs
#define ntohs htons
#endif

#ifndef htonl
uint32_t htonl(uint32_t val);
#endif /* htonl */
#ifndef ntohl
#define ntohl htonl
#endif

uint16_t
htons(uint16_t val)
{
  return HTONS(val);
}

uint32_t
htonl(uint32_t val)
{
  return HTONL(val);
}

#endif
