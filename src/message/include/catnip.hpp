#ifndef CATNIP_UTILS_HPP
#define CATNIP_UTILS_HPP

#include <catnip.pb.h>
#include <chrono>
#include <sodium.h>
#include <vector>

/// Converts the message protobuf to a vector<unsigned char>. May
/// resize the into field.
bool
serialize_message_to_vector(catnip::PacketFragment*, std::vector<unsigned char>*);

/// Converts a vector<unsigned char> to a message protobuf.
bool
deserialize_vector_to_message(catnip::PacketFragment& into,
							  std::vector<unsigned char>& from);

/// Convert a cstr to a vector
/// \param[in] from what to convert
/// \param[out] into what to convert into
void
mutate_cstr_to_vector(unsigned char& from, std::vector<unsigned char>& into);

/// Create a test message.
catnip::PacketFragment
create_test_message();

/// Get a command uid from the time.
uint64_t
get_command_uid();

#endif /* CATNIP_UTILS_HPP */
