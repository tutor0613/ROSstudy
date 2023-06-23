#!/usr/bin/env python

import rospy
from std_msgs.msg import *
from std_srvs.srv import *


def sub_cb(msg):
    rospy.logwarn("[PubSub] Received data : %d"%msg.data)
    rospy.sleep(0.1)

def srv_cb(msg):
    global count
    msg = Int64(); msg.data = count
    pub.publish(msg); count += 1
    rospy.logwarn("[PubSub] Send data : %d"%msg.data)
    return True, 'Success'

def main_():
    global count, pub
    rospy.init_node('PubSub', anonymous=False)
    pub = rospy.Publisher('test_msg', Int64, queue_size=10)
    sub = rospy.Subscriber('test_msg', Int64, sub_cb)
    srv = rospy.Service("test_srv", Trigger, srv_cb)
    count = 0
    rospy.sleep(1)
    rospy.logwarn("[PubSub] START! ")

    # while not rospy.is_shutdown():
    #     msg.data = count; count += 1
    #     pub.publish(msg)
    #     rospy.loginfo('[PubSub] Send data : %d'%msg.data)
    #     r.sleep()

    rospy.spin()
    
if __name__ == '__main__':
    try:
        main_()
    except rospy.ROSInterruptException:
        pass
