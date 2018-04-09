#ifndef __MOTOR__HPP__
#define __MOTOR__HPP__

#include <Stepper.h>

class Motor {
  public:
    Motor(int steps_per_rev, int step, int dir);

    float get_speed();
    void set_speed(float speed);
    void run();

  private:
    float current_w;
    float target_w;
    Stepper step_mt;

};

#endif
