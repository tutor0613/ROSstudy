#!/usr/bin/env python

import rospy
from study_ros.srv import addTwoInts, addTwoIntsResponse

def calc(req):
    res = req.a + req.b
    rospy.loginfo('[BasicSrvServer] Request : %s + %s, Response : %s'%(req.a, req.b, res))
    return addTwoIntsResponse(res)

def basic_srv_server():
    rospy.init_node('basic_srv_server', anonymous=False)
    srv = rospy.Service('basic_srv', addTwoInts, calc)
    rospy.loginfo('[BasicSrvServer] Service Ready. ')
    rospy.spin()

if __name__ == '__main__':
    try:
        basic_srv_server()
    except rospy.ROSInterruptException:
        pass