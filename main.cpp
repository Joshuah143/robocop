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

// note that ports 1 and 2 are left
// 3 and 4 are right, order does within groups not matter

#include "vex.h"
#include "cmath"

using namespace vex;

void standard_mode(){
  while ( true ){
    MotorGroup1.setVelocity(Controller1.Axis3.position(percent), percent);
    MotorGroup3.setVelocity(Controller1.Axis2.position(percent), percent);
    if (Controller1.ButtonB.pressing()){
      MotorGroup1.stop();
      MotorGroup3.stop();
      break;
    }
    wait(5, msec);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // start config
  MotorGroup1.setStopping(coast);
  MotorGroup3.setStopping(coast);
  Controller1.ButtonA.pressed(standard_mode);
  Controller1.Screen.print("Press A to start");
  while ( true ){
    wait(5, msec);
  }
}
