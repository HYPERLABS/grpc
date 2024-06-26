//
//
// Copyright 2015 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//

#include <string.h>

#include <memory>

#include <gtest/gtest.h>

#include "absl/log/check.h"

#include <grpc/support/log.h>

#include "src/core/lib/gprpp/crash.h"
#include "test/core/test_util/test_config.h"

static bool log_func_reached = false;

static void test_callback(gpr_log_func_args* args) {
  CHECK_EQ(strcmp(__FILE__, args->file), 0);
  CHECK(args->severity == GPR_LOG_SEVERITY_INFO);
  CHECK_EQ(strcmp(args->message, "hello 1 2 3"), 0);
}

static void test_should_log(gpr_log_func_args* /*args*/) {
  log_func_reached = true;
}

static void test_should_not_log(gpr_log_func_args* /*args*/) {
  grpc_core::Crash("unreachable");
}

#define test_log_function_reached(SEVERITY)     \
  gpr_set_log_function(test_should_log);        \
  log_func_reached = false;                     \
  gpr_log_message(SEVERITY, "hello 1 2 3");     \
  CHECK(log_func_reached);                      \
  log_func_reached = false;                     \
  gpr_log(SEVERITY, "hello %d %d %d", 1, 2, 3); \
  CHECK(log_func_reached);                      \
  gpr_set_log_function(nullptr);

#define test_log_function_unreached(SEVERITY)   \
  gpr_set_log_function(test_should_not_log);    \
  gpr_log_message(SEVERITY, "hello 1 2 3");     \
  gpr_log(SEVERITY, "hello %d %d %d", 1, 2, 3); \
  gpr_set_log_function(nullptr);

TEST(LogTest, Basic) {
  // test logging at various verbosity levels
  gpr_log(GPR_DEBUG, "%s", "hello world");
  gpr_log(GPR_INFO, "%s", "hello world");
  gpr_log(GPR_ERROR, "%s", "hello world");
  // should succeed
  CHECK(1);
  gpr_set_log_function(test_callback);
  gpr_log_message(GPR_INFO, "hello 1 2 3");
  gpr_log(GPR_INFO, "hello %d %d %d", 1, 2, 3);
  gpr_set_log_function(nullptr);
}

TEST(LogTest, LogVerbosity) {
  gpr_set_log_verbosity(GPR_LOG_SEVERITY_DEBUG);
  test_log_function_reached(GPR_ERROR);
  test_log_function_reached(GPR_INFO);
  test_log_function_reached(GPR_DEBUG);

  gpr_set_log_verbosity(GPR_LOG_SEVERITY_INFO);
  test_log_function_reached(GPR_ERROR);
  test_log_function_reached(GPR_INFO);
  test_log_function_unreached(GPR_DEBUG);

  gpr_set_log_verbosity(GPR_LOG_SEVERITY_ERROR);
  test_log_function_reached(GPR_ERROR);
  test_log_function_unreached(GPR_INFO);
  test_log_function_unreached(GPR_DEBUG);
}

int main(int argc, char** argv) {
  grpc::testing::TestEnvironment env(&argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
