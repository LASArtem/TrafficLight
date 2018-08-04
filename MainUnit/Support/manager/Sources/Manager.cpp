#include "../../common/api_stateMachine/api_stateMachine.hpp"
#include "../Headers/Manager.hpp"

//-----------------------------------------------------------------------------
Manager::Manager()
    : mCtlrPtr(new ManagerCtrl(this))
    , mIsExit(false)
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
            , TXT::MANAGER_APPL, getName());
        mCtlrPtr->sendLog(TXT::message);
    }
}

//-----------------------------------------------------------------------------
Manager::~Manager()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
            , TXT::MANAGER_APPL, getName());
        mCtlrPtr->sendLog(TXT::message);
    }

    delete mCtlrPtr;
}

//-----------------------------------------------------------------------------
const char *Manager::getName()
//-----------------------------------------------------------------------------
{
    return TXT::NAME_MANAGER;
}

//-----------------------------------------------------------------------------
bool Manager::checkExit()
//-----------------------------------------------------------------------------
{
    return mIsExit;
}

//-----------------------------------------------------------------------------
void Manager::sendCommandStartStateMachine()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandStartStateMachine();
    }
}

//-----------------------------------------------------------------------------
void Manager::sendCommandPauseStateMachine()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandPauseStateMachine();
    }
}

//-----------------------------------------------------------------------------
void Manager::sendCommandChangeColourState()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandChangeColourState();
    }
}

//-----------------------------------------------------------------------------
void Manager::sendCommandGetCurrentColourState()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandGetCurrentColourState();
    }
}

//-----------------------------------------------------------------------------
void Manager::sendCommandGetCurrentTime()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandGetCurrentTime();
    }
}

//-----------------------------------------------------------------------------
void Manager::sendCommandStartCountTime()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandStartCountTime(3/*seconds*/);
    }
}

//-----------------------------------------------------------------------------
void Manager::sendCommandPauseCountTime()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandPauseCountTime();
    }
}

//-----------------------------------------------------------------------------
void Manager::sendCommandContinueCountTime()
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr != nullptr) {
        mCtlrPtr->sendCommandContinueCountTime();
    }
}

//-----------------------------------------------------------------------------
void Manager::notifyGetCurrentColourState(uint32_t colour)
//-----------------------------------------------------------------------------
{
    if (mCtlrPtr == nullptr) {
        return;
    }

    switch (colour){
    case RED:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: notifyGetCurrentColourState: RED", TXT::MANAGER_APPL);
        mCtlrPtr->sendLog(TXT::message);
        break;

    case YELLOW_TO_RED:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: notifyGetCurrentColourState: YELLOW_TO_RED", TXT::MANAGER_APPL);
        mCtlrPtr->sendLog(TXT::message);
        break;

    case YELLOW_TO_GREEN:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: notifyGetCurrentColourState: YELLOW_TO_GREEN", TXT::MANAGER_APPL);
        mCtlrPtr->sendLog(TXT::message);
        break;

    case GREEN:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: notifyGetCurrentColourState: GREEN", TXT::MANAGER_APPL);
        mCtlrPtr->sendLog(TXT::message);
        break;

    default:
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: notifyGetCurrentColourState: %d"
            , TXT::MANAGER_APPL, colour);
        mCtlrPtr->sendLog(TXT::message);
        break;
    }
}

//-----------------------------------------------------------------------------
void Manager::notifyUserPressExit()
//-----------------------------------------------------------------------------
{
    mIsExit = true;
}

//-----------------------------------------------------------------------------
void Manager::notifyUserPressStart()
//-----------------------------------------------------------------------------
{
    sendCommandStartCountTime();
}

//-----------------------------------------------------------------------------
void Manager::notifyUserPressPause()
//-----------------------------------------------------------------------------
{

}



