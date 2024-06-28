

#include "CA.h"

unsigned int speed, distance, limit =  50;
void (* state )();


STATE_DEFINE(stop){
    //state id
    state_id = stop;
    speed = 0;
    distance = rand()%20+ 40;

    //state action
    if(distance <= limit) state = STATE(stop);
    else state = STATE(go);

    printf("STOP STATE: \tdistance %d \tspeed %d\n",distance,speed);
}

STATE_DEFINE(go){
    //state id
    state_id = go;
    speed = 30;
    distance = rand()%20+ 40;

    //state action
    if(distance <= limit) state = STATE(stop);
    else state = STATE(go);

    printf("GO STATE: \tdistance %d \tspeed %d\n",distance,speed);
}
