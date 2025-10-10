#include "TicketInformation.h"  //tested

#include "TicketCommand.h"      //tested
#include "FinanceCommand.h"     //tested
#include "TechCommand.h"        //tested
#include "GeneralCommand.h"     //tested

#include "TicketSystem.h"
#include "TicketLeaf.h"
#include "TicketCategory.h"

#include "Support.h"
#include "FinanceSupport.h"
#include "TechSupport.h"
#include "GeneralSupport.h"

#include "SystemMaker.h"
#include "TicketSystemMaker.h"

#include "Director.h"
#include <iostream>

int main()
{
    std::cout<<"=============================================================================================================\n1)Testing TicketInformation Class\n";
    std::vector<TicketInformation *> _financeVec;
    std::vector<TicketInformation *> _techVec;
    std::vector<TicketInformation *> _generalVec;

    std::cout<<"Testing a single TicketInformation...\n";
    TicketInformation* _ticket1=new TicketInformation("Test subject 1","lorem ipsum");
    
    if(_ticket1->getId()!="Test subject 1"){
        std::cout<<"***********TICKETINFORMTION CONSTRUCTOR OR GETID DOES NOT WORK****************\n";
    } else{
        std::cout<<"Ticket System getId() works.";
    }

    if(_ticket1->getInfo()!="lorem ipsum"){
        std::cout<<"***********TICKETINFORMTION CONSTRUCTOR OR GETINFO DOES NOT WORK****************\n";
    } else{
        std::cout<<"Ticket System getId() works.";
    }

    _ticket1->setId("x");
    _ticket1->setInfo("twitter");

    if(_ticket1->getId()=="x" && _ticket1->getInfo()=="twitter"){
        std::cout<<"TicketInformation setId and setInfo works as expected...\n";
    } else{
        std::cout<<"***********TICKETINFORMTION SETINFO OR SETID DOES NOT WORK****************\n";
    }
    
    std::cout<<"Adding 10 tickets to Finance vector...\n";
    for (int i = 0; i < 10; i++)
    {
        std::string _i = std::to_string(i);
        TicketInformation *temp = new TicketInformation(_i, "Info of Finance Ticket " + _i);
        _financeVec.push_back(temp);
    }

    std::cout<<"Adding 10 tickets to Tech vector...\n";
    for (int i = 0; i < 10; i++)
    {
        std::string _i = std::to_string(i);
        TicketInformation *temp = new TicketInformation(_i, "Info of Tech Ticket " + _i);
        _techVec.push_back(temp);
    }

    std::cout<<"Adding 10 tickets to General vector...\n";
    for (int i = 0; i < 10; i++)
    {
        std::string _i = std::to_string(i);
        TicketInformation *temp = new TicketInformation(_i, "Info of General Ticket " + _i);
        _generalVec.push_back(temp);
    }

    std::cout<<"\n=============================================================================================================\n2) Testing Command Pattern...\n";
    std::cout<<"Making a FinanceCommand + testing executing and getType...\n";
    FinanceCommand* _finCommand=new FinanceCommand();
    std::cout<<"Type = "+_finCommand->getType()+"\n";
    _finCommand->execute("test","lorem");

    std::cout<<"Making a TechCommand + testing executing and getType...\n";
    TechCommand* _techCommand=new TechCommand();
    std::cout<<"Type = "+_techCommand->getType()+"\n";
    _techCommand->execute("test","lorem");

    std::cout<<"Making a GeneralCommand + testing executing and getType...\n";
    GeneralCommand* _genCommand=new GeneralCommand();
    std::cout<<"Type = "+_genCommand->getType()+"\n";
    _genCommand->execute("test","lorem");

    std::cout<<"\n=============================================================================================================\nFreeing dynamic memory...\n";
    delete _ticket1;
    delete _techCommand;
    delete _finCommand;
    delete _genCommand;
    std::cout<<"TESTS CONCLUDED!\n";
}
