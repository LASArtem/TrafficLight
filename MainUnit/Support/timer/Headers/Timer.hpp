#ifndef TIMER_HPP
#define TIMER_HPP

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

private:
    TimerCtrl *mCtlrPtr;
};

#endif //TIMER_HPP
