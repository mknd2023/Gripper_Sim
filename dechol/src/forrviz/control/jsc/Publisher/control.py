#!/usr/bin/env python
import rospy  
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray

rospy.init_node('command_to_joint_state')
joint_pub = rospy.Publisher("joint_states", JointState, queue_size=1)

def command_callback(msg):
    ans=Float64MultiArray()
    ans=msg.data 
    joint_state = JointState()
    joint_state.name.append("base_joint")
    joint_state.name.append("rot_joint")
    joint_state.position.append(0.0)
    joint_state.position.append(0.0)
    joint_state.position[0] = -ans[0]
    joint_state.position[1]=ans[1]
    joint_state.header.stamp = rospy.Time.now()
    joint_pub.publish(joint_state)

command_sub = rospy.Subscriber("ang", Float64MultiArray, command_callback, queue_size=1)

while not rospy.is_shutdown():
  x=1
