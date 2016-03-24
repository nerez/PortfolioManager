#ifndef TERMREPORT_H 
#define TERMREPORT_H

#include "BalanceSheet.h"
#include "IncomeStatement.h"
#include "CashFlow.h"

class TermReport
{
    public:
        //Constructors
        TermReport(){};
        TermReport(BalanceSheet bs, IncomeStatement is, CashFlow cf): balancesheet(bs), incomestatement(is), cashflow(cf){};
        TermReport& operator=(const TermReport& tr){balancesheet = tr.balancesheet; incomestatement = tr.incomestatement; cashflow = tr.cashflow;};
        
        //Getters
        BalanceSheet& getBalanceSheet(){return balancesheet;};
        IncomeStatement& getIncomeStatement(){return incomestatement;};
        CashFlow& getCashFlow(){return cashflow;};
        
        //Setters
        void setBalanceSheet(BalanceSheet& val){balancesheet = val;};
        void setIncomeStatement(IncomeStatement& val){incomestatement = val;};
        void setCashFlow(CashFlow& val){cashflow = val;};
        
    private:
        BalanceSheet balancesheet;
        IncomeStatement incomestatement;
        CashFlow cashflow;
};

#endif