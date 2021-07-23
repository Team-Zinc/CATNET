#ifndef TUN_HPP
#define TUN_HPP

extern "C"
{
#include "alloc.h"
}

#include <errno.h>
#include <exception>
#include <fmt/core.h>
#include <string>
#include <vector>

class TunDevice
{
  public:
	int init();
	void destroy();

	bool is_ok();
	std::vector<char>* read_incomming_data();

  private:
	void* m_tun;
};

#endif /* TUNH_HPP */
