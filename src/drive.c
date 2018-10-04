#include "main.h"

void driveSet(int left, int right) {
  blrsMotorSet(DRIVE_LEFT, left, false);
  blrsMotorSet(DRIVE_RIGHT, right, false);
}

void driveInit() {
  blrsMotorInit(DRIVE_LEFT, true, 0.5f, NULL);
  blrsMotorInit(DRIVE_RIGHT, true, 0.5f, NULL);
}
