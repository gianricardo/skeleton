#include "device/system_tick.h"

#include <device/io.h>

#include <avr/interrupt.h>
#include <avr/io.h>

ISR(TIMER1_COMPA_vect) {
}

void SystemTick_init() {
  TCCR1B = bit_value(WGM12) | bit_value(CS10);
  OCR1A = 7999;
}

void SystemTick_register(void(* notify)(void *), void * observer) {

}
