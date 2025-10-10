#include "TicketLeaf.h"
#include "GeneralSupport.h"
#include <iostream>
#include "TicketCommand.h"

void GeneralSupport::support(TicketLeaf *ticket)
{
    if (ticket == NULL)
        return;

    std::string type = "";
    if (ticket->getCmd() != NULL)
    {
        type = ticket->getCmd()->getType();
    }

    if (type == "General")
    {
        std::cout << "General Support is handling the ticket...\n";
        ticket->getCmd()->execute(ticket->getId(), ticket->getInfo());
    }
    else
    {
        std::cout << "General Support is passing on the ticket...\n";
        std::cout << "Ticket Unhandled\n";
    }
}
