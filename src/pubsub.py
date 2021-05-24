#!/usr/bin/env python

import rospy
from std_msgs.msg import Int64


def sub_cb(msg):
    rospy.loginfo("[PubSub] Received data : %d"%msg.data)
    rospy.sleep(0.1)

def main_():
    rospy.init_node('PubSub', anonymous=False)
    pub = rospy.Publisher('test_msg', Int64, queue_size=1)
    sub = rospy.Subscriber('test_msg', Int64, sub_cb)
    rospy.logwarn("[PubSub] START! ")

    msg = Int64(); count = 0
    r = rospy.Rate(100)
    rospy.sleep(1)

    while not rospy.is_shutdown():
        msg.data = count; count += 1
        pub.publish(msg)
        rospy.loginfo('[PubSub] Send data : %d'%msg.data)
        r.sleep()
    
if __name__ == '__main__':
    try:
        main_()
    except rospy.ROSInterruptException:
        pass
