#include "MOTOR.h"


void (*MOTOR_state)();
unsigned int speed = 0;

Motor_speed(int s){
    speed = s;
    MOTOR_state = STATE(MOTOR_busy);


    printf("CA \t>>> MOTOR, Motor_speed(%d)\n",s);
}

STATE_DEFINE(MOTOR_init){
    MOTOR_State_id = MOTOR_idle;
    MOTOR_state = STATE(MOTOR_idle);

    printf("MOTOR \tinit\n");
}

STATE_DEFINE(MOTOR_idle){
    MOTOR_State_id = MOTOR_idle;

    MOTOR_state = STATE(MOTOR_idle);

    printf("MOTOR \tidle\n");
}

STATE_DEFINE(MOTOR_busy){
    MOTOR_State_id = MOTOR_busy;

    MOTOR_state = STATE(MOTOR_idle);

    printf("MOTOR \tbusy\n");
}

