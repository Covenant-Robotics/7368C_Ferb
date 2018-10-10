#include "main.h"

Encoder leftEncoder, rightEncoder;
int leftPos, rightPos;

void driveSet(int left, int right) {
  blrsMotorSet(DRIVE_LEFT, left, false);
  blrsMotorSet(DRIVE_RIGHT, right, false);
}

void driveInit() {
  blrsMotorInit(DRIVE_LEFT, true, 0.5f, NULL);
  blrsMotorInit(DRIVE_RIGHT, true, 0.5f, NULL);
  leftEncoder = encoderInit(LEFT_TOP, LEFT_BOTTOM, false);
  rightEncoder = encoderInit(RIGHT_TOP, RIGHT_BOTTOM, false);
}
/*
int leftGetPos() {
  encoderGet(leftEncoder);
}

int rightGetPos() {
  encoderGet(rightEncoder);
}
*/
int driveGetPos() {
  leftPos = encoderGet(leftEncoder);
  rightPos = encoderGet(rightEncoder);
  return ((leftPos+rightPos)/2);
}
