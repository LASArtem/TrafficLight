#ifndef MANAGERCTRL_HPP
#define MANAGERCTRL_HPP

#include "../../common/api_mails/IMailCtrl.hpp"
#include "Manager.hpp"
class Manager;

class ManagerCtrl: public IMailCtrl
{
public:
    ManagerCtrl(Manager *tPtr = nullptr);
    virtual ~ManagerCtrl();

    virtual const char *getName();
    virtual void processMail(MAIL &mail);

    //to StateMachine
    void sendCommandStartStateMachine();
    void sendCommandPauseStateMachine();
    void sendCommandChangeColourState();
    void sendCommandGetCurrentColourState();

    //to Timer
    void sendCommandGetCurrentTime();
    void sendCommandStartCountTime(uint32_t sec);
    void sendCommandPauseCountTime();
    void sendCommandContinueCountTime();

private:
    void parseCommand(MAIL &mail);
    void parseResponse(MAIL &mail);

    void parseCommandFromKeyBoard(MAIL &mail);
    void parseCommandFromStateMachine(MAIL &mail);
    void parseCommandFromTimer(MAIL &mail);

    void parseResponseFromKeyBoard(MAIL &mail);
    void parseResponseFromStateMachine(MAIL &mail);
    void parseResponseFromTimer(MAIL &mail);

    //send
    void sendResponseCountTimeIsFinished();

    //process
    void processCommandUserPressExit();
    void processResponseGetCurrentColorState(MAIL &mail);

private:
    Manager *mManagerPtr;
};
#endif //MANAGERCTRL_HPP
