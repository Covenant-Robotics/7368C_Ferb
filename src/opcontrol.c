#include "main.h"

 int power;
 int turn;
 int lift;
 int flip;
 bool spinner;
 bool notspinner;
 int spin;
 int fly;
 bool flyhigh;
 bool flylow;


void operatorControl() {
	while (1) {
		delay(20);

////////////////////////////////////////////////////////////////////////////////
//                                 DRIVE CODE                                 //
////////////////////////////////////////////////////////////////////////////////
		power = joystickGetAnalog(1, 3);
		turn = joystickGetAnalog(1, 4);

		if (abs(power) < 15) {
			power = 0;
		}
		if (abs(turn) < 15) {
			turn = 0;
		}
		if (abs(turn) > 95) {
			turn = 95;
		}
		driveSet(power + turn, power - turn);

////////////////////////////////////////////////////////////////////////////////
//                                 LIFT CODE                                  //
////////////////////////////////////////////////////////////////////////////////
		if (buttonGetState(JOY1_6U)) {
			lift = 100;
		}
		else if (buttonGetState(JOY1_6D)) {
			lift = -60;
		}
		else {
			lift = 0;
		}
		liftSet(lift);

////////////////////////////////////////////////////////////////////////////////
//                                FLIPPER CODE                                //
////////////////////////////////////////////////////////////////////////////////
    if (buttonGetState(JOY1_8R)) {
      flip = 100;
    }
    else {
      flip = 0;
    }
    flipSet(flip);

////////////////////////////////////////////////////////////////////////////////
//                                 SPINNER CODE                               //
////////////////////////////////////////////////////////////////////////////////
  if (buttonIsNewPress(JOY1_8U)) {
    spinner = !spinner;
  }
  if (buttonIsNewPress(JOY1_8D)) {
    notspinner = !notspinner;
  }
  if (spinner) {
    spin = 100;
  }
  else if (notspinner) {
    spin = -100;
  }
  else {
    spin = 0;
  }
  spinnerSet(spin);
////////////////////////////////////////////////////////////////////////////////
//                             FLYWHEEL CODE                                  //
////////////////////////////////////////////////////////////////////////////////
  if (buttonIsNewPress(JOY1_5U)) {
    flyhigh = !flyhigh ;
  }
  if (buttonIsNewPress(JOY1_5D)) {
    flylow = !flylow ;
  }
  if (flyhigh) {
    fly = 120;
  }
  else if (flylow) {
    fly = 70;
  }
  else {
    fly = 0;
  }
  flywheelSet(fly);
// end of while loop
  }
// end of opcontrol
}
