#ifndef TICKETSYSTEMMAKER_H
#define TICKETSYSTEMMAKER_H

#include "SystemMaker.h"
#include "TicketSystem.h"
class TicketSystemMaker : public SystemMaker
{
public:
    void reset();
    void addCategory(std::string name);
    void addFinanceTicket(std::string id, std::string info);
    void addTechTicket(std::string id, std::string info);
    void addGeneralTicket(std::string id, std::string info);
    TicketSystem *getTicketSystem();
    TicketSystemMaker();
    ~TicketSystemMaker();

private:
    TicketSystem *root;
    TicketSystem *currentCategory;
};

#endif