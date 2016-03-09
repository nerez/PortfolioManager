#ifndef CASHFLOW_H
#define CASHFLOW_H

#include "Infrastructure.h"

struct Operations
{
    dollars sum;
};

struct Financing
{
    dollars sum;
};

struct Investing
{
    dollars sum;
};


class CashFlow
{
        public:
        //Constructors
        CashFlow(Operations& o, Financing& f, Investing& i): operations(o), financing(f), investing(i){};
        
        //Getters
        Operations getOperations(){return operations;};
        Financing getFinancing(){return financing;};
        Investing getInvesting(){return investing;};
        
        //Setters
        void setOperations(Operations val){operations = val;};
        void setFinancing(Financing val){financing = val;};
        void setInvesting(Investing val){investing = val;};
        
    private:
        Operations      operations;
        Financing       financing;
        Investing       investing;
        
};
#endif
