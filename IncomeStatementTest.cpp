#include <iostream>
#include <cassert>
#include "IncomeStatement.h"
#include "IncomeStatementTest.h"

using namespace std;

void IS_testGettersAndSetters();

/*
int main()
{
    testIncomeStatement();
    return 0;
}
*/

void testIncomeStatement()
{
    cout << "Start Testing IncomeStatement" << endl;
    IS_testGettersAndSetters();
    cout << "Done Testing IncomeStatement" << endl;
}


void IS_testGettersAndSetters()
{
    #define REVENUES1 10.1
    #define REVENUES2 26.3
    #define EXPENSES1 17.2
    #define EXPENSES2 29.0
    #define NETINCOME1 100
    #define NETINCOME2 147
    cout << "Start testGettersAndSetters of IncomeStatement" << endl;
    IncomeStatement is = CreateIncomeStatement(REVENUES1, EXPENSES1, NETINCOME1);
    assert(is.getRevenues() == REVENUES1);
    assert(is.getExpenses() == EXPENSES1);
    assert(is.getNetIncome() == NETINCOME1);
    is.setRevenues(REVENUES2);
    is.setExpenses(EXPENSES2);
    is.setNetIncome(NETINCOME2);
    assert(is.getRevenues() == REVENUES2);
    assert(is.getExpenses() == EXPENSES2);
    assert(is.getNetIncome() == NETINCOME2);
    cout << "Done testGettersAndSetters of IncomeStatement" << endl;
    #undef REVENUES1
    #undef REVENUES2
    #undef EXPENSES1
    #undef EXPENSES2 
    #undef NETINCOME1
    #undef NETINCOME2
}

IncomeStatement CreateIncomeStatement(const dollars _revenues, const dollars _expenses, const dollars _net_income)
{
    cout << "CreateIncomeStatement" << endl;
    t_income_statement income_statement;
    income_statement.revenues = _revenues;
    income_statement.expenses = _expenses;
    income_statement.net_income = _net_income;
    IncomeStatement is(income_statement);
    return is;
}