#include "std_types.h"
#include "state.h"

#include "driver.h"

#include "alarmManager.h"
#include "buzzerDriver.h"
#include "ledDriver.h"
#include "mainControl.h"
#include "pressureSensorDriver.h"


int main() {
    GPIO_INITIALIZATION();


    while (1) {
        //        int i;
        //        Set_Alarm_actuator(0);
        //        for ( i=0;i<10000;i++);
        //        Set_Alarm_actuator(0);
        //        for ( i=0;i<10000;i++);
        //        continue;
        //
        PS_curCall();
        MC_curCall();
        ALARM_MANAGER_curCall();
        Buzzer_curCall();
        LED_curCall();
    }
    
    return 1;
}