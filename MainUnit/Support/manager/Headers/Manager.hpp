#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "ManagerCtrl.hpp"

class ManagerCtrl;

class Manager
{
public:
    Manager();
    ~Manager();

    const char *getName();
    bool checkExit();

    //to StateMachine
    void sendCommandStartStateMachine();
    void sendCommandPauseStateMachine();
    void sendCommandChangeColourState();
    void sendCommandGetCurrentColourState();

    //to Timer
    void sendCommandGetCurrentTime();
    void sendCommandStartCountTime();
    void sendCommandPauseCountTime();
    void sendCommandContinueCountTime();

    //notify
    void notifyGetCurrentColourState(uint32_t colour);
    void notifyUserPressExit();
    void notifyUserPressStart();
    void notifyUserPressPause();

private:
    ManagerCtrl *mCtlrPtr;
    bool mIsExit;
};

#endif //MANAGER_HPP
