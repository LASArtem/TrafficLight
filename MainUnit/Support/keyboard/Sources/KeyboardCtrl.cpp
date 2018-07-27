#include <cstring>// memcpy

#include "../Headers/KeyboardCtrl.hpp"
#include "../../common/api_keyboard/api_keyboard.hpp"
#include "../../common/api_manager/api_manager.hpp"

//-----------------------------------------------------------------------------
KeyboardCtrl::KeyboardCtrl(Keyboard *tPtr)
    : IMailCtrl()
    , mKeyboardPtr(tPtr)
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
        , TXT::KEYBOARD_CTRL, TXT::NAME_KEYBOARD_CTRL);
    sendLog(TXT::message);
    registration(this);
}

//-----------------------------------------------------------------------------
KeyboardCtrl::~KeyboardCtrl()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
        , TXT::KEYBOARD_CTRL, TXT::NAME_KEYBOARD_CTRL);
    sendLog(TXT::message);
}

//-----------------------------------------------------------------------------
const char *KeyboardCtrl::getName()
//-----------------------------------------------------------------------------
{
    if (mKeyboardPtr != nullptr) {
        return mKeyboardPtr->getName();
    } else {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: getName: mKeyboardPtr = nullptr"
            , TXT::KEYBOARD_CTRL);
        sendLog(TXT::message);
        return "default Name: Keyboard";
    }
}

//-----------------------------------------------------------------------------
void KeyboardCtrl::processMail(MAIL &mail)
//-----------------------------------------------------------------------------
{
    if (mail.destination != KEYBOARD) {
        return;
    }

    switch (mail.typeMail) {
    case COMMAND:
        parseCommand(mail);
        break;

    case RESPONSE:
        parseResponse(mail);
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void KeyboardCtrl::sendCommandUserPressStart()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandUserPressStart", TXT::KEYBOARD_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = KEYBOARD;
    mail.destination = MANAGER;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_USER_PRESS_START);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void KeyboardCtrl::sendCommandUserPressPause()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandUserPressPause", TXT::KEYBOARD_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = KEYBOARD;
    mail.destination = MANAGER;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_USER_PRESS_PAUSE);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void KeyboardCtrl::sendCommandUserPressExit()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandUserPressExit", TXT::KEYBOARD_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = KEYBOARD;
    mail.destination = MANAGER;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_USER_PRESS_EXIT);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void KeyboardCtrl::parseCommand(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    /*
    case COMMAND_COUNT_TIME_IS_FINISHED:
        printf("[KeyCTLR]: parseCommand: COMMAND_COUNT_TIME_IS_FINISHED\n");
        sendResponseCountTimeIsFinished();
        break;
*/
    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void KeyboardCtrl::parseResponse(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    /*
    case RESPONSE_START_STATEMACHINE:
        printf("[KeyCTLR]: from STATEMACHINE: RESPONSE_START_STATEMACHINE\n");
        break;
*/
    default:
        break;
    }
}
