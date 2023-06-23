#!/usr/bin/env python

import rospy
from std_msgs.msg import Float32MultiArray

def main_pub():
    rospy.init_node('basic_publisher', anonymous=False)
    basic_pub = rospy.Publisher('test_msg', Float32MultiArray, queue_size=1)
    msg = Float32MultiArray(); count = 0
    r = rospy.Rate(2)
    rospy.sleep(1)

    while not rospy.is_shutdown():
        a = 59.36998931884766
        b = round(a,2)
        msg.data = [a, round(a,2), b]
        basic_pub.publish(msg)
        rospy.logwarn('[BasicPublisher] Send data : %s'%msg)
        r.sleep()
    
if __name__ == '__main__':
    try:
        main_pub()
    except rospy.ROSInterruptException:
        pass
