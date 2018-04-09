#include <ros.h>
#include <Stepper.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float32.h>

ros::NodeHandle  nh; // allows to create publisher/subscriber
geometry_msgs::Twist vel;
std_msgs::Float32 msg;

const int steps_per_rev = 200;

Motor right_mt(steps_per_rev,2,5);
Motor left_mt(steps_per_rev,3,6);

#define EN 8
#define L 0.20f // distance between the two wheels of the robot
#define R 0.05f //radius of the wheel od the robot

const float A = L/(2.0f*R);
const float B = 1.0f/R;

int cnt;

void motors_cb(const geometry_msgs::Twist &move)
{
  const float w_right = A*move.angular.z + B*move.linear.x;
  const float w_left = A*move.angular.z - B*move.linear.x;

  right_mt.set_speed(w_right);
  left_mt.set_speed(w_left);

  cnt ++;

  vel.linear.x = move.linear.x;
  vel.angular.z = move.angular.z;

  msg.data = w_right;

}

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &motors_cb);
ros::Publisher pub("/info_vel", &vel);
ros::Publisher pubtest("/test_speed", &msg);

void setup ()
{
  //need to set the enable to LOW because if it is HIGH the motors are desabled
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);

  StepperDriver.init();

  nh.initNode(); // initialize ROS nodes
  nh.advertise(pubtest);
  nh.subscribe(sub);
  nh.advertise(pub);
}

void loop()
{
  if((cnt%10) == 1)
  {
    pub.publish(&vel);
    pubtest.publish(&msg);
  }

  left_mt.run();
  right_mt.run();

  nh.spinOnce();
}
