#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "KeyboardCtrl.hpp"

class KeyboardCtrl;

class Keyboard
{
public:
    Keyboard();
    ~Keyboard();

    void checkButtons();
    const char *getName();

private:
    void sendCommandUserPressStart();
    void sendCommandUserPressPause();
    void sendCommandUserPressExit();

private:
    KeyboardCtrl *mCtlrPtr;
};

#endif //KEYBOARD_HPP
