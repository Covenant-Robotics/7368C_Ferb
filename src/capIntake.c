#include "main.h"

void liftSet(int lift) {
  blrsMotorSet(LIFT, lift, false);
  blrsMotorSet(LIFT_2, lift, false);
}

void flipSet(int flip) {
  blrsMotorSet(FLIP, flip, false);
}

void capInit() {
  blrsMotorInit(LIFT, false, 0.5f, NULL);
  blrsMotorInit(LIFT_2, true, 0.5f, NULL);
  blrsMotorInit(FLIP, false, 0.5f, NULL);
}
