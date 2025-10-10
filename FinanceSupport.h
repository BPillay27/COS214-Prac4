#ifndef FINANCESUPPORT_H
#define FINANCESUPPORT_H

#include "Support.h"

class FinanceSupport : public Support
{
public:
    void support(TicketLeaf *ticket);
    FinanceSupport();
};

#endif