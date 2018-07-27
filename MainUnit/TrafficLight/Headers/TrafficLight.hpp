#ifndef TRAFFICLIGHT_HPP
#define TRAFFICLIGHT_HPP

#include "../../Support/keyboard/Headers/Keyboard.hpp"
#include "../../Support/mails/Headers/MailOffice.hpp"
#include "../../Support/manager/Headers/Manager.hpp"
#include "../../Support/stateMachine/Headers/StateMachine.hpp"
#include "../../Support/timer/Headers/Timer.hpp"

class TrafficLight
{
public:
    TrafficLight();
    ~TrafficLight();

    void execute();
private:
    MailOffice mMailOffice;
    MailBox &mMailBox;
    Keyboard mKeyBoard;
    Manager mManager;
    StateMachine mStateMachine;
    Timer mTimer;
};

#endif //TRAFFICLIGHT_HPP
