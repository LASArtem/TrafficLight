#include "../../common/api_txtRecord/api_txtRecord.hpp" //for names of component
#include "../Headers/MailBox.hpp"

//-----------------------------------------------------------------------------
MailBox& MailBox::getInstance()
//-----------------------------------------------------------------------------
{
    static MailBox instance;
    return instance;
}

//-----------------------------------------------------------------------------
MailBox::MailBox()
    : mTxtRecord(TxtRecord::getInstance())
    , mMaster(nullptr)
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
        , TXT::MAILBOX_APPL, TXT::NAME_MAILBOX);
    sendLog(TXT::message);
}

//-----------------------------------------------------------------------------
MailBox::~MailBox()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
        , TXT::MAILBOX_APPL, TXT::NAME_MAILBOX);
    sendLog(TXT::message);
    mMaster = nullptr;
}

//-----------------------------------------------------------------------------
void MailBox::subscribe(IMailCtrl *subscriber)
//-----------------------------------------------------------------------------
{
    if (mMaster != nullptr) {
        mMaster->pushSubscriber(subscriber);
    } else {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: subscribe: %s"
            , TXT::MAILBOX_APPL, "mMaster = nullptr");
        sendLog(TXT::message);
    }
}

//-----------------------------------------------------------------------------
void MailBox::sendMail(MAIL &mail)
//-----------------------------------------------------------------------------
{
    if (mMaster != nullptr) {
        mMaster->pushMail(mail);
    } else {
        snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: ERROR: sendMail: %s"
            , TXT::MAILBOX_APPL, "mMaster = nullptr");
        sendLog(TXT::message);
    }
}

//-----------------------------------------------------------------------------
void MailBox::initMaster(MailOffice* master)
//-----------------------------------------------------------------------------
{
    mMaster = master;
}

//-----------------------------------------------------------------------------
void MailBox::sendLog(const char *message) const
//-----------------------------------------------------------------------------
{
    mTxtRecord.sendLog(message);
}
