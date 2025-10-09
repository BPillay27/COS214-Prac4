#ifndef TICKETLEAF_H
#define TICKETLEAF_H

#include "TicketSystem.h"
#include "TicketCommand.h"

class TicketLeaf : public TicketSystem
{
public:
    TicketLeaf(std::string id, std::string description);
    std::string getId();
    std::string getInfo();
    TicketCommand *getCmd();
    void setCmd(TicketCommand *cmd);
    void add(TicketSystem *item);
    void print();

private:
    TicketCommand *cmd;
    std::string id;
    std::string info;
};

#endif