#include <stdio.h> //printf
#include <fstream>//ofstream
#include<iostream>

#include "../../common/api_txtRecord/api_txtRecord.hpp" //for names of component
#include "../Headers/TxtRecord.hpp"

//-----------------------------------------------------------------------------
TxtRecord& TxtRecord::getInstance()
//-----------------------------------------------------------------------------
{
    static TxtRecord instance;
    return instance;
}

//-----------------------------------------------------------------------------
TxtRecord::TxtRecord()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
        , TXT::TXTRECORD_APPL, getName());
    sendLog(TXT::message);

    std::ofstream Log;
    Log.open("Log.txt",std::ios_base::trunc);
    Log.close();
}

//-----------------------------------------------------------------------------
TxtRecord::~TxtRecord()
//-----------------------------------------------------------------------------
{
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s:  destructor of << %s >>"
        , TXT::TXTRECORD_APPL, getName());
    sendLog(TXT::message);
}

//-----------------------------------------------------------------------------
const char *TxtRecord::getName() const
//-----------------------------------------------------------------------------
{
    return TXT::NAME_TXTRECORD;
}

//-----------------------------------------------------------------------------
void TxtRecord::sendLog(const char *message) const
//-----------------------------------------------------------------------------
{
    printf("%s\n", message);

    std::ofstream Log;
    Log.open("Log.txt",std::ofstream::app);
    //Log.write(message,TXT::BUFFER_SIZE);

    Log << std::cout << std::endl<< message;


}
