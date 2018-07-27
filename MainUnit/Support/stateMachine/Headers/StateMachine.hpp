#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "StateMachineCtrl.hpp"
class StateMachineCtrl;

class StateMachine
{
public:
    StateMachine(COLOUR_STATE colourState = RED);
    ~StateMachine();

    const char *getName() const;
    const COLOUR_STATE getColourState() const;
private:
    StateMachineCtrl *mCtlrPtr;
    COLOUR_STATE mColourState;
};

#endif //STATEMACHINE_HPP
