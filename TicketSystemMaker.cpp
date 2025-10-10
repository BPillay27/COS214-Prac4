#include "TicketSystemMaker.h"
#include "TicketSystem.h"
#include "TicketLeaf.h"
#include "FinanceCommand.h"
#include "TechCommand.h"
#include "GeneralCommand.h"
#include "TicketCategory.h"

void TicketSystemMaker::reset()
{
    TicketCategory *temp = new TicketCategory("root");

    if (root == NULL)
    {
        root = temp;
        return;
    }

    temp->add(root);
    root = temp;
}

void TicketSystemMaker::addCategory(std::string name)
{
    if (root == NULL)
    {
        root = new TicketCategory(name);
        return;
    }

    root->add(new TicketCategory(name));
}

void TicketSystemMaker::addFinanceTicket(std::string id, std::string info)
{
    TicketLeaf *temp = new TicketLeaf(id, info);
    temp->setCmd(new FinanceCommand());

    if (root == NULL)
    {
        root = temp;
        return;
    }

    if (currentCategory == NULL)
    {
        root->add(temp);
    }
    currentCategory->add(temp);
}

void TicketSystemMaker::addTechTicket(std::string id, std::string info)
{
    TicketLeaf *temp = new TicketLeaf(id, info);
    temp->setCmd(new TechCommand());

    if (root == NULL)
    {
        root = temp;
        return;
    }

    if (currentCategory == NULL)
    {
        root->add(temp);
    }
    currentCategory->add(temp);
}

void TicketSystemMaker::addGeneralTicket(std::string id, std::string info)
{
    TicketLeaf *temp = new TicketLeaf(id, info);
    temp->setCmd(new GeneralCommand());

    if (root == NULL)
    {
        root = temp;
        return;
    }

    if (currentCategory == NULL)
    {
        root->add(temp);
    }
    currentCategory->add(temp);
}

TicketSystem *TicketSystemMaker::getTicketSystem()
{
    return root;
}

TicketSystemMaker::TicketSystemMaker() : SystemMaker()
{
    root = NULL;
    currentCategory = NULL;
}

TicketSystemMaker::~TicketSystemMaker()
{
    if (currentCategory != NULL)
    {
        delete currentCategory;
        currentCategory = NULL;
    }

    if (root != NULL)
    {
        delete root;
        root = NULL;
    }
}