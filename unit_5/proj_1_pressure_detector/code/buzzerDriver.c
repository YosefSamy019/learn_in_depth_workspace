#include "buzzerDriver.h"
#include "state.h"
#include "std_types.h"

#include "driver.h"

static enum Buzzer_STATES Buzzer_curState = E_buzzerOff;
ptr2fun Buzzer_curCall = STATE(E_buzzerOff);

STATE_DEFINE(E_buzzerOff) {
    //action
    Buzzer_curState = E_buzzerOff;
    
    Set_Alarm_actuator(0);
}

STATE_DEFINE(E_buzzerOn) {
    //action
    Buzzer_curState = E_buzzerOn;
    
    Set_Alarm_actuator(1);
}


//signals
void Signal_turnOnBuzzer(void){
    Buzzer_curCall = STATE(E_buzzerOn);
}
void Signal_turnOffBuzzer(void){
    Buzzer_curCall = STATE(E_buzzerOff);
}