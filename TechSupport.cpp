#include "TechSupport.h"
#include "TicketLeaf.h"
#include "TicketCommand.h"
#include "GeneralSupport.h"
#include <iostream>

void TechSupport::support(TicketLeaf *ticket)
{
    if (ticket == NULL)
        return;

    std::string type = "";
    if (ticket->getCmd() != NULL)
    {
        type = ticket->getCmd()->getType();
    }

    if (type == "Tech")
    {
        std::cout << "Tech Support is handling the ticket...\n";
        ticket->getCmd()->execute(ticket->getId(), ticket->getInfo());
    }
    else
    {
        std::cout << "Tech Support is passing on the ticket...\n";
        GeneralSupport *temp = new GeneralSupport();
        setNext(temp);
        temp->support(ticket);
    }
}

TechSupport::TechSupport() : Support()
{
}