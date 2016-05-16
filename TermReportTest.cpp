#include <iostream>
#include <cassert>
#include <cmath>
#include "BalanceSheet.h"
#include "IncomeStatement.h"
#include "CashFlow.h"
#include "BalanceSheetTest.h"
#include "IncomeStatementTest.h"
#include "CashFlowTest.h"
#include "TermReportTest.h"
#include "TermReport.h"

using namespace std;

void TermReport_testOperators();

/*
int main()
{
    cout << "Start Testing TermReport" << endl;
    testTermReport();
    testBalanceSheet();
    testIncomeStatement();
    testCashFlow();
    cout << "Done Testing TermReport" << endl;
    
    return 0;
}
*/

void testTermReport()
{
    #define CASH1 10.1
    #define SHORT_TERM_DEBT1 17.2
    #define NUM_OF_SHARES1 100
    #define EQUITY1 19
    #define REVENUES1 10.1
    #define EXPENSES1 17.2
    #define NETINCOME1 100
    #define OPERATIONS1 10.1
    #define FINANCING1 17.2
    #define INVESTING1 100
    TermReport tr = CreateTermReport(CASH1, SHORT_TERM_DEBT1, NUM_OF_SHARES1, EQUITY1, REVENUES1, EXPENSES1, NETINCOME1, OPERATIONS1, FINANCING1, INVESTING1);
    TermReport_testOperators();
    #undef CASH1 
    #undef SHORT_TERM_DEBT1
    #undef NUM_OF_SHARES1 
    #undef EQUITY1 
    #undef REVENUES1
    #undef EXPENSES1
    #undef NETINCOME1
    #undef OPERATIONS1
    #undef FINANCING1
    #undef INVESTING1
}


