#include "FinanceCommand.h"
#include <iostream>

FinanceCommand::FinanceCommand() : TicketCommand()
{
}

void FinanceCommand::execute(std::string id, std::string info)
{
    std::string output = "";

    output += "Finance Code: " + id + "\n";
    output += "Finance Information: " + info + "\n";

    std::cout << output;
}

std::string FinanceCommand::getType()
{
    return "Finance";
}