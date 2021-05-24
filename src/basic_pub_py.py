#!/usr/bin/env python

import rospy
from std_msgs.msg import Int64

def main_pub():
    rospy.init_node('basic_publisher', anonymous=False)
    basic_pub = rospy.Publisher('test_msg', Int64, queue_size=1)
    msg = Int64(); count = 0
    r = rospy.Rate(1000)
    rospy.sleep(1)

    while not rospy.is_shutdown():
        msg.data = count; count += 1
        basic_pub.publish(msg)
        rospy.loginfo('[BasicPublisher] Send data : %d'%msg.data)
        r.sleep()
    
if __name__ == '__main__':
    try:
        main_pub()
    except rospy.ROSInterruptException:
        pass