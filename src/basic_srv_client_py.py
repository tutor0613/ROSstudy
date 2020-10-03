#!/usr/bin/env python

import rospy, sys
from study_ros.srv import *

def basic_srv_client(x,y):
    rospy.wait_for_service('basic_srv')  # block until the service is available.
    try:
        basic_srv = rospy.ServiceProxy('basic_srv', addTwoInts)
        res = basic_srv(x,y)
        return res.result
    except rospy.ServiceException as e:
        rospy.logerr('[BasicSrvClient] Service call failed : %s'%e)

if __name__ == '__main__':
    try:
        rospy.init_node('basic_srv_client', anonymous=False)
        
        if len(sys.argv) == 3:   # Wrong input check
            x = int(sys.argv[1])
            y = int(sys.argv[2])
        else:
            rospy.logerr('[BasicSrvClient] Wrong input. ')
            sys.exit(1)

        rospy.loginfo('[BasicSrvClient] Request : %s + %s, Response : %s'%(x, y, basic_srv_client(x,y)))

    except rospy.ROSInterruptException:
        pass    