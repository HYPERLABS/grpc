# Copyright 2018 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("//bazel:grpc_build_system.bzl", "grpc_cc_library", "grpc_cc_test", "grpc_package")

licenses(["notice"])

grpc_package(name = "test/core/tsi/alts/handshaker")

grpc_cc_library(
    name = "alts_handshaker_service_api_test_lib",
    srcs = ["alts_handshaker_service_api_test_lib.cc"],
    hdrs = ["alts_handshaker_service_api_test_lib.h"],
    external_deps = ["absl/log:log"],
    deps = [
        "//:grpc",
    ],
)

grpc_cc_test(
    name = "alts_handshaker_client_test",
    srcs = ["alts_handshaker_client_test.cc"],
    external_deps = ["gtest"],
    deps = [
        ":alts_handshaker_service_api_test_lib",
        "//:grpc",
        "//src/core:env",
        "//test/core/test_util:grpc_test_util",
    ],
)

grpc_cc_test(
    name = "alts_tsi_handshaker_test",
    srcs = ["alts_tsi_handshaker_test.cc"],
    external_deps = ["gtest"],
    deps = [
        ":alts_handshaker_service_api_test_lib",
        "//:gpr",
        "//:grpc",
        "//test/core/test_util:grpc_test_util",
    ],
)

grpc_cc_test(
    name = "alts_tsi_utils_test",
    srcs = ["alts_tsi_utils_test.cc"],
    external_deps = ["gtest"],
    deps = [
        ":alts_handshaker_service_api_test_lib",
        "//:grpc",
        "//test/core/test_util:grpc_test_util",
    ],
)

grpc_cc_test(
    name = "transport_security_common_api_test",
    srcs = ["transport_security_common_api_test.cc"],
    external_deps = ["gtest"],
    deps = [
        "//:grpc",
        "//test/core/test_util:grpc_test_util",
    ],
)

grpc_cc_test(
    name = "alts_concurrent_connectivity_test",
    srcs = [
        "alts_concurrent_connectivity_test.cc",
    ],
    external_deps = [
        "absl/log:check",
        "absl/log:log",
        "gtest",
    ],
    flaky = True,
    # TODO(apolcyn): make the fake TCP server used in this
    # test portable to Windows.
    tags = [
        "no_mac",  # TODO(https://github.com/grpc/grpc/issues/24747): Disable temporarily
        "no_windows",
    ],
    deps = [
        "//:grpc",
        "//src/core:slice",
        "//test/core/end2end:cq_verifier",
        "//test/core/test_util:fake_udp_and_tcp_server",
        "//test/core/test_util:grpc_test_util",
        "//test/core/tsi/alts/fake_handshaker:fake_handshaker_lib",
    ],
)
