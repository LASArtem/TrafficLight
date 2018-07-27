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
private:
    TimerCtrl *mCtlrPtr;
};

#endif //TIMER_HPP
