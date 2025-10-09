#include "GeneralCommand.h"
#include <iostream>

GeneralCommand::GeneralCommand() : TicketCommand()
{
}

void GeneralCommand::execute(std::string id, std::string info)
{
    std::string output = "";

    output += "General Number: " + id + "\n";
    output += "General Information: " + info + "\n";

    std::cout << output;
}

std::string GeneralCommand::getType()
{
    return "General";
}