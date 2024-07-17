#include "mainControl.h"
#include "state.h"
#include "std_types.h"

static enum MC_STATES MC_curState = E_MC_init;
ptr2fun MC_curCall = STATE(E_MC_init);

const uint32 threshld = 20;
static volatile uint32 pressure = 0;

STATE_DEFINE(E_MC_init) {
    //action
    MC_curState = E_MC_init;
    
    //event
    MC_curCall = STATE(E_MC_update);
}

STATE_DEFINE(E_MC_update) {
    //action
    MC_curState = E_MC_update;
   
    
    if(pressure > threshld){
        Signal_onHighPressureDetect();
    }
}


//signals
void Signal_readPressureSensor(uint32 value){
    pressure = value;
}