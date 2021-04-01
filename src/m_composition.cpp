#include <memory>

#include "manual_composition_package/client.hpp"
#include "manual_composition_package/subscriber.hpp"
#include "manual_composition_package/publisher.hpp"
#include "manual_composition_package/server.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ);
  rclcpp::init(argc, argv);
  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto talker = std::make_shared<manual_composition_package::MinimalPublisher>(options);
  exec.add_node(talker);
  auto listener = std::make_shared<manual_composition_package::MinimalSubscriber>(options);
  exec.add_node(listener);
  auto server = std::make_shared<manual_composition_package::MinimalServer>(options);
  exec.add_node(server);
  auto client = std::make_shared<manual_composition_package::MinimalClient>(options);
  exec.add_node(client);

  exec.spin();

  rclcpp::shutdown();

  return 0;
}
