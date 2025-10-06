#ifndef TICKETINFORMATION_H
#define TICKETINFORMATION_H

#include <string>

class TicketInformation
{
public:
    std::string getId();
    void setId(std::string id);
    std::string getInfo();
    void setInfo(std::string info);
    TicketInformation(std::string id, std::string info);
    TicketInformation();

private:
    std::string id;
    std::string info;
};

#endif