#include <stdio.h> //printf
#include <fstream> //ofstream
#include <ctime>   //for getFileName

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
    : mFileNamePtr(nullptr)
//-----------------------------------------------------------------------------
{
    mFileNamePtr = getFileName();
    snprintf(TXT::message, TXT::BUFFER_SIZE, "%s: constructor of << %s >>"
        , TXT::TXTRECORD_APPL, getName());
    sendLog(TXT::message);
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
    Log.open(mFileNamePtr, std::ios_base::app);
    Log << message << "\n";
    Log.close();
}

//-----------------------------------------------------------------------------
const char *TxtRecord::getFileName()
//-----------------------------------------------------------------------------
{
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    timeinfo->tm_mday;
    static char fileName[TXT::BUFFER_SIZE] = {};
    snprintf(fileName, TXT::BUFFER_SIZE, "Logs Data = %02d.%02d.%04d; Time = %02d.%02d.%02d.txt"
        , timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year+1900
        , timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    sendLog(fileName);
    return fileName;
}
