#ifndef US_H_INCLUDED
#define US_H_INCLUDED

#include "states.h"

enum US_states{
    US_init,US_loop
}US_State_id;

STATE_DEFINE(US_init);
STATE_DEFINE(US_loop);

extern void (*US_state)();

#endif // US_H_INCLUDED
