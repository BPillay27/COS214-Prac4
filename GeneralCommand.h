#ifndef GENERALCOMMAND_H
#define GENERALCOMMAND_H

#include "TicketCommand.h"

class GeneralCommand : public TicketCommand
{
public:
    GeneralCommand();
    void execute(std::string id, std::string info);
    std::string getType();
    ~GeneralCommand() = default;
};

#endif