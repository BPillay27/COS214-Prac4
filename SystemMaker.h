#ifndef SYSTEMMAKER_H
#define SYSTEMMAKER_H

#include <string>

class SystemMaker
{
public:
    void reset();
    void addCategory(std::string name);
    void addFinanceTicket(std::string id, std::string info);
    void addTechTicket(std::string id, std::string info);
    void addGeneral(std::string id, std::string info);
};

#endif;