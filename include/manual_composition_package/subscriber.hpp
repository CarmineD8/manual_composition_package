#ifndef MANUAL_COMPOSITION_PACKAGE__MINIMALSUBSCRIBER_COMPONENT_HPP_
#define MANUAL_COMPOSITION_PACKAGE__MINIMALSUBSCRIBER_COMPONENT_HPP_

#include "manual_composition_package/visibility_control.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace manual_composition_package
{

class MinimalSubscriber : public rclcpp::Node
{
public:
  MANUAL_COMPOSITION_PACKAGE_PUBLIC
  explicit MinimalSubscriber(const rclcpp::NodeOptions & options);
  
private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

}  // namespace MANUAL_COMPOSITION_PACKAGE
#endif
