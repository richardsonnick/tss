#include "types.hpp"
#include <expected>
#include <stdexcept>
#include <system_error>
#include <print>

namespace tss {

connection_sock::~connection_sock() {
  this->fd = -1;
  return;
}

std::expected<connection_sock, std::error_code> connection_sock::create(ip_addr addr) {
  printf("Creating connection_sock\n");
  return std::unexpected(std::make_error_code(std::errc::owner_dead));
}

//connection_sock connection_sock::from_fd(int fd) {
//  return std::unexpected(std::make_error_code(std::errc::owner_dead));
//}

std::expected<size_t, std::error_code> recv(std::span<char> buff) {
  return 0;
}

std::expected<size_t, std::error_code> send(std::span<const char> buff) {
  return 0;
}

std::expected<listen_sock, std::error_code> create(uint16_t port) {
  throw std::logic_error("unimplemented"); 
}

std::expected<std::unique_ptr<connection_sock>, std::error_code> accept(uint16_t port) {
  throw std::logic_error("unimplemented"); 
}

}
