#ifndef CA_H_INCLUDED
#define CA_H_INCLUDED

enum{
stop,
go
} state_id;

#define STATE_DEFINE(_state_)   void ST_##_state_()
#define STATE(_state_)          ST_##_state_

STATE_DEFINE(stop);
STATE_DEFINE(go);

extern void (* state )();


#endif // CA_H_INCLUDED
