#include "alarmManager.h"
#include "state.h"
#include "std_types.h"

static enum ALARM_MANAGER_STATES ALARM_MANAGER_curState = E_alarmOff;
ptr2fun ALARM_MANAGER_curCall = STATE(E_alarmOff);

static  utimer alarmTime=0;

STATE_DEFINE(E_alarmOff) {
    //action
    ALARM_MANAGER_curState = E_alarmOff;
    
    Signal_turnOffLed();
    Signal_turnOffBuzzer();
}

STATE_DEFINE(E_alarmOn) {
    //action
    ALARM_MANAGER_curState = E_alarmOn;
   
    //wait timer
    while(alarmTime > 0) {
        alarmTime--;
    }
    
    //reset
    alarmTime = ALARM_TIME;
    Signal_turnOffLed();
    Signal_turnOffBuzzer();
    ALARM_MANAGER_curCall = STATE(E_alarmOff);
    
    
}

//signals
void Signal_onHighPressureDetect(void){
    if(ALARM_MANAGER_curState == E_alarmOff){
        Signal_turnOnLed();
        Signal_turnOnBuzzer();
        
        //set timer
        alarmTime = ALARM_TIME;
        
        ALARM_MANAGER_curCall = STATE(E_alarmOn);
    }
}