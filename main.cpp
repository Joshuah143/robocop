/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       joshuahimmens                                             */
/*    Created:      Wed Oct 20 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// MotorGroup1          motor_group   1, 2            
// MotorGroup3          motor_group   3, 4            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  MotorGroup1.setStopping(brake);
  MotorGroup3.setStopping(brake);
  while (true){
    MotorGroup1.setVelocity(Controller1.Axis3.position(percent), percent);
    MotorGroup3.setVelocity(Controller1.Axis2.position(percent), percent);
    if (Controller1.ButtonX.pressing()){
      MotorGroup1.stop();
      MotorGroup3.stop();
      break;
    }
    wait(5, msec);
  }
}
