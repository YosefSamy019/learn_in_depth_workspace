
#ifndef _PRESSURE_SENSOR_DRIVER_H_
#define _PRESSURE_SENSOR_DRIVER_H_

#include "state.h"
#include "std_types.h"

enum PS_STATES{
    E_PS_init,
    E_PS_update
};

STATE_DEFINE(E_PS_init);
STATE_DEFINE(E_PS_update);

extern ptr2fun PS_curCall;

#endif