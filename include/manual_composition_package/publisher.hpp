#ifndef MANUAL_COMPOSITION_PACKAGE__MINIMALPUBLISHER_COMPONENT_HPP_
#define MANUAL_COMPOSITION_PACKAGE__MINIMALPUBLISHER_COMPONENT_HPP_

#include "manual_composition_package/visibility_control.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace manual_composition_package
{

class MinimalPublisher : public rclcpp::Node
{
public:
  MANUAL_COMPOSITION_PACKAGE_PUBLIC
  explicit MinimalPublisher(const rclcpp::NodeOptions & options);
  
private:
  void timer_callback();
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  size_t count_;
};

}  // namespace MANUAL_COMPOSITION_PACKAGE
#endif
