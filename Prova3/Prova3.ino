
// ConstantSpeed.pde
// -*- mode: C++ -*-
//
// Shows how to run AccelStepper in the simplest,
// fixed speed mode with no accelerations
/// \author  Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2009 Mike McCauley
// $Id: ConstantSpeed.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

// The X Stepper pins
#define STEP1 2
#define DIR1 5
// The Y stepper pins
#define STEP2 3
#define DIR2 6
// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::DRIVER, STEP1, DIR1);
AccelStepper stepper2(AccelStepper::DRIVER, STEP2, DIR2);

void setup()
{
   stepper1.setMaxSpeed(10000);
   stepper1.setSpeed(4000);
   stepper2.setMaxSpeed(10000);
   stepper2.setSpeed(4000);
}

void loop()
{
   stepper1.runSpeed();
   stepper2.runSpeed();
}
