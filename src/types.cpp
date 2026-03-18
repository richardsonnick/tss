#include "types.hpp"
#include <net/ethernet.h>
#include <sys/socket.h>
#include <expected>
#include <stdexcept>
#include <system_error>
#include <print>

namespace tss {

connection_sock::~connection_sock() {
  // Prevent double close
  if (this->fd == -1)
    return;

  close(fd);
  this->fd = -1;
  return;
}

connection_sock::connection_sock(connection_sock&& other) {
  this->fd = other.fd;
  other.fd = -1;
}

connection_sock& connection_sock::operator=(connection_sock&& other){
  if (this == &other) return *this;
  // Since move assignment op, the existing connection_sock being move into could
  // be valid. :[
  if (this->fd != -1) {
    close(this->fd);
  }
  this->fd = other.fd;
  other.fd = -1;
  return *this;
}

int connection_sock::get_fd() {
  return this->fd;
}

// TODO change addr name
std::expected<connection_sock, std::error_code> connection_sock::create() {
  int sock_fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_IP));
  if (sock_fd == -1) {
    return std::unexpected(std::error_code(errno, std::system_category()));
  }
  return connection_sock{sock_fd};
}

//connection_sock connection_sock::from_fd(int fd) {
//  return std::unexpected(std::make_error_code(std::errc::owner_dead));
//}

std::expected<size_t, std::error_code> connection_sock::recv(std::span<char> buff) {
  return 0;
}

std::expected<size_t, std::error_code> connection_sock::send(std::span<const char> buff) {
  return 0;
}

std::expected<listen_sock, std::error_code> listen_sock::create(uint16_t port) {
  throw std::logic_error("unimplemented"); 
}

std::expected<std::unique_ptr<connection_sock>, std::error_code> listen_sock::accept(uint16_t port) {
  throw std::logic_error("unimplemented"); 
}

}
