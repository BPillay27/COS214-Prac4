#ifndef TICKETSYSTEM_H
#define TICKETSYSTEM_H

class TicketSystem
{
public:
    virtual void print() = 0;
    virtual void add(TicketSystem *item) = 0;
    TicketSystem() = default;
    virtual ~TicketSystem() = default;
};

#endif