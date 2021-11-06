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
// MotorGroup18         motor_group   18, 19          
// MotorGroup17         motor_group   17, 16          
// MotorGroup14         motor_group   14, 15          
// ---- END VEXCODE CONFIGURED DEVICES ----

/* PORTS:
T8 = 14
T6 = 15
T4 = 17
T2 = 16
T8 = 18
T1 = 19
*/

#include "vex.h"
#include "cmath"
#include <string>

using namespace std;

namespace run_cofigs{
  double run_speed = 1;
  string mode_name;
  bool forward_ = false;
  int spin_lift = 0; // 0=stay, 1=up, 2=down
}

#define screen_print Controller1.Screen.print
#define screen_clear Controller1.Screen.newLine

#define left_wheels MotorGroup17
#define right_wheels MotorGroup18
#define lift_motors MotorGroup14


using namespace vex;
using namespace run_cofigs;

void flash_speed(){
  screen_clear();
  screen_print("%s - %.2f       ", mode_name.c_str(), run_speed);
  Brain.Screen.clearLine();
  Brain.Screen.print("%s - %.2f", mode_name.c_str(), run_speed);
}

void set_half_speed() {
  run_speed = 0.5;
  mode_name = "HALF";
  flash_speed()
  ;
}

void set_full_speed() {
  run_speed = 1.0;
  mode_name = "FULL";
  flash_speed();
}

void threq() {
  run_speed = 0.75;
  mode_name = "THREQ";
  flash_speed();
}

void forward_set() {
  forward_ = !forward_;
  Brain.Screen.newLine();
  Brain.Screen.print("Forward: %i", forward_);
}

void lift_up() {
  spin_lift = 1;
}

void lift_down() {
  spin_lift = 2;
}

void lift_stop() {
  spin_lift = 0;
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // start config
  left_wheels.setStopping(coast);
  right_wheels.setStopping(coast);
  lift_motors.setStopping(brake);
  Controller1.ButtonA.pressed(set_full_speed);
  Controller1.ButtonB.pressed(set_half_speed);
  Controller1.ButtonY.pressed(threq);
  Controller1.ButtonX.pressed(forward_set);
  Controller1.ButtonR1.pressed(lift_up);
  Controller1.ButtonR2.pressed(lift_down);
  Controller1.ButtonR1.released(lift_stop);
  Controller1.ButtonR2.released(lift_stop);
  while ( true ){
    double left = Controller1.Axis3.position(percent);
    double right = Controller1.Axis2.position(percent);
    if (((fabs(left) >= 0.3) || (fabs(right) >= 0.3))) {
      MotorGroup17.spin(fwd, left * run_speed, percent);
      MotorGroup18.spin(fwd, right * run_speed, percent);
      forward_ = false;
    }
    else if (forward_){
      MotorGroup17.spin(fwd, run_speed * 100, percent);
      MotorGroup18.spin(fwd, run_speed * 100, percent);
      screen_clear();
    }
    else {
      MotorGroup17.stop();
      MotorGroup18.stop();
    }
    int lift_spin_magnitude = 15; // in intager percent
    if (spin_lift == 0) {
      lift_motors.stop();
    }
    else if (spin_lift == 1) {
      lift_motors.spin(fwd, lift_spin_magnitude, percent);
    }
    else if (spin_lift == 2) {
      lift_motors.spin(reverse, lift_spin_magnitude, percent);
    }

    wait(5, msec);
  }
}
