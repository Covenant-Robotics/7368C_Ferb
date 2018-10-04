#include "main.h"
void liftSet (int lift) {
  blrsMotorSet(LIFT, lift, false);
}
void liftInit (int lift) {
  blrsMotorInit(LIFT, false, 0.5f, NULL);
}
