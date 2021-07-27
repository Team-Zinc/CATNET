// https://backreference.org/2010/03/26/tuntun-interface-tutorial/

#include "include/tun.hpp"
extern "C"
{
#ifdef __linux__
#include "linux/type.h"
#endif /* linux */

#include "include/alloc.h"
#include "include/ip.h"
#include "include/up.h"
}

#include <errno.h>
#include <string>

#include <fmt/core.h>
#include <log.hpp>

int
TunDevice::init()
{
#ifdef __linux__
    AllocatedTun* tun;
	CND_DAEMON_DEBUG("Allocating tun device....");
	if (tun_alloc(&tun) != 0) {
		CND_DAEMON_CRITICAL(
		  fmt::format("Failed to allocate tun device: {}", strerror(errno)));

		return -1;
	}

	CND_DAEMON_DEBUG("Bringing tun device up....");
	if (bring_tun_up(&tun) != 0) {
		CND_DAEMON_CRITICAL(
		  fmt::format("Failed to bring tun device up: {}", strerror(errno)));

		return -1;
	}

	CND_DAEMON_DEBUG("Assigning tun device IPv4 ip....");
	if (assign_tun_ipv4(&tun) != 0) {
		CND_DAEMON_CRITICAL(fmt::format("Failed to assign IP to tun device: {}",
										strerror(errno)));

		return -1;
	}

    m_tun = tun;
#elif __APPLE__

#endif

	return 0;
}

void
TunDevice::destroy()
{
#ifdef __linux__
	tun_dealloc(&m_tun);
#elif __APPLE__

#endif
}

bool
TunDevice::is_ok()
{
#ifdef __linux__
	return static_cast<AllocatedTun*>(this->m_tun)->device >= 0;
#else
#error Unsupported platform!
#endif
}

std::vector<char>*
TunDevice::read_incomming_data()
{
	static std::vector<char> buf;
	buf.reserve(1800);

	usleep(1000);

#ifdef __linux__
	if (read(static_cast<AllocatedTun*>(this->m_tun)->device, buf.data(), buf.size())) {
		CND_DAEMON_ERROR(fmt::format("Failed to read from tun interface: {}",
									 strerror(errno)));

		return nullptr;
	}
#else
#error Unsupported platform!
#endif

	return &buf;
}
