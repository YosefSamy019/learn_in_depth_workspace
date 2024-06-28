#ifndef STATES_H_INCLUDED
#define STATES_H_INCLUDED

#define STATE_DEFINE(_state_)   void ST_##_state_()
#define STATE(_state_)          ST_##_state_

//signals
US_setDistance(int d);
Motor_speed(int s);

#endif // STATES_H_INCLUDED
