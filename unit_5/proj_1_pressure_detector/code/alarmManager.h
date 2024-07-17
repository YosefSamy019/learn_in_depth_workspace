
#ifndef _ALARM_MANAGER_H_
#define _ALARM_MANAGER_H_

#include "state.h"
#include "std_types.h"

#define ALARM_TIME (utimer)5000

enum ALARM_MANAGER_STATES{
    E_alarmOff,
    E_alarmOn
};

STATE_DEFINE(E_alarmOff);
STATE_DEFINE(E_alarmOn);

extern ptr2fun ALARM_MANAGER_curCall;

#endif