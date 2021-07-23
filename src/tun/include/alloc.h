#ifndef ALLOC_H
#define ALLOC_H

#define TUN_CLONE_DEVICE "/dev/net/tun"

#ifdef linux
#include "../linux/type.h"
#endif

int tun_alloc(void* tun);
void tun_dealloc(void* tun);

#endif /* ALLOC_H */