void TermReport_testOperators()
{
    #define CASH1 10.1
    #define CASH2 11.15
    #define SHORT_TERM_DEBT1 17.2
    #define SHORT_TERM_DEBT2 19.1
    #define NUM_OF_SHARES1 100
    #define NUM_OF_SHARES2 107
    #define EQUITY1 19
    #define EQUITY2 25
    #define OPERATIONS1 10.1
    #define OPERATIONS2 19.13 
    #define FINANCING1 17.2
    #define FINANCING2 22.0
    #define INVESTING1 100
    #define INVESTING2 104   
    #define REVENUES1 10.1
    #define REVENUES2 15.3
    #define EXPENSES1 14.2
    #define EXPENSES2 17.0
    #define NETINCOME1 100
    #define NETINCOME2 107
    cout << "Start testOperators of TermReport" << endl;
    TermReport tr1 = CreateTermReport(CASH1, SHORT_TERM_DEBT1, NUM_OF_SHARES1, EQUITY1, REVENUES1, EXPENSES1, NETINCOME1, OPERATIONS1, FINANCING1, INVESTING1);
    TermReport tr2 = CreateTermReport(CASH2, SHORT_TERM_DEBT2, NUM_OF_SHARES2, EQUITY2, REVENUES2, EXPENSES2, NETINCOME2, OPERATIONS2, FINANCING2, INVESTING2);
    
    TermReport tr3 = tr1 + tr2;
    assert(abs(tr3.getBalanceSheet().getAssets().cash - (CASH1 + CASH2)) < EPSILON);
    assert(abs(tr3.getBalanceSheet().getLiabilities().short_term_debt - (SHORT_TERM_DEBT1 + SHORT_TERM_DEBT2)) < EPSILON);
    assert(abs(tr3.getBalanceSheet().getEquity().equity - (EQUITY1 + EQUITY2)) < EPSILON);
    assert(abs(tr3.getIncomeStatement().getRevenues() - (REVENUES1 + REVENUES2)) < EPSILON);
    assert(abs(tr3.getIncomeStatement().getExpenses() - (EXPENSES1 + EXPENSES2)) < EPSILON);
    assert(abs(tr3.getIncomeStatement().getNetIncome() - (NETINCOME1 + NETINCOME2)) < EPSILON);
    assert(abs(tr3.getCashFlow().getOperations().sum - (OPERATIONS1 + OPERATIONS2)) < EPSILON);
    assert(abs(tr3.getCashFlow().getFinancing().sum - (FINANCING1 + FINANCING2)) < EPSILON);
    assert(abs(tr3.getCashFlow().getInvesting().sum - (INVESTING1 + INVESTING2)) < EPSILON);
    
    TermReport tr4 = tr2 - tr1;
    assert(abs(tr4.getBalanceSheet().getAssets().cash - (CASH2 - CASH1)) < EPSILON);
    assert(abs(tr4.getBalanceSheet().getLiabilities().short_term_debt - (SHORT_TERM_DEBT2 - SHORT_TERM_DEBT1)) < EPSILON);
    assert(abs(tr4.getBalanceSheet().getEquity().equity - (EQUITY2 - EQUITY1)) < EPSILON);
    assert(abs(tr4.getIncomeStatement().getRevenues() - (REVENUES2 - REVENUES1)) < EPSILON);
    assert(abs(tr4.getIncomeStatement().getExpenses() - (EXPENSES2 - EXPENSES1)) < EPSILON);
    assert(abs(tr4.getIncomeStatement().getNetIncome() - (NETINCOME2 - NETINCOME1)) < EPSILON);
    assert(abs(tr4.getCashFlow().getOperations().sum - (OPERATIONS2 - OPERATIONS1)) < EPSILON);
    assert(abs(tr4.getCashFlow().getFinancing().sum - (FINANCING2 - FINANCING1)) < EPSILON);
    assert(abs(tr4.getCashFlow().getInvesting().sum - (INVESTING2 - INVESTING1)) < EPSILON);
    
    tr4 += tr1;
    assert(abs(tr4.getBalanceSheet().getAssets().cash - (CASH2)) < EPSILON);
    assert(abs(tr4.getBalanceSheet().getLiabilities().short_term_debt - (SHORT_TERM_DEBT2)) < EPSILON);
    assert(abs(tr4.getBalanceSheet().getEquity().equity - (EQUITY2)) < EPSILON);
    assert(abs(tr4.getIncomeStatement().getRevenues() - (REVENUES2)) < EPSILON);
    assert(abs(tr4.getIncomeStatement().getExpenses() - (EXPENSES2)) < EPSILON);
    assert(abs(tr4.getIncomeStatement().getNetIncome() - (NETINCOME2)) < EPSILON);
    assert(abs(tr4.getCashFlow().getOperations().sum - (OPERATIONS2)) < EPSILON);
    assert(abs(tr4.getCashFlow().getFinancing().sum - (FINANCING2)) < EPSILON);
    assert(abs(tr4.getCashFlow().getInvesting().sum - (INVESTING2)) < EPSILON);
    
    tr3 -= tr1;
    assert(abs(tr3.getBalanceSheet().getAssets().cash - (CASH2)) < EPSILON);
    assert(abs(tr3.getBalanceSheet().getLiabilities().short_term_debt - (SHORT_TERM_DEBT2)) < EPSILON);
    assert(abs(tr3.getBalanceSheet().getEquity().equity - (EQUITY2)) < EPSILON);
    assert(abs(tr3.getIncomeStatement().getRevenues() - (REVENUES2)) < EPSILON);
    assert(abs(tr3.getIncomeStatement().getExpenses() - (EXPENSES2)) < EPSILON);
    assert(abs(tr3.getIncomeStatement().getNetIncome() - (NETINCOME2)) < EPSILON);
    assert(abs(tr3.getCashFlow().getOperations().sum - (OPERATIONS2)) < EPSILON);
    assert(abs(tr3.getCashFlow().getFinancing().sum - (FINANCING2)) < EPSILON);
    assert(abs(tr3.getCashFlow().getInvesting().sum - (INVESTING2)) < EPSILON);
    
    
    #undef CASH1
    #undef CASH2
    #undef SHORT_TERM_DEBT1
    #undef SHORT_TERM_DEBT2
    #undef NUM_OF_SHARES1
    #undef NUM_OF_SHARES2
    #undef EQUITY1
    #undef EQUITY2
    #undef OPERATIONS1
    #undef OPERATIONS2
    #undef FINANCING1
    #undef FINANCING2
    #undef INVESTING1
    #undef INVESTING2
    #undef REVENUES1
    #undef REVENUES2
    #undef EXPENSES1
    #undef EXPENSES2
    #undef NETINCOME1
    #undef NETINCOME2
}

TermReport CreateTermReport(const dollars _cash, const dollars _short_term_debt, const shares _num_of_shares, const dollars _equity, const dollars _revenues, 
                        const dollars _expenses, const dollars _net_income, const dollars _operations, const dollars _financing, const dollars _investing)
{
    cout << "CreateTermReport" << endl;
    BalanceSheet bs = CreateBalanceSheet(_cash, _short_term_debt, _num_of_shares, _equity);
    IncomeStatement is = CreateIncomeStatement(_revenues, _expenses, _net_income);
    CashFlow cf = CreateCashFlow(_operations, _financing, _investing);
    TermReport tr(bs, is, cf);
    return tr;
}

