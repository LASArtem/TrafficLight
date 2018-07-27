#include <conio.h> //getch

#include "../../common/api_keyboard/api_keyboard.hpp"
#include "../Headers/Keyboard.hpp"

namespace {
#define NAME "Keyboard"
}

//-----------------------------------------------------------------------------
Keyboard::Keyboard()
    : mCtlrPtr(new KeyboardCtrl(this))
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
            , TXT::KEYBOARD_APPL, TXT::NAME_KEYBOARD);
        mCtlrPtr->sendLog(TXT::message);
    }
}

//-----------------------------------------------------------------------------
Keyboard::~Keyboard()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
            , TXT::KEYBOARD_APPL, TXT::NAME_KEYBOARD);
        mCtlrPtr->sendLog(TXT::message);
    }

    delete mCtlrPtr;
}

//-----------------------------------------------------------------------------
void Keyboard::checkButtons()
//-----------------------------------------------------------------------------
{
    if (!_kbhit()) {
        return;
    }

    switch (getch()) {
    case 'S':
    case 's':
        sendCommandUserPressStart();
        break;

    case 'P':
    case 'p':
        sendCommandUserPressPause();
        break;

    case 'E':
    case 'e':
        sendCommandUserPressExit();
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
const char *Keyboard::getName()
//-----------------------------------------------------------------------------
{
    return NAME;
}

//-----------------------------------------------------------------------------
void Keyboard::sendCommandUserPressStart()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandUserPressStart();
    }
}

//-----------------------------------------------------------------------------
void Keyboard::sendCommandUserPressPause()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandUserPressPause();
    }
}

//-----------------------------------------------------------------------------
void Keyboard::sendCommandUserPressExit()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandUserPressExit();
    }
}
