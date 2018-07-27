#ifndef IMAILCTRL_HPP
#define IMAILCTRL_HPP

#include "../../mails/Headers/MailBox.hpp"
#include "../api_txtRecord/api_txtRecord.hpp" //for names of component

class MailBox;

class IMailCtrl
{
public:
    IMailCtrl();
    virtual ~IMailCtrl();

    virtual const char *getName() = 0;
    virtual void processMail(MAIL &mail) = 0;

    void sendLog(const char *message);
protected:
    void registration(IMailCtrl *owner);
    void sendMail(MAIL &mail);


private:
    MailBox &mMailBox;
};

#endif //IMAILCTRL_HPP
