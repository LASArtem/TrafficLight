#ifndef TIMERCTRL_HPP
#define TIMERCTRL_HPP

#include "../../common/api_mails/IMailCtrl.hpp"
#include "../../common/api_stateMachine/api_stateMachine.hpp"
#include "StateMachine.hpp"
class StateMachine;

class StateMachineCtrl: public IMailCtrl
{
public:
    StateMachineCtrl(StateMachine *tPtr = nullptr);
    virtual ~StateMachineCtrl();

    virtual const char *getName();
    virtual void processMail(MAIL &mail);

private:
    void parseCommand(MAIL &mail);
    void parseResponse(MAIL &mail);

    void sendResponseStartStateMachine();
    void sendResponsePauseStateMachine();
    void sendResponseChangeColourState();
    void sendResponseGetCurrentColourState();

private:
    StateMachine *mStateMachinePtr;
};
#endif //TIMERCTRL_HPP
