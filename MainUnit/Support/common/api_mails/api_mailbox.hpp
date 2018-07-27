#ifndef API_MAILBOX_HPP
#define API_MAILBOX_HPP

#include <cstdint> //uint32_t and other

const uint32_t MAX_DATA_SIZE = 32;

enum MAIL_ID
{
    DEFFAULT
    , KEYBOARD
    , MANAGER
    , STATEMACHINE
    , TIMER
};

enum GROUP_ID
{
    COMMAND
    , RESPONSE
};

struct MAIL
{
    MAIL_ID source;
    MAIL_ID destination;
    GROUP_ID typeMail;
    uint32_t dataType;
    uint32_t dataSize;
    uint8_t data[MAX_DATA_SIZE];
};

#endif //API_MAILBOX_HPP
