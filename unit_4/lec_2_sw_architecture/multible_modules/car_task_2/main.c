#include <stdio.h>
#include <stdlib.h>

#include "states.h"
#include "CA.h"
#include "US.h"
#include "MOTOR.h"

int main()
{

    int d=0,i=0;

    CA_state = STATE(CA_stop);
    US_state = STATE(US_init);
    MOTOR_state = STATE(MOTOR_init);

    while(1){
            US_state();
            CA_state();
            MOTOR_state();

            printf("\n");

            for(d=0;d<1000;d++);

            if(i++>100) break;
    }


    return 0;
}
