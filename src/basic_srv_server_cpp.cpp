#include "ros/ros.h"
#include "study_ros/addTwoInts.h"

bool calc(study_ros::addTwoInts::Request &req, study_ros::addTwoInts::Response &res) {  // Service callback
    res.result = req.a + req.b;
    ROS_INFO("[BasicSrvServer] Request : %ld + %ld, Response : %ld", req.a, req.b, res.result);
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "basic_srv_server");
    ros::NodeHandle nh;

    ros::ServiceServer basic_srv_server = nh.advertiseService("basic_srv", calc);
    ROS_INFO("[BasicSrvServer] Service Ready. ");

    ros::spin();
    return 0;
}