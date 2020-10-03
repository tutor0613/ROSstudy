#include "ros/ros.h"
#include "std_msgs/Int64.h"

void basicCallback(const std_msgs::Int64::ConstPtr& msg) {
    ROS_INFO("[BasicSubscriber] Receive data : %ld", msg->data);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "basic_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber basic_sub = nh.subscribe("test_msg", 1, basicCallback);
    ros::spin();   // keeps code from exiting until ROS is shutdown.

    return 0;
}