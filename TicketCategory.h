#ifndef TICKETCATEGORY_H
#define TICKETCATEGORY_H

#include "TicketSystem.h"
#include <string>
#include <vector>

class TicketCategory : public TicketSystem
{
public:
    TicketCategory(std::string name);
    std::string getName();
    void setName(std::string name);
    void add(TicketSystem *item);
    void print();
    ~TicketCategory();

private:
    std::string name;
    std::vector<TicketSystem *> children;
};

#endif