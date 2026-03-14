#include "types.hpp"

class connection_sock {
  private:
    int fd;
  public:
    connection_sock() = delete;
    connection_sock(const connection_sock&) = delete;
    connection_sock& operator=(const connection_sock&) = delete;
    ~connection_sock();
    connection_sock(connection_sock&& other);
    connection_sock& operator=(connection_sock&& other);

    static std::expected<connection_sock, std::error_code> create(ip_addr addr);
    static connection_sock from_fd(int fd);
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
    std::expected<std::unique_ptr<connection_sock>, std::error_code> accept();
};

std::expected<connection_sock, std::error_code> connection_sock::create(ip_addr addr) {
  throw std::logic_error("unimplemented"); 
  connection_sock sock{};
  return sock;
}

connection_sock connection_sock::from_fd(int fd) {
  throw std::logic_error("unimplemented"); 
  connection_sock sock{};
  return sock;
}

std::expected<size_t, std::error_code> recv(std::span<char> buff) {
  throw std::logic_error("unimplemented"); 
  return 0;
}

std::expected<size_t, std::error_code> send(std::span<const char> buff) {
  throw std::logic_error("unimplemented"); 
  return 0;
}

std::expected<listen_sock, std::error_code> create(uint16_t port) {
  throw std::logic_error("unimplemented"); 
  listen_sock sock{};
  return  sock;
}

std::expected<std::unique_ptr<connection_sock>, std::error_code> accept(uint16_t port) {
  throw std::logic_error("unimplemented"); 
  connection_sock sock{};
  return  sock;
}
