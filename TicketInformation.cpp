#include "TicketInformation.h"

std::string TicketInformation::getId()
{
    return id;
}

void TicketInformation::setId(std::string id)
{
    this->id = id;
}

std::string TicketInformation::getInfo()
{
    return info;
}

void TicketInformation::setInfo(std::string info)
{
    this->info = info;
}

TicketInformation::TicketInformation(std::string id, std::string info)
{
    this->id = id;
    this->info = info;
}

TicketInformation::TicketInformation()
{
    id = "";
    info = "";
}