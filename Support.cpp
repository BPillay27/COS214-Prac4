#include "TicketLeaf.h"
#include "Support.h"

void Support::setNext(Support *next)
{
    this->next = next;
}

Support::~Support()
{
    if (next !=NULL)
    {
        delete next;
        next = NULL;
    }
}