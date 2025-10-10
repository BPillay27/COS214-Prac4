#include "TicketInformation.h"
#include "SystemMaker.h"
#include "TicketSystem.h"
#include "Director.h"

Director::Director(SystemMaker *m)
{
    maker = m;
}

Director::~Director()
{
    if (maker != NULL)
    {
        delete maker;
        maker = NULL;
    }
}

TicketSystem *Director::construct()
{
    maker->reset();

    if (!financeTickets.empty())
    {
        maker->addCategory("Finance");

        for (TicketInformation *t : financeTickets)
        {
            maker->addFinanceTicket(t->getId(), t->getInfo());
        }
    }

    if(!techTickets.empty()){
        maker->addCategory("Tech");

        for(TicketInformation *t :techTickets){
            maker->addTechTicket(t->getId(), t->getInfo());
        }
    }

    if(!generalTickets.empty()){
        maker->addCategory("General");

        for(TicketInformation *t :techTickets){
            maker->addGeneralTicket(t->getId(), t->getInfo());
        }
    }
}

std::vector<TicketInformation *> Director::getFinanceTickets()
{
    return financeTickets;
}

void Director::setFinanceTickets(std::vector<TicketInformation *> financeTickets)
{
    this->financeTickets=financeTickets;
}

std::vector<TicketInformation *> Director::getTechTickets()
{
    return techTickets;
}

void Director::setTechTickets(std::vector<TicketInformation *> techTickets)
{
    this->techTickets=techTickets;
}

std::vector<TicketInformation *> Director::getGeneralTickets()
{
    return generalTickets;
}

void Director::setGeneralTickets(std::vector<TicketInformation *> generalTickets)
{
    this->generalTickets=generalTickets;
}