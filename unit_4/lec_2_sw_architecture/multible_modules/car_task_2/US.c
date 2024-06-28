#include "US.h"

void (*US_state)();
unsigned int distance = 0;

STATE_DEFINE(US_init){
    //move to loop state
    US_State_id = US_loop;
    US_state = STATE(US_loop);

    printf("US \tinit\n");
}

STATE_DEFINE(US_loop){
    US_State_id = US_loop;
    US_state = STATE(US_loop);

    distance = rand()%20 + 40;

    US_setDistance(distance);

    printf("US \tloop \tdistance %d\n",distance);
}
