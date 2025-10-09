#ifndef TECHSUPPORT_H
#define TECHSUPPORT_H

#include "TicketLeaf.h"
#include "Support.h"

class GeneralSupport : public Support
{
public:
    void support(TicketLeaf *ticket);
    GeneralSupport();
};

#endif