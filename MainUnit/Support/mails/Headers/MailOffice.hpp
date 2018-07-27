#ifndef MAILOFFICE_HPP
#define MAILOFFICE_HPP

#include <queue>
using std::queue;
#include <list>
using std::list;

#include "../../common/api_mails/api_mailbox.hpp"
#include "../../common/api_mails/IMailCtrl.hpp"
#include "MailBox.hpp"

class IMailCtrl;
class MailBox;

class MailOffice
{
public:
    MailOffice();
    ~MailOffice();

    void pushSubscriber(IMailCtrl *subscriber);
    void pushMail(MAIL &mail);
    void processMails();

private:
    void sendMailToSubscribers(MAIL &mail);

private:
    MailBox &mMailBox;
    list<IMailCtrl *> mSubscribers;
    queue<MAIL> mMails;
};

#endif //MAILOFFICE_HPP
