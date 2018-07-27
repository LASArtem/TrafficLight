#include "../Headers/StateMachine.hpp"

//-----------------------------------------------------------------------------
StateMachine::StateMachine(COLOUR_STATE colourState)
    : mCtlrPtr(new StateMachineCtrl(this))
    , mColourState(colourState)
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
            , TXT::STATEMACHINE_APPL, getName());
        mCtlrPtr->sendLog(TXT::message);
    }
}

//-----------------------------------------------------------------------------
StateMachine::~StateMachine()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
            , TXT::STATEMACHINE_APPL, getName());
        mCtlrPtr->sendLog(TXT::message);
    }

    delete mCtlrPtr;
}

//-----------------------------------------------------------------------------
const char *StateMachine::getName() const
//-----------------------------------------------------------------------------
{
    return TXT::NAME_STATEMACHINE;
}

//-----------------------------------------------------------------------------
const COLOUR_STATE StateMachine::getColourState() const
//-----------------------------------------------------------------------------
{
    return mColourState;
}
