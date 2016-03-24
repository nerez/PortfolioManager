#ifndef INCOMESTATEMENT_H
#define INCOMESTATEMENT_H

#include "Infrastructure.h"

struct t_income_statement
{
    dollars revenues;
    dollars expenses;
    dollars net_income;
};

class IncomeStatement
{
    public:
        //Constructors
        IncomeStatement(){};
        IncomeStatement(t_income_statement& is): income_statement(is){};
        
        //Getters
        dollars getRevenues(){return income_statement.revenues;};
        dollars getExpenses(){return income_statement.expenses;};
        dollars getNetIncome(){return income_statement.net_income;};
        
        //Setters
        void setRevenues(dollars val){income_statement.revenues = val;};
        void setExpenses(dollars val){income_statement.expenses = val;};
        void setNetIncome(dollars val){income_statement.net_income = val;};
        
    private:
        t_income_statement income_statement;
};
#endif
