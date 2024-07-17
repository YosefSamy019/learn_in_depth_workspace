
#ifndef _MAIN_CONTROL_H_
#define _MAIN_CONTROL_H_

#include "state.h"
#include "std_types.h"

enum MC_STATES{
    E_MC_init,
    E_MC_update
};

STATE_DEFINE(E_MC_init);
STATE_DEFINE(E_MC_update);

extern ptr2fun MC_curCall;

#endif