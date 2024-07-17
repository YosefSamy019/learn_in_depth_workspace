
#ifndef _BUZZER_DRIVER_H_
#define _BUZZER_DRIVER_H_

#include "state.h"
#include "std_types.h"

enum Buzzer_STATES{
    E_buzzerOn,
    E_buzzerOff
};

STATE_DEFINE(E_buzzerOn);
STATE_DEFINE(E_buzzerOff);

extern ptr2fun Buzzer_curCall;

#endif