#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "basic_publisher");
    ros::NodeHandle nh;

    ros::Publisher basic_pub = nh.advertise<std_msgs::Int64>("test_msg", 1);
    ros::Rate r(1);
    int count = 0;

    while(ros::ok()) {
        std_msgs::Int64 msg;
        msg.data = count++;
        ROS_INFO("[BasicPublisher] Send data : %ld", msg.data);
        basic_pub.publish(msg);
        r.sleep();
    }
    
    return 0;
}