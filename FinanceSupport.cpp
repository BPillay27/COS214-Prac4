#include "TicketLeaf.h"
#include "FinanceSupport.h"
#include "TicketCommand.h"
#include <iostream>
#include "TechCommand.h"
#include "TechSupport.h"

void FinanceSupport::support(TicketLeaf *ticket)
{
    if (ticket == NULL)
        return;
    std::string type = ticket->getCmd()->getType();

    if (type == "Finance")
    {
        std::cout << "Finance Support is handling the ticket...\n";
        ticket->getCmd()->execute(ticket->getId(), ticket->getInfo());
    }
    else
    {
        std::cout << "Finance Support is passing on the ticket...\n";
        TechSupport *temp = new TechSupport();
        setNext(temp);
        temp->support(ticket);
    }
}

FinanceSupport::FinanceSupport() : Support()
{
}