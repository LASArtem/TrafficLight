#include <cstring>// memcpy

#include "../../common/api_stateMachine/api_stateMachine.hpp"
#include "../Headers/StateMachineCtrl.hpp"

//-----------------------------------------------------------------------------
StateMachineCtrl::StateMachineCtrl(StateMachine *tPtr)
    : IMailCtrl()
    , mStateMachinePtr(tPtr)
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
        , TXT::STATEMACHINE_CTRL, TXT::NAME_STATEMACHINE_CTRL);
    sendLog(TXT::message);
    registration(this);
}

//-----------------------------------------------------------------------------
StateMachineCtrl::~StateMachineCtrl()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
        , TXT::STATEMACHINE_CTRL, TXT::NAME_STATEMACHINE_CTRL);
    sendLog(TXT::message);
}

//-----------------------------------------------------------------------------
const char *StateMachineCtrl::getName()
//-----------------------------------------------------------------------------
{
    if (mStateMachinePtr != nullptr) {
        return mStateMachinePtr->getName();
    } else {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: getName: %s"
            , TXT::STATEMACHINE_CTRL, "mStateMachinePtr = nullptr");
        sendLog(TXT::message);
        return "default Name: StateMachine";
    }
}

//-----------------------------------------------------------------------------
void StateMachineCtrl::processMail(MAIL &mail)
//-----------------------------------------------------------------------------
{
    if (mail.destination != STATEMACHINE) {
        return;
    }

    switch (mail.typeMail){
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
void StateMachineCtrl::parseCommand(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    case COMMAND_START_STATEMACHINE:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommand: %s"
            , TXT::STATEMACHINE_CTRL, "COMMAND_START_STATEMACHINE");
        sendLog(TXT::message);
        sendResponseStartStateMachine();
        break;

    case COMMAND_PAUSE_STATEMACHINE:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommand: %s"
            , TXT::STATEMACHINE_CTRL, "COMMAND_PAUSE_STATEMACHINE");
        sendLog(TXT::message);
        sendResponsePauseStateMachine();
        break;

    case COMMAND_CHANGE_COLOUR_STATE:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommand: %s"
            , TXT::STATEMACHINE_CTRL, "COMMAND_CHANGE_COLOUR_STATE");
        sendLog(TXT::message);
        sendResponseChangeColourState();
        break;

    case COMMAND_GET_CURRENT_COLOUR_STATE:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommand: %s"
            , TXT::STATEMACHINE_CTRL, "COMMAND_GET_CURRENT_COLOUR_STATE");
        sendLog(TXT::message);
        sendResponseGetCurrentColourState();
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void StateMachineCtrl::parseResponse(MAIL &mail)
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
void StateMachineCtrl::sendResponseStartStateMachine()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendResponseStartStateMachine", TXT::STATEMACHINE_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = STATEMACHINE;
    mail.destination = MANAGER;
    mail.typeMail = RESPONSE;
    mail.dataType = static_cast<uint32_t>(RESPONSE_START_STATEMACHINE);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void StateMachineCtrl::sendResponsePauseStateMachine()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendResponsePauseStateMachine", TXT::STATEMACHINE_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = STATEMACHINE;
    mail.destination = MANAGER;
    mail.typeMail = RESPONSE;
    mail.dataType = static_cast<uint32_t>(RESPONSE_PAUSE_STATEMACHINE);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void StateMachineCtrl::sendResponseChangeColourState()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendResponseChangeColourState", TXT::STATEMACHINE_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = STATEMACHINE;
    mail.destination = MANAGER;
    mail.typeMail = RESPONSE;
    mail.dataType = static_cast<uint32_t>(RESPONSE_CHANGE_COLOUR_STATE);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void StateMachineCtrl::sendResponseGetCurrentColourState()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendResponseGetCurrentColourState", TXT::STATEMACHINE_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = STATEMACHINE;
    mail.destination = MANAGER;
    mail.typeMail = RESPONSE;
    mail.dataType = static_cast<uint32_t>(RESPONSE_GET_CURRENT_COLOUR_STATE);
    if (mStateMachinePtr != nullptr) {
        mail.dataSize = sizeof(COLOUR_STATE);
        const COLOUR_STATE colourState = mStateMachinePtr->getColourState();
        memcpy(mail.data, &colourState, mail.dataSize);
    } else {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: sendResponseGetCurrentColourState: %s"
            , TXT::STATEMACHINE_CTRL, "mStateMachinePtr = nullptr");
        sendLog(TXT::message);
        mail.dataSize = 0;
    }

    sendMail(mail);
}
