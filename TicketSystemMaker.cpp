#include "TicketSystemMaker.h"
#include "TicketSystem.h"
#include "TicketLeaf.h"
#include "FinanceCommand.h"
#include "TechCommand.h"
#include "GeneralCommand.h"

void TicketSystemMaker::reset()
{

}

void TicketSystemMaker::addCategory(std::string name)
{

}

void TicketSystemMaker::addFinanceTicket(std::string id, std::string info)
{
    TicketLeaf* temp=new TicketLeaf(id,info);
    temp->setCmd(new FinanceCommand());
    currentCategory->add(temp);
}

void TicketSystemMaker::addTechTicket(std::string id, std::string info)
{
    TicketLeaf* temp=new TicketLeaf(id,info);
    temp->setCmd(new TechCommand());
    currentCategory->add(temp);
}

void TicketSystemMaker::addGeneralTicket(std::string id, std::string info)
{
    TicketLeaf* temp=new TicketLeaf(id,info);
    temp->setCmd(new GeneralCommand());
    currentCategory->add(temp);
}

TicketSystem *getTicketSystem()
{
    
}

TicketSystemMaker::TicketSystemMaker()
{

}

TicketSystemMaker::~TicketSystemMaker()
{

}