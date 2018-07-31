#ifndef TIMER_HPP
#define TIMER_HPP

#include <cstdint> //uint32_t and other

#include "TimerCtrl.hpp"
class TimerCtrl;

class Timer
{
public:
    Timer();
    ~Timer();

    const char *getName();

    //notify
    void notifyStartCountTime(uint32_t seconds);
    void notifyCheckCountTime();

private:
    //send
    void sendCommandCheckCountTime();
    void sendResponseCheckCountTime();

private:
    TimerCtrl *mCtlrPtr;
    uint32_t mCounter;
    uint32_t mStartCounter;
    uint32_t mEndCounter;
};

#endif //TIMER_HPP
