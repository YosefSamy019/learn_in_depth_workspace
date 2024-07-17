
#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_

#include "state.h"
#include "std_types.h"

enum LED_STATES{
    E_ledOn,
    E_ledOff
};

STATE_DEFINE(E_ledOn);
STATE_DEFINE(E_ledOff);

extern ptr2fun LED_curCall;

#endif