#include "ros/ros.h"
#include "study_ros/addTwoInts.h"

#define PLUS        1
#define MINUS       2
#define MULTIPLY    3
#define DEVISION    4

int g_operator = PLUS;

bool calc(study_ros::addTwoInts::Request &req, study_ros::addTwoInts::Response &res) {  // Service callback
    switch(g_operator) {
        case PLUS:
            res.result = req.a + req.b; break;
        case MINUS:
            res.result = req.a - req.b; break;
        case MULTIPLY:
            res.result = req.a * req.b; break;
        case DEVISION:
            res.result = req.a / req.b; break;
    }
    res.result = req.a + req.b;
    ROS_INFO("[BasicSrvServer] Request : %ld, %ld, Response : %ld", req.a, req.b, res.result);
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "basic_srv_server");
    ros::NodeHandle nh;

    nh.getParam("calc_method", g_operator);

    ros::ServiceServer basic_srv_server = nh.advertiseService("basic_srv", calc);
    ROS_INFO("[BasicSrvServer] Service Ready. ");
    ROS_INFO("[BasicSrvServer] Calc mode : %s", g_operator);
    // ros::Rate r(10);

    // while(ros::ok()) {
    //     nh.getParam("calc_method", g_operator);
    //     ros::spinOnce();
    //     r.sleep();
    // }

    ros::spin();
    
    return 0;
}