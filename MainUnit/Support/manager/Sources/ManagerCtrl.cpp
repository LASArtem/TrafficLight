#include <cstring>// memcpy

#include "../Headers/ManagerCtrl.hpp"
#include "../../common/api_manager/api_manager.hpp"
#include "../../common/api_stateMachine/api_stateMachine.hpp"
#include "../../common/api_timer/api_timer.hpp"

//-----------------------------------------------------------------------------
ManagerCtrl::ManagerCtrl(Manager *tPtr)
    : IMailCtrl()
    , mManagerPtr(tPtr)
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
        , TXT::MANAGER_CTRL, TXT::NAME_MANAGER_CTRL);
    sendLog(TXT::message);
    registration(this);
}

//-----------------------------------------------------------------------------
ManagerCtrl::~ManagerCtrl()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
        , TXT::MANAGER_CTRL, TXT::NAME_MANAGER_CTRL);
    sendLog(TXT::message);
}

//-----------------------------------------------------------------------------
const char *ManagerCtrl::getName()
//-----------------------------------------------------------------------------
{
    if (mManagerPtr != nullptr) {
        return mManagerPtr->getName();
    } else {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: getName: %s"
            , TXT::MANAGER_CTRL, "mManagerPtr = nullptr");
        sendLog(TXT::message);
        return "default Name: manager";
    }
}

//-----------------------------------------------------------------------------
void ManagerCtrl::processMail(MAIL &mail)
//-----------------------------------------------------------------------------
{
    if (mail.destination != MANAGER) {
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
void ManagerCtrl::parseCommand(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.source) {
    case KEYBOARD:
        parseCommandFromKeyBoard(mail);
        break;

    case STATEMACHINE:
        parseCommandFromStateMachine(mail);
        break;

    case TIMER:
        parseCommandFromTimer(mail);
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void ManagerCtrl::parseResponse(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.source) {
    case KEYBOARD:
        parseResponseFromKeyBoard(mail);
        break;

    case STATEMACHINE:
        parseResponseFromStateMachine(mail);
        break;

    case TIMER:
        parseResponseFromTimer(mail);
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void ManagerCtrl::parseCommandFromKeyBoard(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    case COMMAND_USER_PRESS_EXIT:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommandFromKeyBoard: %s"
            , TXT::MANAGER_CTRL, "COMMAND_USER_PRESS_EXIT");
        sendLog(TXT::message);
        processCommandUserPressExit();
        break;
    case COMMAND_USER_PRESS_START:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommandFromKeyBoard: %s"
            , TXT::MANAGER_CTRL, "COMMAND_USER_PRESS_START");
        sendLog(TXT::message);
        processCommandUserPressStart();
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void ManagerCtrl::parseCommandFromStateMachine(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    case COMMAND_COUNT_TIME_IS_FINISHED:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommandFromStateMachine: %s"
            , TXT::MANAGER_CTRL, "COMMAND_COUNT_TIME_IS_FINISHED");
        sendLog(TXT::message);
        sendResponseCountTimeIsFinished();
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void ManagerCtrl::parseCommandFromTimer(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    case COMMAND_COUNT_TIME_IS_FINISHED:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommandFromTimer: %s"
            , TXT::MANAGER_CTRL, "COMMAND_COUNT_TIME_IS_FINISHED");
        sendLog(TXT::message);
        sendResponseCountTimeIsFinished();
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void ManagerCtrl::parseResponseFromKeyBoard(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    case RESPONSE_START_STATEMACHINE:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseResponseFromStateMachine: %s"
            , TXT::MANAGER_CTRL, "RESPONSE_START_STATEMACHINE");
        sendLog(TXT::message);
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void ManagerCtrl::parseResponseFromStateMachine(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    case RESPONSE_START_STATEMACHINE:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseResponseFromStateMachine: %s"
            , TXT::MANAGER_CTRL, "RESPONSE_START_STATEMACHINE");
        sendLog(TXT::message);
        break;

    case RESPONSE_PAUSE_STATEMACHINE:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseResponseFromStateMachine: %s"
            , TXT::MANAGER_CTRL, "RESPONSE_PAUSE_STATEMACHINE");
        sendLog(TXT::message);
        break;

    case RESPONSE_CHANGE_COLOUR_STATE:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseResponseFromStateMachine: %s"
            , TXT::MANAGER_CTRL, "RESPONSE_CHANGE_COLOUR_STATE");
        sendLog(TXT::message);
        break;

    case RESPONSE_GET_CURRENT_COLOUR_STATE:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseResponseFromStateMachine: %s"
            , TXT::MANAGER_CTRL, "RESPONSE_GET_CURRENT_COLOUR_STATE");
        sendLog(TXT::message);
        processResponseGetCurrentColorState(mail);
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void ManagerCtrl::parseResponseFromTimer(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    case RESPONSE_GET_CURRENT_TIME:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseResponseFromTimer: %s"
            , TXT::MANAGER_CTRL, "RESPONSE_GET_CURRENT_TIME");
        sendLog(TXT::message);
        break;

    case RESPONSE_START_COUNT_TIME:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseResponseFromTimer: %s"
            , TXT::MANAGER_CTRL, "RESPONSE_START_COUNT_TIME");
        sendLog(TXT::message);
        break;

    case RESPONSE_PAUSE_COUNT_TIME:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseResponseFromTimer: %s"
            , TXT::MANAGER_CTRL, "RESPONSE_PAUSE_COUNT_TIME");
        sendLog(TXT::message);
        break;

    case RESPONSE_CONTINUE_COUNT_TIME:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseResponseFromTimer: %s"
            , TXT::MANAGER_CTRL, "RESPONSE_CONTINUE_COUNT_TIME");
        sendLog(TXT::message);
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void ManagerCtrl::sendCommandStartStateMachine()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandStartStateMachine", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = MANAGER;
    mail.destination = STATEMACHINE;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_START_STATEMACHINE);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void ManagerCtrl::sendCommandPauseStateMachine()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandPauseStateMachine", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = MANAGER;
    mail.destination = STATEMACHINE;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_PAUSE_STATEMACHINE);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void ManagerCtrl::sendCommandChangeColourState()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandChangeColourState", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = MANAGER;
    mail.destination = STATEMACHINE;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_CHANGE_COLOUR_STATE);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void ManagerCtrl::sendCommandGetCurrentColourState()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandGetCurrentColourState", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = MANAGER;
    mail.destination = STATEMACHINE;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_GET_CURRENT_COLOUR_STATE);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void ManagerCtrl::sendCommandGetCurrentTime()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandGetCurrentTime", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = MANAGER;
    mail.destination = TIMER;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_GET_CURRENT_TIME);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void ManagerCtrl::sendCommandStartCountTime(uint32_t sec)
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandStartCountTime", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = MANAGER;
    mail.destination = TIMER;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_START_COUNT_TIME);
    mail.dataSize = sizeof(uint32_t);
    memcpy(mail.data, &sec, sizeof(uint32_t));

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void ManagerCtrl::sendCommandPauseCountTime()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandPauseCountTime", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = MANAGER;
    mail.destination = TIMER;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_PAUSE_COUNT_TIME);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void ManagerCtrl::sendCommandContinueCountTime()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendCommandContinueCountTime", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = MANAGER;
    mail.destination = TIMER;
    mail.typeMail = COMMAND;
    mail.dataType = static_cast<uint32_t>(COMMAND_CONTINUE_COUNT_TIME);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void ManagerCtrl::sendResponseCountTimeIsFinished()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendResponseCountTimeIsFinished", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = MANAGER;
    mail.destination = TIMER;
    mail.typeMail = RESPONSE;
    mail.dataType = static_cast<uint32_t>(RESPONSE_COUNT_TIME_IS_FINISHED);
    mail.dataSize = 0;

    sendMail(mail);
}


