#ifndef TECHCOMMAND_H
#define TECHCOMMAND_H

#include "TicketCommand.h"

class TechCommand : public TicketCommand
{
public:
    TechCommand();
    void execute(std::string id, std::string info);
    std::string getType();
};

#endif