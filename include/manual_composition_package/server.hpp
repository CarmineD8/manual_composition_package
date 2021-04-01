#ifndef MANUAL_COMPOSITION_PACKAGE__MINIMALSERVER_COMPONENT_HPP_
#define MANUAL_COMPOSITION_PACKAGE__MINIMALSERVER_COMPONENT_HPP_

#include "manual_composition_package/visibility_control.h"
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

using AddTwoInts = example_interfaces::srv::AddTwoInts;

namespace manual_composition_package
{

class MinimalServer : public rclcpp::Node
{
public:
  MANUAL_COMPOSITION_PACKAGE_PUBLIC
  explicit MinimalServer(const rclcpp::NodeOptions & options);
  
private:
  void handle_service(const std::shared_ptr<rmw_request_id_t> request_header,
  const std::shared_ptr<AddTwoInts::Request> request,
  const std::shared_ptr<AddTwoInts::Response> response);
  rclcpp::Service<AddTwoInts>::SharedPtr service_;
};

}  // namespace MANUAL_COMPOSITION_PACKAGE
#endif
