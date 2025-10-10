#include "TicketInformation.h"
#include "SystemMaker.h"
#include "TicketSystem.h"
#include "Director.h"
#include "TicketSystemMaker.h"

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

    for (TicketInformation *t : financeTickets)
    {
        delete t;
    }

    for (TicketInformation *t : generalTickets)
    {
        delete t;
    }

    for (TicketInformation *t : techTickets)
    {
        delete t;
    }
}

TicketSystem *Director::construct()
{
    TicketSystemMaker *m = new TicketSystemMaker();

    if (!financeTickets.empty())
    {
        m->addCategory("Finance");

        for (TicketInformation *t : financeTickets)
        {
            m->addFinanceTicket(t->getId(), t->getInfo());
        }
    }

    if (!techTickets.empty())
    {
        m->addCategory("Tech");

        for (TicketInformation *t : techTickets)
        {
            m->addTechTicket(t->getId(), t->getInfo());
        }
    }

    if (!generalTickets.empty())
    {
        m->addCategory("General");

        for (TicketInformation *t : techTickets)
        {
            m->addGeneralTicket(t->getId(), t->getInfo());
        }
    }

    return m->getTicketSystem();
}

std::vector<TicketInformation *> Director::getFinanceTickets()
{
    return financeTickets;
}

void Director::setFinanceTickets(std::vector<TicketInformation *> financeTickets)
{
    this->financeTickets = financeTickets;
}

std::vector<TicketInformation *> Director::getTechTickets()
{
    return techTickets;
}

void Director::setTechTickets(std::vector<TicketInformation *> techTickets)
{
    this->techTickets = techTickets;
}

std::vector<TicketInformation *> Director::getGeneralTickets()
{
    return generalTickets;
}

void Director::setGeneralTickets(std::vector<TicketInformation *> generalTickets)
{
    this->generalTickets = generalTickets;
}