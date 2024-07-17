#include "pressureSensorDriver.h"
#include "state.h"
#include "std_types.h"

#include "driver.h"

static enum PS_STATES PS_curState = E_PS_init;
ptr2fun PS_curCall = STATE(E_PS_init);

STATE_DEFINE(E_PS_init) {
    //action
    PS_curState = E_PS_init;
    
    //event
    PS_curCall = STATE(E_PS_update);
}
STATE_DEFINE(E_PS_update) {
    //action
    PS_curState = E_PS_update;
    
    uint32 pressureVal = (uint32) getPressureVal(); 
//    static  uint32 pressureVal = 1;
//    pressureVal = pressureVal + 1;
    
    //send signal
    Signal_readPressureSensor(pressureVal);
    
    //event
    PS_curCall = STATE(E_PS_update);
}
