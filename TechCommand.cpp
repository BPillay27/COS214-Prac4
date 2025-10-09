#include "TechCommand.h"
#include <iostream>

TechCommand::TechCommand() : TicketCommand()
{
}

void TechCommand::execute(std::string id, std::string info)
{
    std::string output = "";

    output += "Tech Issue: " + id + "\n";
    output += "Tech Information: " + info + "\n";

    std::cout << output;
}

std::string TechCommand::getType()
{
    return "Tech";
}