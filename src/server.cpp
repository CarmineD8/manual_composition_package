// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "manual_composition_package/server.hpp"

#include <inttypes.h>
#include <memory>
#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

using AddTwoInts = example_interfaces::srv::AddTwoInts;
using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;

namespace manual_composition_package{


  MinimalServer::MinimalServer(const rclcpp::NodeOptions & options)
  : Node("minimal_server", options)
  {
    service_ = this->create_service<AddTwoInts>(
      "add_two_ints", std::bind(&MinimalServer::handle_service, this, _1, _2, _3));
  }

  void MinimalServer::handle_service(
  const std::shared_ptr<rmw_request_id_t> request_header,
  const std::shared_ptr<AddTwoInts::Request> request,
  const std::shared_ptr<AddTwoInts::Response> response)
  {
  (void)request_header;
  RCLCPP_INFO(
    this->get_logger(),
    "request: %" PRId64 " + %" PRId64, request->a, request->b);
  response->sum = request->a + request->b;
  }
}

RCLCPP_COMPONENTS_REGISTER_NODE(manual_composition_package::MinimalServer) 

