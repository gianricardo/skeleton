#include "device/ipwm.h"

void Pwm_on(struct IPwm * base)
{
  base->on(base);
}

void Pwm_off(struct IPwm * base)
{
  base->off(base);
}
