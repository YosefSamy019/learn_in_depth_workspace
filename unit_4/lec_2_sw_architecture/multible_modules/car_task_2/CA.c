
#include "CA.h"

unsigned speed, distance, limit = 50;

 void (*CA_state)();

US_setDistance(int d){
    distance = d;
    printf("US \t>>> CA US_setDistance(%d)\n",d);
}


STATE_DEFINE(CA_stop){
    CA_State_id = CA_stop;

    Motor_speed(speed);

    if(distance <= limit) CA_state = STATE(CA_stop);
    else CA_state = STATE(CA_go);

    printf("CA \tstop\n");

}

STATE_DEFINE(CA_go){
    CA_State_id = CA_go;

    Motor_speed(speed);

    if(distance <= limit) CA_state = STATE(CA_stop);
    else CA_state = STATE(CA_go);

    printf("CA \tgo\n");
}
