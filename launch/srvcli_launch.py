import launch
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    """Generate launch description with multiple components."""
    container = ComposableNodeContainer(
            name='my_container',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='manual_composition_package',
                    plugin='manual_composition_package::MinimalServer',
                    name='server'),
                ComposableNode(
                    package='manual_composition_package',
                    plugin='manual_composition_package::MinimalClient',
                    name='client')
            ],
            output='screen',
    )

    return launch.LaunchDescription([container])

