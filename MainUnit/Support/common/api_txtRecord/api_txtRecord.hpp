#ifndef API_TXTRECORD_HPP
#define API_TXTRECORD_HPP

#include <cstdint> //uint32_t and other

namespace TXT {
const uint8_t BUFFER_SIZE = 127;
static char message[TXT::BUFFER_SIZE] = {};

const char *const NAME_TRAFFICLIGHT      = "TrafficLight";
const char *const NAME_MAILBOX           = "Mailbox";
const char *const NAME_MAILOFFICE        = "MailOffice";
const char *const NAME_TXTRECORD         = "TxtRecord";
const char *const NAME_KEYBOARD          = "Keyboard";
const char *const NAME_MANAGER           = "Manager";
const char *const NAME_STATEMACHINE      = "StateMachine";
const char *const NAME_TIMER             = "Timer";

const char *const NAME_KEYBOARD_CTRL     = "Keyboard-CTRL";
const char *const NAME_MANAGER_CTRL      = "Manager-CTRL";
const char *const NAME_STATEMACHINE_CTRL = "StateMachine-CTRL";
const char *const NAME_TIMER_CTRL        = "Timer-CTRL";

const char *const TRAFFICLIGHT_APPL      = "[TrafficLight-appl]";
const char *const KEYBOARD_APPL          = "[    Keyboard-appl]";
const char *const STATEMACHINE_APPL      = "[StateMachine-appl]";
const char *const MANAGER_APPL           = "[     Manager-appl]";
const char *const TIMER_APPL             = "[       Timer-appl]";
const char *const MAILOFFICE_APPL        = "[  MailOffice-appl]";
const char *const HMI_APPL               = "[         Hmi-appl]";
const char *const TXTRECORD_APPL         = "[   TXTRecord-appl]";
const char *const MAILBOX_APPL           = "[     MailBox-appl]";

const char *const KEYBOARD_CTRL          = "[    Keyboard-CTLR]";
const char *const STATEMACHINE_CTRL      = "[StateMachine-CTLR]";
const char *const MANAGER_CTRL           = "[     Manager-CTLR]";
const char *const TIMER_CTRL             = "[       Timer-CTLR]";
const char *const HMI_CTRL               = "[         Hmi-CTLR]";
}

#endif //API_TXTRECORD_HPP
