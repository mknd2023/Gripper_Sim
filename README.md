# gripper_sim
>**Author - Mukund S K**
>
>This project has been made as part of an attempt to simulate the end effector of a two-link arm on Rviz, as part of my work at Project Kratos, my college's Mars Rover Team.
>
>This project involves the use of an MPU6050 6-DOF IMU (Inertial Measurement Unit) and the library [MPU6050_light.h](https://github.com/rfetick/MPU6050_light.git) by rfetic. The data has been collected through the Robot Operating System and eventually published to the simulation on RViz. 
>
>The folder _bevelonarm_ contains the simulation related files while the folder _control_ contains the files related to Robot Operating System - either to be uploaded to the ESP32 connected to the IMU, or the code for publishing angle data onto the RViz simulation.