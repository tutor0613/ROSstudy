#!usr/bin/env python

import rospy
from std_msgs.msg import Int64

def basicCallback(msg):
    rospy.logwarn("[BasicSubscriber] Received data : %d"%msg.data)
    rospy.sleep(1)

def main_sub():
    rospy.init_node('basic_subscriber', anonymous=False)
    basic_sub = rospy.Subscriber('test_msg', Int64, basicCallback, queue_size=1)
    rospy.logwarn("[BasicSubscriber] START! ")
    rospy.spin()

if __name__ == '__main__':
    try:
        main_sub()
    except rospy.ROSInterruptException:
        pass
