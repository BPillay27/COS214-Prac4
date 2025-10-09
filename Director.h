#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "SystemMaker.h"
#include <vector>
#include "TicketInformation.h"
#include "TicketSystem.h"

class Director
{
public:
    Director(SystemMaker* m);
    TicketSystem* construct();
    std::vector<TicketInformation*> getFinanceTickets();
    void setFinanceTickets(std::vector<TicketInformation*> financeTickets);
    std::vector<TicketInformation*> getTechTickets();
    void setTechTickets(std::vector<TicketInformation*> techTickets);
    std::vector<TicketInformation*> getGeneralTickets();
    void setGeneralTickets(std::vector<TicketInformation*> generalTickets);

private:
    SystemMaker *maker;
    std::vector<TicketInformation *> financeTickets;
    std::vector<TicketInformation*> generalTickets;
};

#endif