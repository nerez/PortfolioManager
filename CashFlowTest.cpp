#include <iostream>
#include <cassert>
#include <cmath>
#include "CashFlow.h"
#include "CashFlowTest.h"

using namespace std;

void CF_testGettersAndSetters();
void CF_testOperators();


void testCashFlow()
{
    cout << "Start Testing CashFlow" << endl;
    CF_testGettersAndSetters();
    CF_testOperators();
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


void CF_testOperators()
{
    #define OPERATIONS1 10.1
    #define OPERATIONS2 11.15 
    #define FINANCING1 17.2
    #define FINANCING2 29.0
    #define INVESTING1 100
    #define INVESTING2 147
    cout << "Start testOperators of CashFlow" << endl;
    CashFlow cf1 = CreateCashFlow(OPERATIONS1, FINANCING1, INVESTING1);
    CashFlow cf2 = CreateCashFlow(OPERATIONS2, FINANCING2, INVESTING2);
    
    CashFlow cf3 = cf1 + cf2;
    assert(abs(cf3.getOperations().sum - (OPERATIONS1 + OPERATIONS2)) < EPSILON);
    assert(abs(cf3.getFinancing().sum - (FINANCING1 + FINANCING2)) < EPSILON);
    assert(abs(cf3.getInvesting().sum - (INVESTING1 + INVESTING2)) < EPSILON);
    
    CashFlow cf4 = cf2 - cf1;
    assert(abs(cf4.getOperations().sum - (OPERATIONS2 - OPERATIONS1)) < EPSILON);
    assert(abs(cf4.getFinancing().sum - (FINANCING2 - FINANCING1)) < EPSILON);
    assert(abs(cf4.getInvesting().sum - (INVESTING2 - INVESTING1)) < EPSILON);
    
    cf4 += cf1;
    assert(abs(cf4.getOperations().sum - (OPERATIONS2)) < EPSILON);
    assert(abs(cf4.getFinancing().sum - (FINANCING2)) < EPSILON);
    assert(abs(cf4.getInvesting().sum - (INVESTING2)) < EPSILON);
    
    cf3 -= cf1;
    assert(abs(cf3.getOperations().sum - (OPERATIONS2)) < EPSILON);
    assert(abs(cf3.getFinancing().sum - (FINANCING2)) < EPSILON);
    assert(abs(cf3.getInvesting().sum - (INVESTING2)) < EPSILON);
    
    
    #undef OPERATIONS1
    #undef FINANCING1 
    #undef NUM_OF_SHARES1
    #undef INVESTING1
    #undef OPERATIONS2
    #undef FINANCING2
    #undef NUM_OF_SHARES2
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