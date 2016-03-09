#include <iostream>
#include <cassert>
#include "IncomeStatementTest.h"
#include "BalanceSheetTest.h"
#include "CashFlowTest.h"

using namespace std;

int main()
{
    cout << "Start Testing TermReport" << endl;
    testBalanceSheet();
    testIncomeStatement();
    testCashFlow();
    cout << "Done Testing TermReport" << endl;
    
    return 0;
    
}