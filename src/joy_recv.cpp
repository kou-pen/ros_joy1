#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <vector>

using std::placeholders::_1;


class joy_sub: public rclcpp::Node{
	rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub;
	void sub_callback(const sensor_msgs::msg::Joy joy_){
		std::vector<int> vec{0,0,0,0,0,0,0};

		vec[0] = joy_.axes[0] * 128 ;
		vec[1] = joy_.axes[1] * 128 ;
		vec[2] = joy_.axes[2] * 128 - 128;
		vec[3] = joy_.axes[3] * 128 ;
		vec[4] = joy_.axes[4] * 128 ;
		vec[5] = joy_.axes[5] * 128 - 128;
		vec[6] = joy_.axes[6] ;
		vec[7] = joy_.axes[7] ;

		RCLCPP_INFO(this->get_logger(), "axis: %d, %d, %d, %d, %d, %d, %d, %d", vec[0], vec[1], vec[3], vec[4], vec[2], vec[5], vec[6], vec[7]);
		RCLCPP_INFO(this->get_logger(), "A:%d,B:%d,X:%d,Y:%d,LB:%d,RB:%d,BACK:%d,START:%d,LOGI:%d,LPUSH:%d,RPUSH%d" ,joy_.buttons[0], joy_.buttons[1], joy_.buttons[2], joy_.buttons[3], joy_.buttons[4], joy_.buttons[5], joy_.buttons[6], joy_.buttons[7], joy_.buttons[8], joy_.buttons[9], joy_.buttons[10]);
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
