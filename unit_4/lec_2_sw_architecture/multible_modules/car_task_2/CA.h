#ifndef CA_H_INCLUDED
#define CA_H_INCLUDED

#include "states.h"

enum CA_states{
    CA_stop,CA_go
}CA_State_id;

STATE_DEFINE(CA_stop);
STATE_DEFINE(CA_go);

extern void (*CA_state)();

#endif // CA_H_INCLUDED

