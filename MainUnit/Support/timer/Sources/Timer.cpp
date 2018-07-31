#include "../../common/api_txtRecord/api_txtRecord.hpp" //for names of component
#include "../Headers/Timer.hpp"
#include<ctime>

//-----------------------------------------------------------------------------
Timer::Timer()
    : mCtlrPtr(new TimerCtrl(this))
     ,mCounter(0)
     ,mStartCounter(0)
     ,mEndCounter(0)
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

//-----------------------------------------------------------------------------
void Timer::notifyStartCountTime(uint32_t seconds)
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: notifyStartCountTime: << %d seconds>>"
            , TXT::TIMER_APPL, seconds);
        mCtlrPtr->sendLog(TXT::message);
    }

    mCounter = seconds;
    mStartCounter = clock();

   sendCommandCheckCountTime();

}


//-----------------------------------------------------------------------------
void Timer::notifyCheckCountTime()
//-----------------------------------------------------------------------------
{
    mEndCounter = clock();
    uint32_t endCheck = mEndCounter + 500.0;

    if((mEndCounter - mStartCounter)/1000.0 >= mCounter){
        mCounter = 0;
        mStartCounter = 0;
        mEndCounter = 0;
        sendResponseCheckCountTime();
        return;
    }

    while (mEndCounter < endCheck) {
        mEndCounter = clock();
    }
    sendCommandCheckCountTime();




}


//-----------------------------------------------------------------------------
void Timer::sendCommandCheckCountTime()
//-----------------------------------------------------------------------------
{
    if(mCtlrPtr !=nullptr){
        mCtlrPtr->sendCommandCheckCountTime();
    }
}


//-----------------------------------------------------------------------------
void Timer::sendResponseCheckCountTime()
//-----------------------------------------------------------------------------
{
    if(mCtlrPtr !=nullptr){
        mCtlrPtr->sendResponseCheckCountTime();
    }
}



