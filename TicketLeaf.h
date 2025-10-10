#ifndef TICKETLEAF_H
#define TICKETLEAF_H

#include <string>
#include "TicketSystem.h"
class TicketCommand;

class TicketLeaf : public TicketSystem
{
public:
    TicketLeaf(std::string id, std::string info);
    std::string getId();
    std::string getInfo();
    TicketCommand *getCmd();
    void setCmd(TicketCommand *cmd);
    void add(TicketSystem *item);
    void print();
    ~TicketLeaf();

private:
    TicketCommand *cmd;
    std::string id;
    std::string info;
};

#endif