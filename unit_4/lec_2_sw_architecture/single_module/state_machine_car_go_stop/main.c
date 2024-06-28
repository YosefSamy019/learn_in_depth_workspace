#include <stdio.h>
#include <stdlib.h>

#include "CA.h"

int main()
{
    int d=0,l=0;

    //setup
    state = STATE(stop);

    while(1){
        state();

        for(d=0;d<10000;d++);

        if(l++ > 100) break;

    }

    return 0;
}
