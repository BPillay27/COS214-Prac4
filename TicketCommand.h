#ifndef TICKETCOMMAND_H
#define TICKETCOMMAND_H

#include <string>

class TicketCommand
{
public:
    TicketCommand() = default;
    virtual void execute(std::string id, std::string info) = 0;
    virtual std::string getType() = 0;
    virtual ~TicketCommand() = default;
};

#endif