#include "../../common/api_txtRecord/api_txtRecord.hpp" //for names of component
#include "../Headers/Timer.hpp"

//-----------------------------------------------------------------------------
Timer::Timer()
    : mCtlrPtr(new TimerCtrl(this))
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
            , TXT::TIMER_APPL, getName());
        mCtlrPtr->sendLog(TXT::message);
    }
}

//-----------------------------------------------------------------------------
Timer::~Timer()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
            , TXT::TIMER_APPL, getName());
        mCtlrPtr->sendLog(TXT::message);
    }

    delete mCtlrPtr;
}

//-----------------------------------------------------------------------------
const char *Timer::getName()
//-----------------------------------------------------------------------------
{
    return TXT::NAME_TIMER;
}
