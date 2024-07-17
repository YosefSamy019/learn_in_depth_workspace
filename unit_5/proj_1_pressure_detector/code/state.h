
#ifndef _STATE_H_
#define _STATE_H_

#include "std_types.h"

#define STATE_DEFINE(state) void state_define_##state()
#define STATE(state) state_define_##state 

//signals
void Signal_readPressureSensor(uint32 value);
void Signal_onHighPressureDetect(void);
void Signal_turnOnBuzzer(void);
void Signal_turnOffBuzzer(void);
void Signal_turnOnLed(void);
void Signal_turnOffLed(void);

#endif