#ifndef MANUAL_COMPOSITION_PACKAGE__MINIMALCLIENT_COMPONENT_HPP_
#define MANUAL_COMPOSITION_PACKAGE__MINIMALCLIENT_COMPONENT_HPP_

#include "manual_composition_package/visibility_control.h"
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

using AddTwoInts = example_interfaces::srv::AddTwoInts;

namespace manual_composition_package
{

class MinimalClient : public rclcpp::Node
{
public:
  MANUAL_COMPOSITION_PACKAGE_PUBLIC
  explicit MinimalClient(const rclcpp::NodeOptions & options);
  
private:
  void call_server();
  rclcpp::Client<AddTwoInts>::SharedPtr client_; 
  rclcpp::TimerBase::SharedPtr timer_;
  std::shared_ptr<AddTwoInts::Request> request_;
};

}  // namespace MANUAL_COMPOSITION_PACKAGE
#endif
