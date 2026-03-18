#include <gtest/gtest.h>
#include "types.hpp"

TEST(ConnectionSockTests, TestOpenRawSocket) {
  auto sock = tss::connection_sock::create();
  EXPECT_TRUE(sock.has_value()) << sock.error().message();
}
