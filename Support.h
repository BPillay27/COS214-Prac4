#ifndef SUPPORT_H
#define SUPPORT_H

class TicketLeaf;

class Support
{
public:
    Support();
    void setNext(Support *next);
    virtual void support(TicketLeaf *ticket) = 0;
    virtual ~Support();

private:
    Support *next;
};

#endif