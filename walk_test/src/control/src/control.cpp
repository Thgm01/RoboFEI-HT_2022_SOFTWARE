// Open terminal #2 
// $ ros2 run control control
// $ ros2 run um7 um7_node
// $ ros2 launch control action.launch.py


// ros2 topic pub -1 /decision dynamixel_sdk_custom_interfaces/Decision "{decision: 1}"

#include <chrono>
#include <memory>
#include <thread>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <libgen.h> //dirname

#include "MotionManager.h"
#include "Walking.h"
#include "rclcpp/rclcpp.hpp"
#include "dynamixel_sdk_custom_interfaces/msg/set_position.hpp"
#include "dynamixel_sdk_custom_interfaces/msg/decision.hpp"
#include "dynamixel_sdk_custom_interfaces/msg/walk.hpp"
#include "dynamixel_sdk_custom_interfaces/msg/param_walk.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "GaitMove.hpp"
#include "dynamixel_sdk_custom_interfaces/msg/set_position_original.hpp"

// #define INI_FILE_PATH       "../../Action/src/control_framework/config.ini"
#define INI_FILE_PATH       "../../Control/Data/config.ini"

using namespace std::chrono_literals;
using std::placeholders::_1;
int movement = 0;
int contador = 0;
bool stop_gait = true;
bool fallen = false;
bool fallenFront = false;
double X_amplitude = 4;
double Y_amplitude = 4;
double A_amplitude = 4;
bool same_moviment = false;

using namespace Robot;

class Control : public rclcpp::Node
{
public:
  Control()
  : Node("control")
  {
    RCLCPP_INFO(this->get_logger(), "Running action node");
    subscription_ = this->create_subscription<dynamixel_sdk_custom_interfaces::msg::Decision>(
      "/decision", 10, std::bind(&Control::topic_callback, this, _1));
    subscription_imu = this->create_subscription<sensor_msgs::msg::Imu>(
    "imu/data", 10, std::bind(&Control::topic_callback_imu, this, _1));
    publisher_ = this->create_publisher<dynamixel_sdk_custom_interfaces::msg::SetPosition>("set_position", 10); 
    publisher_single = this->create_publisher<dynamixel_sdk_custom_interfaces::msg::SetPositionOriginal>("set_position_single", 10);
    publisher_walk = this->create_publisher<dynamixel_sdk_custom_interfaces::msg::Walk>("walking", 10); 
    publisher_param = this->create_publisher<dynamixel_sdk_custom_interfaces::msg::ParamWalk>("param_walk", 10); 
    timer_ = this->create_wall_timer(4ms, std::bind(&Control::Process, this));
  }

  private:
    void topic_callback_imu(const std::shared_ptr<sensor_msgs::msg::Imu> imu_msg_) const
    {
      float IMU_ACCEL_Z = imu_msg_->linear_acceleration.z/10;
      RCLCPP_INFO(this->get_logger(),"ACEL Z %f\n", IMU_ACCEL_Z);
      if(IMU_ACCEL_Z > 0.7 || IMU_ACCEL_Z < -0.7)
        contador++;
      else
        contador = 0;
      RCLCPP_INFO(this->get_logger(),"Contador %d \n", contador);
      
      if(contador>=3)
      {
        RCLCPP_INFO(this->get_logger(),"Caido");
        fallen = true; // Robô caido
      }
      if (fallen == true){ // Robô esta caido
        if(IMU_ACCEL_Z > 0){  // Robô caido de frente
          fallenFront = true;
        }
        else{  // Robô caido de costas
          fallenFront = false;
        }
      }
    }

