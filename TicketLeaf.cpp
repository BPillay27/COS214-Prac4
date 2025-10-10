#include "TicketCommand.h"
#include "TicketLeaf.h"
#include <iostream>

TicketLeaf::TicketLeaf(std::string id, std::string info) : TicketSystem()
{
    this->id = id;
    this->info = info;
    cmd = NULL;
}

std::string TicketLeaf::getId()
{
    return id;
}

std::string TicketLeaf::getInfo()
{
    return info;
}

TicketCommand *TicketLeaf::getCmd()
{
    return cmd;
}

void TicketLeaf::setCmd(TicketCommand *cmd)
{
    this->cmd = cmd;
}

void TicketLeaf::add(TicketSystem *item)
{
}

void TicketLeaf::print()
{
    std::cout << id + " - " + info;
}

TicketLeaf::~TicketLeaf()
{
    if (cmd != NULL)
    {
        delete cmd;
        cmd=NULL;
    }
}
