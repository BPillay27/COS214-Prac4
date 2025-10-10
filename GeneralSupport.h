#ifndef GENERALSUPPORT_H
#define GENERALSUPPORT_H

#include "Support.h"

class GeneralSupport : public Support
{
public:
    void support(TicketLeaf *ticket);
    GeneralSupport();
};

#endif