#!usr/bin/env python

import rospy
from std_msgs.msg import Int64

def basicCallback(msg):
    rospy.loginfo("[BasicSubscriber] Received data : %d"%msg.data)

def main_sub():
    rospy.init_node('basic_subscriber', anonymous=False)
    basic_sub = rospy.Subscriber('test_msg', Int64, basicCallback)
    rospy.spin()

if __name__ == '__main__':
    try:
        main_sub()
    except rospy.ROSInterruptException:
        pass