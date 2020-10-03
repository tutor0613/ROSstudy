#include "ros/ros.h"
#include "study_ros/addTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv) {
    ros::init(argc, argv, "basic_srv_client");

    if (argc != 3) {  // Wrong Input Check
        ROS_INFO("[BasicSrvClient] Wrong input. ");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient basic_srv_client = nh.serviceClient<study_ros::addTwoInts>("basic_srv");

    study_ros::addTwoInts srv;
    srv.request.a = atoll(argv[1]);  // atoll : Convert string to int
    srv.request.b = atoll(argv[2]);

    if (basic_srv_client.call(srv)) {  // Call service
        ROS_INFO("[BasicSrvClient] Request : %ld + %ld, Response : %ld", srv.request.a, srv.request.b, srv.response.result);
    }
    else {
        ROS_ERROR("[BasicSrvClient] Service call failed. ");
        return 1;
    }

    return 0;
}