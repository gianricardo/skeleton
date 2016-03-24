#ifndef SKELETON_INTERRUPT_H
#define SKELETON_INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

#define ISR(name) void name()

extern void TIMER1_COMPA_vect();

extern void sei();
extern void cli();

#ifdef __cplusplus
} // extern "C"
#endif


#endif //SKELETON_INTERRUPT_H
