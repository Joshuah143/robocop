# robocop
The source for our Vex V5 robot

## Greg:
[![Our robot](https://github.com/Joshuah143/robocop/blob/main/img.png "GREG")](https://github.com/Joshuah143/robocop)

# Resources:

 - [drive folder](https://drive.google.com/open?id=127Mzc9Ae0EIo83zuiMaaNYiwo3xQIhEh&authuser=joshuah143%40educbe.ca&usp=drive_fs)
 - [vex site](https://www.vexrobotics.com/)
 - [vex discord](https://discord.gg/KvU8BWwh)
 - [vexcode and vex downloads](https://www.vexrobotics.com/vexcode-download)
 - [team discord](https://discord.gg/7j5vRAp8)

# Remote:

## Joysticks:

The left and right joystick respectivly controlle the speeds of the left and right side motors respectivly based off the y component of the joystick. So if both are up it will move forward. Note that the x-axis hasnt been configed and the the y component will be multiplied by the speed coefiscient set by the leter buttons.

## Letter buttons:

### A:

sets full speed and calls flash_speed

### B:

sets half speed and calls flash_speed

### X:

sets the auto-on variable so that the robot will move forwrad with the speed described by the speed coeficiant. This can be stopped by pressing x again or touching the joysticks. Note that if it isnt working its likly that the joysticks are still registering some moment so adjust them to 0.

### Y:

sets 0.75 speed and calls flash_speed

## Right bumbers:

### Top:

sets the lift varieble to 2 so that the arm is lefted in the run loop when pressed. Set to 0 when released.

### Bottom:

sets the lift varieble to 2 so that the arm is lefted in the run loop when pressed. Set to 0 when released.

Note that if they seam reversed switch the cabels on the two lifting motors.

# Port mappings

|**Motor #**|**Port #**|**Desciption**|
|:---:|:---:|:---|
|T8|14| 
|T6|15|
|T5|17|
|T2|16|
|T4|18|
|T1|19|

# Todo:

 - [ ] fix axles on lifting arm
 - [ ] switch lifting arms to metal gears
 - [ ] add HS inserts to lifting motors
 - [ ] attache new cables
 - [ ] design ring pick up stuff
 - [ ] test code and robot
 - [ ] add auto robot mode
