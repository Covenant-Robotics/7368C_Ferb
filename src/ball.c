#include "main.h"

void spinnerSet (int spin) {
  blrsMotorSet(SPIN, spin, false);
}

void flywheelSet(int fly) {
  blrsMotorSet(FLYWHEEL, fly, false);
}

void ballInit() {
  blrsMotorInit(SPIN, false, 0.5f, NULL);
  blrsMotorInit(FLYWHEEL, false, 0.2f, NULL);
}
