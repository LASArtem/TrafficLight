#ifndef MANAGERCTRL_HPP
#define MANAGERCTRL_HPP

#include "../../common/api_mails/IMailCtrl.hpp"
#include "Keyboard.hpp"
class Keyboard;

class KeyboardCtrl: public IMailCtrl
{
public:
    KeyboardCtrl(Keyboard *tPtr = nullptr);
    virtual ~KeyboardCtrl();

    virtual const char *getName();
    virtual void processMail(MAIL &mail);

    void sendCommandUserPressStart();
    void sendCommandUserPressPause();
    void sendCommandUserPressExit();

private:
    void parseCommand(MAIL &mail);
    void parseResponse(MAIL &mail);

private:
    Keyboard *mKeyboardPtr;
};
#endif //MANAGERCTRL_HPP
