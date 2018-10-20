#include "main.h"

 int power;
 int turn;
 int lift;
 bool liftHold;
 int flipper;
 bool flip;
 bool spinner;
 bool notSpinner;
 int spin;
 int fly;
 bool flyHigh;
 bool flyLow;


void operatorControl() {
	while (1) {
		delay(20);

    lcdSetText(uart1, 1, "COVENANT");

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
    if (buttonIsNewPress(JOY1_7U)) {
      liftHold = !liftHold;
    }
    if (buttonGetState(JOY1_6U)) {
			lift = 100;
		}
		else if (buttonGetState(JOY1_6D)) {
			lift = -60;
		}
    else if (liftHold) {
      if (analogRead(LIFT_POT) < 400) {
        lift = 80;
      }
      else {
        lift = 0;
      }
    }
		else {
			lift = 0;
		}
		liftSet(lift);

////////////////////////////////////////////////////////////////////////////////
//                                FLIPPER CODE                                //
////////////////////////////////////////////////////////////////////////////////
    if (buttonIsNewPress(JOY1_8R)) {
      flip = !flip;
    }
    if (flip) {
      if(analogRead(FLIP_POT) > 100) {
        flipper = 80;
      }
      else {
        flipper = 0;
      }
    }
    else {
      if (analogRead(FLIP_POT) < 1000) {
        flipper = -80;
      }
      else {
        flipper = 0;
      }
    }
    flipSet(flipper);
////////////////////////////////////////////////////////////////////////////////
//                                 SPINNER CODE                               //
////////////////////////////////////////////////////////////////////////////////
  if (buttonIsNewPress(JOY1_8U)) {
    spinner = !spinner;
  }
  if (buttonIsNewPress(JOY1_8D)) {
    notSpinner = !notSpinner;
  }
  if (spinner) {
    spin = 100;
  }
  else if (notSpinner) {
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
    flyHigh = !flyHigh ;
  }
  if (buttonIsNewPress(JOY1_5D)) {
    flyLow = !flyLow ;
  }
  if (flyHigh) {
    fly = 120;
  }
  else if (flyLow) {
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
