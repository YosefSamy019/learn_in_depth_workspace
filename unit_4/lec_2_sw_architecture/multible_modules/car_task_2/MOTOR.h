#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

#include"states.h"

enum MOTOR_states{
    MOTOR_init,MOTOR_idle,MOTOR_busy
}MOTOR_State_id;

STATE_DEFINE(MOTOR_init);
STATE_DEFINE(MOTOR_idle);
STATE_DEFINE(MOTOR_busy);

extern void (*MOTOR_state)();

#endif // MOTOR_H_INCLUDED
