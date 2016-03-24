#include <iostream>
#include <cassert>
#include "CashFlow.h"
#include "CashFlowTest.h"

using namespace std;

void CF_testGettersAndSetters();


void testCashFlow()
{
    cout << "Start Testing CashFlow" << endl;
    CF_testGettersAndSetters();
    cout << "Done Testing CashFlow" << endl;
}

void CF_testGettersAndSetters()
{
    #define OPERATIONS1 10.1
    #define OPERATIONS2 8.15 
    #define FINANCING1 17.2
    #define FINANCING2 29.0
    #define INVESTING1 100
    #define INVESTING2 147
    cout << "Start testGettersAndSetters of CashFlow" << endl;
    CashFlow cf = CreateCashFlow(OPERATIONS1, FINANCING1, INVESTING1) ;
    assert(cf.getOperations().sum == OPERATIONS1);
    assert(cf.getFinancing().sum == FINANCING1);
    assert(cf.getInvesting().sum == INVESTING1);
    Operations operations;
    Financing financing;
    Investing investing;
    operations.sum = OPERATIONS2;
    financing.sum = FINANCING2;
    investing.sum = INVESTING2;
    cf.setOperations(operations);
    cf.setFinancing(financing);
    cf.setInvesting(investing);
    assert(cf.getOperations().sum == OPERATIONS2);
    assert(cf.getFinancing().sum == FINANCING2);
    assert(cf.getInvesting().sum == INVESTING2);
    cout << "Done testGettersAndSetters of CashFlow" << endl;
    #undef OPERATIONS1
    #undef OPERATIONS2
    #undef FINANCING1
    #undef FINANCING2 
    #undef INVESTING1
    #undef INVESTING2
}

CashFlow CreateCashFlow(const dollars _operations, const dollars _financing, const dollars _investing)
{
    cout << "CreateCashFlow" << endl;
    Operations operations;
    operations.sum = _operations;
    Financing financing;
    financing.sum = _financing;
    Investing investing;
    investing.sum = _investing;
    CashFlow cf(operations, financing, investing);
    return cf;
}