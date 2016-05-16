#ifndef INCOMESTATEMENT_H
#define INCOMESTATEMENT_H

#include "Infrastructure.h"

struct t_income_statement
{
    dollars revenues;
    dollars expenses;
    dollars net_income;
    
     //Operators
    t_income_statement& operator+=(const t_income_statement& other)
    {
        revenues += other.revenues;
        expenses += other.expenses;
        net_income += other.net_income;
    }
    
    t_income_statement& operator-=(const t_income_statement& other)
    {
        revenues -= other.revenues;
        expenses -= other.expenses;
        net_income -= other.net_income;
    }
};

inline t_income_statement operator+(t_income_statement left, const t_income_statement& right)
{
    left += right;
    return left;
}

inline t_income_statement operator-(t_income_statement left, const t_income_statement& right)
{
    left -= right;
    return left;
}



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
        
         //Operators
        IncomeStatement& operator+=(const IncomeStatement& other)
        {
            income_statement += other.income_statement;
        }
        
        IncomeStatement& operator-=(const IncomeStatement& other)
        {
            income_statement -= other.income_statement;
        }
        
    private:
        t_income_statement income_statement;
};

inline IncomeStatement operator+(IncomeStatement left, const IncomeStatement& right)
{
    left += right;
    return left;
}

inline IncomeStatement operator-(IncomeStatement left, const IncomeStatement& right)
{
    left -= right;
    return left;
}
        
#endif
