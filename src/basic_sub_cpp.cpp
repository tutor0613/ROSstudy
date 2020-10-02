#include "ros/ros.h"
#include "std_msgs/Int32.h"

void basicCallback(const std_msgs::Int32::ConstPtr& msg) {
    ROS_INFO("[BasicSubscriber] Receive data : %d", msg->data);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "basic_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber basic_sub = nh.subscribe("test_msg", 1, basicCallback);
    ros::spin();

    return 0;
}