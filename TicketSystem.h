#ifndef TICKETSYSTEM_H
#define TICKETSYSTEM_H

class TicketSystem
{
public:
    void print();
    void add(TicketSystem *item);
    TicketSystem() = default;
    virtual ~TicketSystem() = default;
};

#endif