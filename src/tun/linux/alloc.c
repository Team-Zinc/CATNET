#include "../include/alloc.h"
#include "type.h"

#include <linux/if.h>
#include <linux/if_tun.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/// Allocates a tun->device. The kernel picks the name
/// of the device.
/// https://www.kernel.org/doc/Documentation/networking/tun->ap.txt
/// I love linux documentation. Seriously. I do.
/// TODO: Support multiqueue (paralell tun->
int
tun_alloc(void* v_tun)
{
    AllocatedTun *tun = (AllocatedTun*) v_tun;
    static struct ifreq ifr;
    int fp, err;
    char dev[16] = "\0"; // Let the kernel pick a name

    if ((fp = open(TUN_CLONE_DEVICE, O_RDWR)) < 0) {
        return -1;
    }

    memset(&ifr, 0, sizeof(ifr));

    ifr.ifr_flags = IFF_TUN | IFF_NO_PI; 
    if (*dev) {
        strncpy(ifr.ifr_name, dev, IFNAMSIZ);
    }

    if ((err = ioctl(fp, TUNSETIFF, (void *) &ifr)) < 0) {
        close(fp);
        return -1;
    }

    strcpy(dev, ifr.ifr_name);

    tun->ifr = &ifr;
    tun->device = fp;

    return 0;
}

void tun_dealloc(void* v_tun) {
    AllocatedTun *tun = (AllocatedTun*) v_tun;

    close(tun->device);
    close(tun->sock);
}
