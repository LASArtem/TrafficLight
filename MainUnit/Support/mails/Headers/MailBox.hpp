#ifndef MAILBOX_HPP
#define MAILBOX_HPP

#include <queue>
using std::queue;

#include "../../common/api_mails/api_mailbox.hpp"
#include "../../common/api_mails/IMailCtrl.hpp"
#include "../../txtRecord/Headers/TxtRecord.hpp"
#include "MailOffice.hpp"
class IMailCtrl;
class MailOffice;
class TxtRecord;

class MailBox
{
public:
    static MailBox& getInstance();

    void subscribe(IMailCtrl *subscriber);
    void sendMail(MAIL &mail);
    void initMaster(MailOffice *master);
    void sendLog(const char *message) const;

private:
    MailBox();
    ~MailBox();

private:
    TxtRecord &mTxtRecord;
    MailOffice *mMaster;
};

#endif //MAILBOX_HPP