//-----------------------------------------------------------------------------
void ManagerCtrl::processCommandUserPressExit()
//-----------------------------------------------------------------------------
{
    if (mManagerPtr == nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: processCommandUserPressExit: %s"
            , TXT::MANAGER_CTRL, "mManagerPtr = nullptr");
        sendLog(TXT::message);
        return;
    }

    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: processCommandUserPressExit", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    mManagerPtr->notifyUserPressExit();
}


//-----------------------------------------------------------------------------
void ManagerCtrl::processCommandUserPressStart()
//-----------------------------------------------------------------------------
{
    if (mManagerPtr == nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: processCommandUserPressStart: %s"
            , TXT::MANAGER_CTRL, "mManagerPtr = nullptr");
        sendLog(TXT::message);
        return;
    }

    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: processCommandUserPressStart", TXT::MANAGER_CTRL);
    sendLog(TXT::message);

    mManagerPtr->notifyUserPressStart();
}


//-----------------------------------------------------------------------------
void ManagerCtrl::processResponseGetCurrentColorState(MAIL &mail)
//-----------------------------------------------------------------------------
{
    if (mail.dataSize != sizeof(COLOUR_STATE)) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: processResponseGetCurrentColorState: %s"
            , TXT::MANAGER_CTRL, "wrong dataSize");
        sendLog(TXT::message);
        return;
    }

    COLOUR_STATE currentColourState;
    memcpy(&currentColourState, mail.data, sizeof(COLOUR_STATE));
    if (mManagerPtr != nullptr) {
        mManagerPtr->notifyGetCurrentColourState(static_cast<uint32_t>(currentColourState));
    } else {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: processResponseGetCurrentColorState: %s"
            , TXT::MANAGER_CTRL, "mManagerPtr != nullptr");
        sendLog(TXT::message);
    }
}
