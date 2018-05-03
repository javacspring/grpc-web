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

#ifndef NET_GRPC_GATEWAY_RUNTIME_RESPONSE_H_
#define NET_GRPC_GATEWAY_RUNTIME_RESPONSE_H_

#include <algorithm>
#include <memory>

#include "net/grpc/gateway/runtime/types.h"
#include "third_party/grpc/include/grpcpp/support/status.h"

namespace grpc {
namespace gateway {

class Response {
 public:
  Response();
  virtual ~Response();
  Response(const Response&) = delete;
  Response& operator=(const Response&) = delete;

  void set_headers(std::unique_ptr<Headers> headers) {
    headers_ = std::move(headers);
  }
  Headers* headers() { return headers_.get(); }
  std::unique_ptr<Headers> release_headers() { return std::move(headers_); }

  void set_message(std::unique_ptr<Message> message) {
    message_ = std::move(message);
  }
  Message* message() { return message_.get(); }
  std::unique_ptr<Message> release_message() { return std::move(message_); }

  void set_trailers(std::unique_ptr<Trailers> trailers) {
    trailers_ = std::move(trailers);
  }
  Trailers* trailers() { return trailers_.get(); }
  std::unique_ptr<Trailers> release_trailers() { return std::move(trailers_); }

  void set_status(std::unique_ptr<Status> status) {
    status_ = std::move(status);
  }
  Status* status() { return status_.get(); }
  std::unique_ptr<Status> release_status() { return std::move(status_); }

  bool final() { return final_; }
  void set_final(bool final) { final_ = final; }

 private:
  std::unique_ptr<Headers> headers_;
  std::unique_ptr<Message> message_;
  std::unique_ptr<Trailers> trailers_;
  std::unique_ptr<Status> status_;
  bool final_;
};

}  // namespace gateway
}  // namespace grpc
#endif  // NET_GRPC_GATEWAY_RUNTIME_RESPONSE_H_
