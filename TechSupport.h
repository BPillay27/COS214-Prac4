#ifndef TECHSUPPORT_H
#define TECHSUPPORT_H

#include "Support.h"

class TechSupport : public Support
{
public:
    void support(TicketLeaf *ticket);
    TechSupport();
};

#endif