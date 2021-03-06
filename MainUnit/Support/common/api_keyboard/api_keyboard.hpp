#ifndef API_KEYBOARD_HPP
#define API_KEYBOARD_HPP

enum COMMAND_KEYBOARD_ID
{
    COMMAND_START_STATEMACHINE
    , COMMAND_PAUSE_STATEMACHINE
    , COMMAND_CHANGE_COLOUR_STATE
    , COMMAND_GET_CURRENT_COLOUR_STATE
};

enum RESPONSE_KEYBOARD_ID
{
    RESPONSE_START_STATEMACHINE
    , RESPONSE_PAUSE_STATEMACHINE
    , RESPONSE_CHANGE_COLOUR_STATE
    , RESPONSE_GET_CURRENT_COLOUR_STATE
};

#endif //API_KEYBOARD_HPP
