#include <iostream>
#include <cassert>
#include "BalanceSheet.h"
#include "IncomeStatement.h"
#include "CashFlow.h"
#include "BalanceSheetTest.h"
#include "IncomeStatementTest.h"
#include "CashFlowTest.h"
#include "TermReportTest.h"
#include "TermReport.h"

using namespace std;



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

