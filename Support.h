#ifndef SUPPORT_H
#define SUPPORT_H

#include "TicketLeaf.h"

class Support
{
public:
    Support();
    void setNext(Support *next);
    virtual void support(TicketLeaf *ticket) = 0;

private:
    Support *next;
};

#endif