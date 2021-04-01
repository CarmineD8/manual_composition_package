// Copyright 2016 Open Source Robotics Foundation, Inc.
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

#include "manual_composition_package/client.hpp"

#include <chrono>
#include <cinttypes>
#include <memory>
#include <cstdlib>
#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

using namespace std::chrono_literals;
using AddTwoInts = example_interfaces::srv::AddTwoInts;

namespace manual_composition_package{

  MinimalClient::MinimalClient(const rclcpp::NodeOptions & options)
  : Node("minimal_client", options)
  {
    client_ = this->create_client<AddTwoInts>("add_two_ints");
    
    while (!client_->wait_for_service(std::chrono::seconds(1))){
     if (!rclcpp::ok()) {
      RCLCPP_ERROR(this->get_logger(), "client interrupted while waiting for service to appear.");
      return;
    }
    RCLCPP_INFO(this->get_logger(), "waiting for service to appear...");
  }
   timer_ = this->create_wall_timer(
      2000ms, std::bind(&MinimalClient::call_server, this));
  }
  
  void MinimalClient::call_server()
  {
  this->request_ = std::make_shared<AddTwoInts::Request>();
  this->request_->a = std::rand();
  this->request_->b = std::rand();
  
   using ServiceResponseFuture =
    rclcpp::Client<AddTwoInts>::SharedFuture;
  auto response_received_callback = [this](ServiceResponseFuture future) {
      RCLCPP_INFO(this->get_logger(), "Got result: [%" PRId64 "]", future.get()->sum);
    };
  auto future_result = client_->async_send_request(this->request_, response_received_callback);
  }
}



RCLCPP_COMPONENTS_REGISTER_NODE(manual_composition_package::MinimalClient) 

