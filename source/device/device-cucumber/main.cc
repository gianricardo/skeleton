#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cucumber-cpp/defs.hpp>

namespace {

  using cucumber::ScenarioScope;
  using namespace ::testing;

  struct DeviceContext {
  };

  GIVEN("^succeed$") {
    SUCCEED();
  }

}
