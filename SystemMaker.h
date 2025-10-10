#ifndef SYSTEMMAKER_H
#define SYSTEMMAKER_H

#include <string>

class SystemMaker
{
public:
    virtual void reset() = 0;
    virtual void addCategory(std::string name) = 0;
    virtual void addFinanceTicket(std::string id, std::string info) = 0;
    virtual void addTechTicket(std::string id, std::string info) = 0;
    virtual void addGeneralTicket(std::string id, std::string info) = 0;
    SystemMaker() = default;
    virtual ~SystemMaker() = default;
};

#endif;