    void Process(){
      auto message_walk = dynamixel_sdk_custom_interfaces::msg::Walk();  
      auto message = dynamixel_sdk_custom_interfaces::msg::SetPosition();  
      auto message_param = dynamixel_sdk_custom_interfaces::msg::ParamWalk();  
      auto message_single = dynamixel_sdk_custom_interfaces::msg::SetPositionOriginal();  
      if(fallen == true){ // Robô caido, tem que levantar antes de qualquer movimento
        if (fallenFront == true){ // Caido de frente      
          RCLCPP_INFO(this->get_logger(), "Stand Up Back");                     
          message_single.id = 254;
          message_single.address = 112;
          message_single.position = 80;
          publisher_single->publish(message_single);

          //RETO
          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {2048,2048,2048,2048,2048,2048,2048,2103,2048,2060,2048,2048,2048,2048,2048,2048,2048,2048,2048};   
          publisher_->publish(message);
          usleep(1000000);


          //SE JOGA PRA FRENTE
          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {2450,2450,2316,1802,2048,2048,2048,2103,2048,2060,2048,2048,2048,2048,2048,2048,2048,2048,2048};   
          publisher_->publish(message);
          usleep(1000000);

          //next
          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {3871,244,2994,1047,2048,2048,2048,2103,2048,2060,2048,2048,2048,2048,2048,2048,2048,2048,2048};   
          publisher_->publish(message);
          usleep(1000000);


          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {3871,244,2037,2048,2048,2048,2048,2103,2048,2060,2048,2048,2048,2048,2048,2048,2048,2048,2048};   
          publisher_->publish(message);
          usleep(2000000);

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {2047,2047,2048,2048,417,3679,2048,2067,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047};   
          publisher_->publish(message);
          usleep(3000000);

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {2152,1942,2096,2000,766,3328,2048,2067,2047,2047,837,3259,3028,1066,2919,1175,2047,2047,2047};   
          publisher_->publish(message);
          usleep(1500000);

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          message.position = {2755,1339,2096,2000,2048,2048,2048,2067,2047,2047,837,3259,3275,819,2657,1494,2047,2047,2047};   
          publisher_->publish(message);
          usleep(1500000);

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          message.position = {2048,2048,2148,1948,1024,3072,2048,2067,2047,2047,841,3259,3644,452,2657,1494,2047,2047,2047};   
          publisher_->publish(message);
          usleep(1500000);

          message_single.id = 254;
          message_single.address = 112;
          message_single.position = 30;
          publisher_single->publish(message_single);

          message_single.id = 13;
          message_single.address = 112;
          message_single.position = 60;
          publisher_single->publish(message_single);

          message_single.id = 14;
          message_single.address = 112;
          message_single.position = 60;
          publisher_single->publish(message_single);

          // 15 = 2048 + 800 // 16 = 2048 - 800 //
          // 11 = 2048 - 800 // 12 = 2048 + 800 //
          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          message.position = {2048,2048,2148,1948,1024,3072,2048,2067,2047,2047,1248,2848,3644,452,2848,1248,2047,2047,2047};   
          publisher_->publish(message);
          usleep(1600000);

          // 11 += 224 // 12 -= 224
          // 15 -= 224 // 16 += 224
          // 13 -= 448 // 14 += 448
          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //  //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          //  message.position = {2048,2048,2148,1948,1024,3072,1917,2067,2047,2047,1472,2624,3196,900,2624,1472,2047,2047,2047};   
          // publisher_->publish(message);
          // std::this_thread::sleep_for(std::chrono::seconds(2)); // Seg_1

          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //  //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          //  message.position = {2048,2048,2148,1948,1024,3072,1917,2067,2047,2047,1696,2400,2748,1348,2400,1696,2047,2047,2047};   
          // publisher_->publish(message);
          // std::this_thread::sleep_for(std::chrono::seconds(1)); // Seg_2

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          message.position = {2048,2048,2148,1948,1024,3072,2048,2067,2047,2047,1920,2176,2300,1748,2176,1920,2047,2047,2047};   
          publisher_->publish(message);
          usleep(20000000);

          message_single.id = 254;
          message_single.address = 112;
          message_single.position = 60;
          publisher_single->publish(message_single);
          fallen = false;
        }
        else{ // Robô caido de costas
          RCLCPP_INFO(this->get_logger(), "Stand Up Back");
          message_single.id = 254;
          message_single.address = 112;
          message_single.position = 40;
          publisher_single->publish(message_single);


          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {2850,2850,2734,1362,2048,2048,2048,2103,2048,2060,2048,2048,2048,2048,2048,2048,2048,2048,2048};   
          publisher_->publish(message);
          usleep(3000000);

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {2048,2048,2096,2000,2048,2048,2048,2103,2048,2060,2048,2048,2048,2048,2048,2048,2048,2048,2048};   
          publisher_->publish(message);
          usleep(3000000);

          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          // //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          // message.position = {2048,2048,2096,2000,2048,2048,2048,2048,2048,2060,1348,2748,3500,596,1748,2348,2048,2048,2048};   
          // publisher_->publish(message);
          // usleep(3000000);

          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          // //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          // message.position = {2048,2048,2096,2000,1024,3072,2048,2048,2048,2060,1227,2869,3621,475,2596,1500,2048,2048,2048};   
          // publisher_->publish(message);
          // usleep(3000000);

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1    2    3    4   5   6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {944,3203,2096,2000,804,3292,2048,2048,2048,2060,1315,2781,3665,442,2000,2096,2048,2048,2048};   
          publisher_->publish(message);
          usleep(3000000);


          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {882,3214,2096,2000,1178,2918,2048,2048,2048,2060,952,3144,3665,442,1978,2118,2048,2048,2048};   
          publisher_->publish(message);
          usleep(3000000);

          message_single.id = 254;
          message_single.address = 112;
          message_single.position = 70;
          publisher_single->publish(message_single);

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {1769,2294,2096,2000,2048,2048,2048,2103,2048,2060,1146,2950,3621,475,2596,1500,2048,2048,2048};   
          publisher_->publish(message);
          usleep(3000000);

          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          // //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          // message.position = {2011,2122,2096,2000,2048,2048,2048,2103,2048,2060,853,3243,3621,475,2211,1885,2048,2048,2048};   
          // publisher_->publish(message);
          // usleep(3000000);

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          message.position = {2121,1975,2096,2000,2048,2048,2048,2103,2048,2060,589,3507,3621,475,2296,1800,2048,2048,2048};   
          publisher_->publish(message);
          usleep(4000000);

          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          // //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          // message.position = {2011,2122,2096,2000,2048,2048,2048,2048,2048,2060,636,3474,3665,442,2145,1951,2048,2048,2048};   
          // publisher_->publish(message);
          // usleep(2000000);

          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          // //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          // message.position = {1952,2192,2096,2000,2048,2048,2048,2048,2048,2060,1029,3067,3665,442,2442,1654,2048,2048,2048};   
          // publisher_->publish(message);
          // usleep(4000000);


          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          // //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
          // message.position = {2121,1975,2096,2000,2048,2048,2048,2048,2048,2060,1070,3020,3621,475,2714,1382,2048,2048,2048};   
          // publisher_->publish(message);
          // usleep(3000000);


          message_single.id = 254;
          message_single.address = 112;
          message_single.position = 30;
          publisher_single->publish(message_single);

          message_single.id = 13;
          message_single.address = 112;
          message_single.position = 60;
          publisher_single->publish(message_single);

          message_single.id = 14;
          message_single.address = 112;
          message_single.position = 60;
          publisher_single->publish(message_single);



          // 15 = 2048 + 800 // 16 = 2048 - 800 //
          // 11 = 2048 - 800 // 12 = 2048 + 800 //
          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          message.position = {2048,2048,2148,1948,1024,3072,2048,2048,2047,2047,1248,2848,3644,452,2848,1248,2047,2047,2047};   
          publisher_->publish(message);
          usleep(1600000);


          // 11 += 224 // 12 -= 224
          // 15 -= 224 // 16 += 224
          // 13 -= 448 // 14 += 448
          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //  //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          //  message.position = {2048,2048,2148,1948,1024,3072,1917,2067,2047,2047,1472,2624,3196,900,2624,1472,2047,2047,2047};   
          // publisher_->publish(message);
          // std::this_thread::sleep_for(std::chrono::seconds(2)); // Seg_1

          // message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //  //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          //  message.position = {2048,2048,2148,1948,1024,3072,1917,2067,2047,2047,1696,2400,2748,1348,2400,1696,2047,2047,2047};   
          // publisher_->publish(message);
          // std::this_thread::sleep_for(std::chrono::seconds(1)); // Seg_2

          message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
          //                    1   2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
          message.position = {2048,2048,2148,1948,1024,3072,2048,2048,2047,2047,1920,2176,2300,1748,2176,1920,2047,2047,2047};   
          publisher_->publish(message);
          usleep(20000000);

          message_single.id = 254;
          message_single.address = 112;
          message_single.position = 60;
          publisher_single->publish(message_single);
    
          fallen = false;
        }
      }
      else{
        switch (movement){
          case 1:
            message_walk.walk = 0; 
            publisher_walk->publish(message_walk);
            RCLCPP_INFO(this->get_logger(), "Parado");                            
            message.id = {1, 2, 3};          
            message.position = {1024, 1024, 2593};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 2:
            message_walk.walk = 0; 
            publisher_walk->publish(message_walk);
            RCLCPP_INFO(this->get_logger(), "Greeting");                            
            message.id = {4, 5, 6};          
            message.position = {2024, 2048, 2093};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 3: // Right kick
            message_walk.walk = 0; 
            publisher_walk->publish(message_walk);
            RCLCPP_INFO(this->get_logger(), "Right kick");                            
            message_single.id = 254;
            message_single.address = 112;
            message_single.position = 60;
            publisher_single->publish(message_single);

            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19 
            message.position = {1701,2351,2219,1877,626,3470,2047,2111,2005,2095,1664,2329,2677,1420,2360,1635,2021,2082,2047};
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(2)); //1

            // 3 = 2048 + 70 // 4 = 248 - 70
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19 
            message.position = {2047,2047,2118,1978,2048,2048,2047,2047,1930,2054,1770,2350,2440,1696,2292,1900,2048,1980,2047};
      
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(3)); //1

            // Dobrar joelhos
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
            message.position = {2047,2047,2137,1446,496,2854,2047,2047,1930,2054,1746,2368,2622,1696,2298,1900,1954,1928,2047};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1)); //1


            // Equilibrar em uma perna
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
            message.position = {2047,2047,2137,1446,496,2854,2047,2047,1930,2054,1343,2368,3239,1696,2543,1900,2048,1930,2047};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1)); //1
            

                // Perna pra trás
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
            message.position = {2047,2047,2137,1446,496,2854,2047,2047,1850,2054,2356,2368,3239,1696,2296,1900,2048,1930,2047};   
            publisher_->publish(message);

            message_single.id = 11;
            message_single.address = 112;
            message_single.position = 4000;
            publisher_single->publish(message_single);

            message_single.id = 13;
            message_single.address = 112;
            message_single.position = 2000;
            publisher_single->publish(message_single);

            message_single.id = 15;
            message_single.address = 112;
            message_single.position = 2000;
            publisher_single->publish(message_single);

            std::this_thread::sleep_for(std::chrono::seconds(1)); //1
                // Quase chute
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
            message.position = {2047,2047,2137,1446,496,2854,2047,2047,1850,2054,1350,2368,2996,1696,2048,1900,2048,1950,2047};   
            publisher_->publish(message);
            usleep(200000);

                // Chute
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
            message.position = {2047,2047,2137,1446,496,2854,2047,2047,1850,2054,1200,2368,2050,1696,2048,1900,2048,1950,2047};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(2)); //1

            message_single.id = 254;
            message_single.address = 112;
            message_single.position = 128;
            publisher_single->publish(message_single);
            break;
          case 4: // Left kick
            message_walk.walk = 0; 
            publisher_walk->publish(message_walk);
            RCLCPP_INFO(this->get_logger(), "Left kick");                            
            message_single.id = 254;
            message_single.address = 112;
            message_single.position = 40;
            publisher_single->publish(message_single);


            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19 
            message.position = {1701,2351,2219,1877,626,3470,2048,2048,2005,2095,1668,2384,2677,1420,2360,1701,2021,2082,2047};
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(2)); //1


            message_single.id = 254;
            message_single.address = 112;
            message_single.position = 20;
            publisher_single->publish(message_single);

            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19 
            message.position = {1701,2351,2219,1877,626,3470,2048,2048,2159,2333,1558,2538,2677,1299,2360,1723,2131,2192,2047};
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(2)); //1


            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19 
            message.position = {2020,2351,3066,1877,956,3470,2048,2048,2104,2333,1540,2681,2677,991,2360,1723,2175,2203,2047};
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(2)); //1


            //NEXT
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19 
            message.position = {2020,2351,3066,1877,956,3470,2048,2048,2104,2256,1540,2197,2677,672,2360,1723,2175,2048,2047};
            publisher_->publish(message);

            message_single.id = 12;
            message_single.address = 112;
            message_single.position = 2000;
            publisher_single->publish(message_single);

            message_single.id = 14;
            message_single.address = 112;
            message_single.position = 1000;
            publisher_single->publish(message_single);
            std::this_thread::sleep_for(std::chrono::seconds(2)); //1


            //chute

            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19 
            message.position = {2020,2351,3066,1877,956,3470,2048,2048,2104,2256,1540,3000,2677,1860,2360,2196,2175,2048,2047};
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(20)); //1





            // Dobrar joelhos
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3*   4*  5*   6*   7*   8*   9*   10*  11*  12*  13*  14*  15*  16*  17*  18*  19*
            message.position = {2047,2047,2782,1960,1242,3600,2047,2131,2110,2166,1728,2350,2400,1474,2196,1798,2168,2142,2047};
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(5)); //1


            // Equilibrar em uma perna
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                   1   2     3*   4*  5*   6*   7*   8*   9*   10*  11*  12*  13*  14*  15*  16*  17*  18*  19*
            message.position = {2047,2047,2782,1960,1242,3600,2047,2131,2042,2166,1728,2753,2400,857,2196,1553,2166,2048,2047};
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(100)); //1
            


            // Perna pra trás
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
            message.position = {2047,2047,2782,1446,496,2854,1965,2047,1930,2054,1728,2753,3239,1696,2296,1900,2048,1930,2047};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1)); //1

            message_single.id = 11;
            message_single.address = 112;
            message_single.position = 4000;
            publisher_single->publish(message_single);

            message_single.id = 13;
            message_single.address = 112;
            message_single.position = 4000;
            publisher_single->publish(message_single);

            message_single.id = 15;
            message_single.address = 112;
            message_single.position = 4000;
            publisher_single->publish(message_single);
            std::this_thread::sleep_for(std::chrono::seconds(1)); //1

                // Quase chute
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
            message.position = {2047,2047,2137,1446,496,2854,1965,2047,1930,2054,1350,2368,2996,1696,2048,1900,2048,1950,2047};   
            publisher_->publish(message);
            usleep(350000);

                // Chute
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
            message.position = {2047,2047,2137,1446,496,2854,1965,2047,1930,2054,1200,2368,2050,1696,2048,1900,2048,1950,2047};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(2)); //1

            message_single.id = 254;
            message_single.address = 112;
            message_single.position = 128;
            publisher_single->publish(message_single);
            break;
          case 5:
            RCLCPP_INFO(this->get_logger(), "Turn Right");                           
            message_walk.walk = 1; 
            publisher_walk->publish(message_walk);                             
            message.id = {4, 5, 6};          
            message.position = {2024, 2048, 2093};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 6:
            RCLCPP_INFO(this->get_logger(), "Turn Left");                            
            message_walk.walk = 1; 
            publisher_walk->publish(message_walk);                            
            message.id = {4, 5, 6};          
            message.position = {2024, 2048, 2093};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 7: // Goodbye
            RCLCPP_INFO(this->get_logger(), "Goodbye"); 
            message_walk.walk = 0; 
            publisher_walk->publish(message_walk);                           
            for (int i=1; i<=4; i++){
              message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
              //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
              message.position = {2047,1024,2048,1024,2048,2593,2047,2047,2047,2047,2000,2094,2400,1696,2292,1800,2047,2048,2048};   
              publisher_->publish(message);
              std::this_thread::sleep_for(std::chrono::seconds(1));
              message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
              //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19 
              message.position = {2047,1024,2048,1024,2048,3553,2047,2047,2047,2047,2000,2094,2400,1696,2292,1800,2047,2048,2048};   
              publisher_->publish(message);
              std::this_thread::sleep_for(std::chrono::seconds(1));
              // RCLCPP_INFO(this->get_logger(), "%d", i);
              if (i%4==0){
              message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
              //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
              message.position = {2047,2047,2048,2048,2048,2200,2047,2047,2047,2047,2000,2094,2400,1696,2292,1800,2047,2048,2048};   
              publisher_->publish(message);
              std::this_thread::sleep_for(std::chrono::seconds(10));
              }
            }
            break;
          case 8:
            RCLCPP_INFO(this->get_logger(), "Moving head"); 
            message_walk.walk = 0; 
            publisher_walk->publish(message_walk);                            
            message.id = {4, 5, 6};          
            message.position = {2024, 2048, 2093};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 9:
            message_walk.walk = 1; 
            publisher_walk->publish(message_walk);
            RCLCPP_INFO(this->get_logger(), "Turn around ball clockwise");                           
            message.id = {4, 5, 6};          
            message.position = {2024, 2048, 2093};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 10:
            message_walk.walk = 1; 
            publisher_walk->publish(message_walk);
            RCLCPP_INFO(this->get_logger(), "Turn around ball anticlockwise");                            
            message.id = {4, 5, 6};          
            message.position = {2024, 2048, 2093};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 11:
            message_walk.walk = 0; 
            publisher_walk->publish(message_walk);
            RCLCPP_INFO(this->get_logger(), "Fall left");                             
            message.id = {4, 5, 6};          
            message.position = {2024, 2048, 2093};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 12:
            message_walk.walk = 0; 
            publisher_walk->publish(message_walk);
            RCLCPP_INFO(this->get_logger(), "Fall right");                            
            message.id = {4, 5, 6};          
            message.position = {2024, 2048, 2093};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 13:
            message_walk.walk = 0; 
            publisher_walk->publish(message_walk);
            RCLCPP_INFO(this->get_logger(), "Agachando");                            
            message.id = {4, 5, 6};          
            message.position = {2024, 2048, 2093};   
            publisher_->publish(message);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          case 14: // Walking
            RCLCPP_INFO(this->get_logger(), "Walking"); 
            message_param.walk = 20;   
            message_param.sidle = 0;  
            message_param.turn = 2.5;  
            publisher_param->publish(message_param);
            message_walk.walk = 1; 
            publisher_walk->publish(message_walk);
            break;
          case 15:
            RCLCPP_INFO(this->get_logger(), "Gait"); 
            message_param.walk = 20;   
            message_param.sidle = 0;  
            message_param.turn = 2.5;  
            publisher_param->publish(message_param);
            message_walk.walk = 1; 
            publisher_walk->publish(message_walk);
            break;
        }
      }
    }

    void topic_callback(const std::shared_ptr<dynamixel_sdk_custom_interfaces::msg::Decision> msg) const
    {
      
      auto message_dec = dynamixel_sdk_custom_interfaces::msg::Decision();
      message_dec.decision = msg->decision;
      movement = (int)message_dec.decision;
      RCLCPP_INFO(this->get_logger(), "I heard %d", movement);
      
    } 

    rclcpp::Subscription<dynamixel_sdk_custom_interfaces::msg::Decision>::SharedPtr subscription_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription_imu;
    rclcpp::Publisher<dynamixel_sdk_custom_interfaces::msg::SetPosition>::SharedPtr publisher_; 
    rclcpp::Publisher<dynamixel_sdk_custom_interfaces::msg::SetPositionOriginal>::SharedPtr publisher_single; 
    rclcpp::Publisher<dynamixel_sdk_custom_interfaces::msg::Walk>::SharedPtr publisher_walk;   
    rclcpp::Publisher<dynamixel_sdk_custom_interfaces::msg::ParamWalk>::SharedPtr publisher_param;   
    rclcpp::TimerBase::SharedPtr timer_;
};

void change_current_dir()
{
    char exepath[1024] = {0};
    if(readlink("/proc/self/exe", exepath, sizeof(exepath)) != -1)
        chdir(dirname(exepath));
}

int main(int argc, char * argv[])
{
  change_current_dir();

  
  //Configurando para prioridade maxima para executar este processo-------
  char string1[50]; //String
  sprintf(string1,"echo robofei 123456| sudo -S renice -20 -p %d", getpid());
  system(string1);//prioridade
  //GaitMove gaitMove(ini);
  rclcpp::init(argc, argv);
  // if(MotionManager::GetInstance()->Initialize() == false)
  //   {
  //     printf("Fail to initialize Motion Manager!\n");
  //     return 0;
  // }
  rclcpp::spin(std::make_shared<Control>());
  rclcpp::shutdown();
  return 0;
}