#ifndef TIMERCTRL_HPP
#define TIMERCTRL_HPP

#include "../../common/api_mails/IMailCtrl.hpp"
#include "Timer.hpp"
class Timer;

class TimerCtrl: public IMailCtrl
{
public:
    TimerCtrl(Timer *tPtr = nullptr);
    virtual ~TimerCtrl();

    virtual const char *getName();
    virtual void processMail(MAIL &mail);

private:
    void parseCommand(MAIL &mail);
    void parseResponse(MAIL &mail);

    void sendResponseGetCurrentTime();
    void sendResponseStartCountTime();
    void sendResponsePauseCountTime();
    void sendResponseCountinueCountTime();

private:
    Timer *mTimerPtr;
};
#endif //TIMERCTRL_HPP
