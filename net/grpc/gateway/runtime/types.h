/**
 *
 * Copyright 2018 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef NET_GRPC_GATEWAY_RUNTIME_TYPES_H_
#define NET_GRPC_GATEWAY_RUNTIME_TYPES_H_

#include <string>
#include <utility>
#include <vector>

#include "third_party/grpc/include/grpcpp/support/slice.h"
#include "third_party/grpc/include/grpcpp/support/string_ref.h"

namespace grpc {
namespace gateway {

typedef std::pair<std::string, string_ref> Header;
typedef Header Trailer;
typedef std::vector<Header> Headers;
typedef Headers Trailers;
typedef std::vector<Slice> Message;

}  // namespace gateway
}  // namespace grpc

#endif  // NET_GRPC_GATEWAY_RUNTIME_TYPES_H_
