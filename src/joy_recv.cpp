#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>

using std::placeholders::_1;

class joy_sub: public rclcpp::Node{
	rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub;
	void sub_callback(const sensor_msgs::msg::Joy joy_){
		RCLCPP_INFO(this->get_logger(), "axis: %f, %f, %f, %f  button: %d", joy_.axes[0], joy_.axes[1], joy_.axes[2], joy_.axes[3], joy_.buttons[0]);
	}

public:
	joy_sub(): Node("joy_recv"){
		sub = this->create_subscription<sensor_msgs::msg::Joy>("joy", 10, std::bind(&joy_sub::sub_callback, this, _1));
	}
};

int main(int argc, char*argv[]){
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<joy_sub>());
	rclcpp::shutdown();
	return 0;
}
