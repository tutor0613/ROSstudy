#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <study_ros/fibonacciAction.h>

class fibonacciAction {
    protected:
        ros::NodeHandle nh;
        actionlib::SimpleActionServer<study_ros::fibonacciAction> as;
        std::string action_name;
        study_ros::fibonacciFeedback feedback;
        study_ros::fibonacciResult result;
    
    public:
        fibonacciAction(std::string name): 
            as(nh, name, boost::bind(&fibonacciAction::executeCB, this, _1), false),
            action_name(name) {
            as.start();
        }

        ~fibonacciAction(void) {}

        void executeCB(const study_ros::fibonacciGoalConstPtr &goal) {
            // helper variables
            ros::Rate r(10);
            bool success = true;

            // push_back the seeds for the fibonacci sequence
            feedback.sequence.clear();
            feedback.sequence.push_back(0);
            feedback.sequence.push_back(1);

            // publish info to the console for the user
            ROS_INFO("%s : Executing, creating fibonacci sequence of order %i with seeds %i, %i", action_name.c_str(), goal->order, feedback.sequence[0], feedback.sequence[1]);

            // start executing the action
            for(int i=1; i<=goal->order; i++) {
                //check that preempt has not been requested by the client
                if (as.isPreemptRequested() || !ros::ok()) {
                    ROS_INFO("%s : Preempted", action_name.c_str());
                    // set the action state to preempted
                    as.setPreempted();
                    success = false;
                    break;
                }
                feedback.sequence.push_back(feedback.sequence[i] + feedback.sequence[i-1]);

                //publish the feedback
                as.publishFeedback(feedback);
                // this sleep is not necessary, the sequence is computed at 1Hz for demonstration purposes
                r.sleep();

                if(success) {
                    result.sequence = feedback.sequence;
                    ROS_INFO("%s : Succeeded", action_name.c_str());
                    // set the action state to succeeded
                    as.setSucceeded(result);
                }
            }
        }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "basic_act_server");

    fibonacciAction fibonacci("basic_action");
    ros::spin();

    return 0;
}