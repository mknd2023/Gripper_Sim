/* Get tilt angles on X and Y, and rotation angle on Z
 * Angles are given in degrees
 * 
 * License: MIT
 */

#include "Wire.h"
#include <MPU6050_light.h>
#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Float64MultiArray.h>
ros::NodeHandle  nh;
std_msgs::Float64MultiArray imu;
ros::Publisher sens("/ang", &imu);
MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Wire.begin();
  byte status = mpu.begin();
  nh.initNode();
  nh.advertise(sens);
  imu.layout.dim=NULL;
  imu.layout.data_offset=0;
  while(status!=0){ } // stop everything if could not connect to MPU6050
  while (!nh.connected()) {
    nh.spinOnce(); 
    delay(100);
}
  delay(10);
  mpu.calcOffsets();
}

void loop() {
  mpu.update();
  float x,y;
  if((millis()-timer)>10){
	x=mpu.getAngleX()*3.14/180;
	y=mpu.getAngleY()*3.14/180;
  	float array[]={x,y};
  	imu.data=array;
  	imu.data_length=2;
  	sens.publish(&imu);
  	nh.spinOnce();  
	timer = millis();  
  }
}
