#include "TicketCategory.h"
#include <iostream>

TicketCategory::TicketCategory(std::string name) : TicketSystem()
{
    this->name = name;
}

std::string TicketCategory::getName()
{
    return name;
}

void TicketCategory::setName(std::string name)
{
    this->name = name;
}

void TicketCategory::add(TicketSystem *item)
{
    if (item == NULL)
        return;

    for (TicketSystem *t : children)
    {
        if (t == item)
        {
            return;
        }
    }

    children.push_back(item);
}

void TicketCategory::print()
{
    std::cout << "[" + name + ": (";

    for (TicketSystem *t : children)
    {
        t->print();

        if (t != children.back())
        {
            std::cout << ",";
        }
        else
        {
            std::cout << ")]";
            return;
        }
    }
}

TicketCategory::~TicketCategory()
{
    for (TicketSystem *t : children)
    {
        delete t;
    }

    children.clear();
}