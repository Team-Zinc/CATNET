#ifndef TYPE_H
#define TYPE_H

/// Basically a wrapper around a device and
/// the kernel chosen name for a TUN device.
typedef struct {
    int device, sock;
    struct ifreq* ifr;
} AllocatedTun;

#endif /* TYPE_H */
