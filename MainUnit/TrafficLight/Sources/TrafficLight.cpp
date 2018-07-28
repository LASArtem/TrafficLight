#include "../Headers/TrafficLight.hpp"

//-----------------------------------------------------------------------------
TrafficLight::TrafficLight()
    : mMailOffice()
    , mMailBox(MailBox::getInstance())
    , mKeyBoard()
    , mManager()
    , mStateMachine(RED)
    , mTimer()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
        , TXT::TRAFFICLIGHT_APPL, TXT::NAME_TRAFFICLIGHT);
    mMailBox.sendLog(TXT::message);
}

//-----------------------------------------------------------------------------
TrafficLight::~TrafficLight()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
        , TXT::TRAFFICLIGHT_APPL, TXT::NAME_TRAFFICLIGHT);
    mMailBox.sendLog(TXT::message);
}

//-----------------------------------------------------------------------------
void TrafficLight::execute()
//-----------------------------------------------------------------------------
{
    while(!mManager.checkExit()) {
        mKeyBoard.checkButtons();
        mMailOffice.processMails();

    }
}
