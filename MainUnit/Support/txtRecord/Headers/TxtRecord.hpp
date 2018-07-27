#ifndef TXTRECORD_HPP
#define TXTRECORD_HPP

#include <cstdio> // for snprintf

class TxtRecord
{
public:
    static TxtRecord& getInstance();

    const char *getName() const;
    void sendLog(const char *message) const;

private:
    TxtRecord();
    ~TxtRecord();
};

#endif //TXTRECORD_HPP
