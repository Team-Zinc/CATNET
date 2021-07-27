// A funky chonky mix of Linux, Mac, and BSD code! :D

#ifndef _NET_IF_TUN_H_
#define _NET_IF_TUN_H_

#include <stdint.h>


/* Refer to if_tunvar.h for the softc stuff */

/* Maximum transmit packet size (default) */
#define TUNMTU          1500

/* Maximum receive packet size (hard limit) */
#define TUNMRU          65535

struct tuninfo {
        int     baudrate;               /* linespeed */
        unsigned short  mtu;            /* maximum transmission unit */
        uint8_t  type;                   /* ethernet, tokenring, etc. */
        uint8_t  dummy;                  /* place holder */
};

/* ioctl's for get/set debug */
#define TUNSETIFF       _IOW('t', 202, int)
#define TUNSDEBUG       _IOW('t', 90, int)
#define TUNGDEBUG       _IOR('t', 89, int)
#define TUNSIFINFO      _IOW('t', 91, struct tuninfo)
#define TUNGIFINFO      _IOR('t', 92, struct tuninfo)
#define TUNSLMODE       _IOW('t', 93, int)
#define TUNSIFMODE      _IOW('t', 94, int)
#define TUNSIFPID       _IO('t', 95)
#define TUNSIFHEAD      _IOW('t', 96, int)
#define TUNGIFHEAD      _IOR('t', 97, int)

#define IFF_TUN 0x0001
#define IFF_NO_PI 0x1000

#endif /* !_NET_IF_TUN_H_ */ 
