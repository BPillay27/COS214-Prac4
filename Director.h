#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "SystemMaker.h"
#include <vector>

class SystemMaker;
class TicketInformation;
class TicketSystem;

class Director
{
public:
    Director(SystemMaker *m);
    ~Director() = default;
    TicketSystem *construct();
    std::vector<TicketInformation *> getFinanceTickets();
    void setFinanceTickets(std::vector<TicketInformation *> financeTickets);
    std::vector<TicketInformation *> getTechTickets();
    void setTechTickets(std::vector<TicketInformation *> techTickets);
    std::vector<TicketInformation *> getGeneralTickets();
    void setGeneralTickets(std::vector<TicketInformation *> generalTickets);

private:
    SystemMaker *maker;
    std::vector<TicketInformation *> financeTickets;
    std::vector<TicketInformation *> techTickets;
    std::vector<TicketInformation *> generalTickets;
};

#endif