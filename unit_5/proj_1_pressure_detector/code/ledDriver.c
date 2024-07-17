#include "ledDriver.h"
#include "state.h"
#include "std_types.h"

#include "driver.h"

static enum LED_STATES LED_curState = E_ledOff;
ptr2fun LED_curCall = STATE(E_ledOff);

STATE_DEFINE(E_ledOff) {
    //action
    LED_curState = E_ledOff;
    
    Set_Alarm_actuator(0);
}

STATE_DEFINE(E_ledOn) {
    //action
    LED_curState = E_ledOn;
   
    Set_Alarm_actuator(1);
}

//signals
void Signal_turnOnLed(void){
    LED_curCall = STATE(E_ledOn);
}
void Signal_turnOffLed(void){
    LED_curCall = STATE(E_ledOff);
}