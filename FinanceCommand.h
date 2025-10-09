#ifndef FINANCECOMMAND_H
#define FINANCECOMMAND_H

#include "TicketCommand.h"

class FinanceCommand : public TicketCommand
{
public:
    FinanceCommand();
    void execute(std::string id, std::string info);
    std::string getType();
    ~FinanceCommand() = default;
};

#endif