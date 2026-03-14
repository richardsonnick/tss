#pragma once

#include <cstdint>
#include <memory>
#include <netinet/in.h>
#include <expected>
#include <span>
#include <system_error>

namespace tss {

struct ip_addr {
  in_addr addr;
  uint16_t port;
};

class connection_sock {
  private:
    int fd;
    connection_sock(int fd) : fd(fd){};

  public:
    connection_sock(const connection_sock&) = delete;
    connection_sock& operator=(const connection_sock&) = delete;
    ~connection_sock();
    connection_sock(connection_sock&& other);
    connection_sock& operator=(connection_sock&& other);

    static std::expected<connection_sock, std::error_code> create(ip_addr addr);
    static connection_sock from_fd(int fd);
    int get_fd();
    std::expected<size_t, std::error_code> recv(std::span<char> buff);
    std::expected<size_t, std::error_code> send(std::span<const char> buff);
};

class listen_sock {
  private:
    int fd;
  public:
    listen_sock() = delete;
    listen_sock(const listen_sock&) = delete;
    listen_sock& operator=(const listen_sock&) = delete;
    ~listen_sock();
    listen_sock(listen_sock&& other);
    listen_sock& operator=(listen_sock&& other);

    static std::expected<listen_sock, std::error_code> create(uint16_t port);
    std::expected<std::unique_ptr<connection_sock>, std::error_code> accept(uint16_t port);
};

}
