#include <stdio.h> //printf

#include "../../common/api_timer/api_timer.hpp"
#include "../Headers/TimerCtrl.hpp"

//-----------------------------------------------------------------------------
TimerCtrl::TimerCtrl(Timer *tPtr)
    : IMailCtrl()
    , mTimerPtr(tPtr)
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
        , TXT::TIMER_CTRL, TXT::NAME_TIMER_CTRL);
    sendLog(TXT::message);
    registration(this);
}

//-----------------------------------------------------------------------------
TimerCtrl::~TimerCtrl()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
        , TXT::TIMER_CTRL, TXT::NAME_TIMER_CTRL);
    sendLog(TXT::message);
}

//-----------------------------------------------------------------------------
const char *TimerCtrl::getName()
//-----------------------------------------------------------------------------
{
    if (mTimerPtr != nullptr) {
        return mTimerPtr->getName();
    } else {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: getName: %s"
            , TXT::TIMER_CTRL, "mTimerPtr = nullptr");
        sendLog(TXT::message);
        return "default Name: timer";
    }
}

//-----------------------------------------------------------------------------
void TimerCtrl::processMail(MAIL &mail)
//-----------------------------------------------------------------------------
{
    if (mail.destination != TIMER) {
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
void TimerCtrl::parseCommand(MAIL &mail)
//-----------------------------------------------------------------------------
{
    switch (mail.dataType){
    case COMMAND_GET_CURRENT_TIME:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommand: %s"
            , TXT::TIMER_CTRL, "COMMAND_GET_CURRENT_TIME");
        sendLog(TXT::message);
        sendResponseGetCurrentTime();
        break;

    case COMMAND_START_COUNT_TIME:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommand: %s"
            , TXT::TIMER_CTRL, "COMMAND_START_COUNT_TIME");
        sendLog(TXT::message);
        sendResponseStartCountTime();
        processCommandStartCountTime(mail);
        break;

    case COMMAND_PAUSE_COUNT_TIME:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommand: %s"
            , TXT::TIMER_CTRL, "COMMAND_PAUSE_COUNT_TIME");
        sendLog(TXT::message);
        sendResponsePauseCountTime();
        break;

    case COMMAND_CONTINUE_COUNT_TIME:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: parseCommand: %s"
            , TXT::TIMER_CTRL, "COMMAND_CONTINUE_COUNT_TIME");
        sendLog(TXT::message);
        sendResponseCountinueCountTime();
        break;

    default:
        break;
    }
}

//-----------------------------------------------------------------------------
void TimerCtrl::parseResponse(MAIL &mail)
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
void TimerCtrl::sendResponseGetCurrentTime()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendResponseGetCurrentTime", TXT::TIMER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = TIMER;
    mail.destination = MANAGER;
    mail.typeMail = RESPONSE;
    mail.dataType = static_cast<uint32_t>(RESPONSE_GET_CURRENT_TIME);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void TimerCtrl::sendResponseStartCountTime()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendResponseStartCountTime", TXT::TIMER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = TIMER;
    mail.destination = MANAGER;
    mail.typeMail = RESPONSE;
    mail.dataType = static_cast<uint32_t>(RESPONSE_START_COUNT_TIME);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void TimerCtrl::sendResponsePauseCountTime()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendResponsePauseCountTime", TXT::TIMER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = TIMER;
    mail.destination = MANAGER;
    mail.typeMail = RESPONSE;
    mail.dataType = static_cast<uint32_t>(RESPONSE_PAUSE_COUNT_TIME);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void TimerCtrl::sendResponseCountinueCountTime()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: sendResponseCountinueCountTime", TXT::TIMER_CTRL);
    sendLog(TXT::message);

    MAIL mail = {};
    mail.source = TIMER;
    mail.destination = MANAGER;
    mail.typeMail = RESPONSE;
    mail.dataType = static_cast<uint32_t>(RESPONSE_CONTINUE_COUNT_TIME);
    mail.dataSize = 0;

    sendMail(mail);
}

//-----------------------------------------------------------------------------
void TimerCtrl::processCommandStartCountTime(MAIL &mail)
//-----------------------------------------------------------------------------
{
    if (mail.dataSize != sizeof(uint32_t)) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: processCommandStartCountTime: %s"
            , TXT::TIMER_CTRL, "wrong dataSize");
        sendLog(TXT::message);
        return;
    }

    uint32_t seconds;
    memcpy(&seconds, mail.data, sizeof(uint32_t));
    if (mTimerPtr != nullptr) {
        mTimerPtr->notifyStartCountTime(seconds);
    } else {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: processCommandStartCountTime: %s"
            , TXT::TIMER_CTRL, "mTimerPtr != nullptr");
        sendLog(TXT::message);
    }
}
