#include "../../common/api_txtRecord/api_txtRecord.hpp" //for names of component
#include "../Headers/MailOffice.hpp"

//-----------------------------------------------------------------------------
MailOffice::MailOffice()
    : mMailBox(MailBox::getInstance())
    , mSubscribers()
    , mMails()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
        , TXT::MAILOFFICE_APPL, TXT::NAME_MAILOFFICE);
    mMailBox.sendLog(TXT::message);
    mMailBox.initMaster(this);
}

//-----------------------------------------------------------------------------
MailOffice::~MailOffice()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
        , TXT::MAILOFFICE_APPL, TXT::NAME_MAILOFFICE);
    mMailBox.sendLog(TXT::message);

    while (!mSubscribers.empty()) {
        mSubscribers.pop_front();
    }

    while (!mMails.empty()) {
        mMails.pop();
    }
}

//-----------------------------------------------------------------------------
void MailOffice::pushSubscriber(IMailCtrl *subscriber)
//-----------------------------------------------------------------------------
{
    if (subscriber != nullptr) {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: subscriber << %s >> was registrated"
            , TXT::MAILOFFICE_APPL, subscriber->getName());
        mMailBox.sendLog(TXT::message);
        mSubscribers.push_back(subscriber);
    }
}

//-----------------------------------------------------------------------------
void MailOffice::pushMail(MAIL &mail)
//-----------------------------------------------------------------------------
{
    mMails.push(mail);
}

//-----------------------------------------------------------------------------
void MailOffice::processMails()
//-----------------------------------------------------------------------------
{
    while (!mMails.empty()) {
        sendMailToSubscribers(mMails.front());
        mMails.pop();
    }
}

//-----------------------------------------------------------------------------
void MailOffice::sendMailToSubscribers(MAIL &mail)
//-----------------------------------------------------------------------------
{
    for (list<IMailCtrl *>::iterator it = mSubscribers.begin(); it != mSubscribers.end(); ++it) {
        (*it)->processMail(mail);
    }
}
