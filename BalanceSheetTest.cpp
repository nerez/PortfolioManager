#include <iostream>
#include <cassert>
#include <cmath>
#include "BalanceSheet.h"
#include "BalanceSheetTest.h"

using namespace std;

void BS_testGettersAndSetters();
void BS_testOperators();


void testBalanceSheet()
{
    cout << "Start Testing BalanceSheet" << endl;
    BS_testGettersAndSetters();
    BS_testOperators();
    cout << "Done Testing BalanceSheet" << endl;
}




void BS_testGettersAndSetters()
{
    #define CASH1 10.1
    #define SHORT_TERM_DEBT1 17.2
    #define NUM_OF_SHARES1 100
    #define EQUITY1 19
    #define CASH2 8.15
    #define SHORT_TERM_DEBT2 29.0
    #define NUM_OF_SHARES2 147
    #define EQUITY2 38
    cout << "Start testGettersAndSetters of BalanceSheet" << endl;
    BalanceSheet bs = CreateBalanceSheet(CASH1, SHORT_TERM_DEBT1, NUM_OF_SHARES1, EQUITY1);
    assert(bs.getAssets().cash == CASH1);
    assert(bs.getLiabilities().short_term_debt == SHORT_TERM_DEBT1);
    assert(bs.getEquity().equity == EQUITY1);
    assert(bs.getEquity().num_of_shares == NUM_OF_SHARES1);
    Assets asset;
    asset.cash = CASH2;
    Liabilities liability;
    liability.short_term_debt = SHORT_TERM_DEBT2;
    Equity equity;
    equity.num_of_shares = NUM_OF_SHARES2;
    equity.equity = EQUITY2;
    bs.setAssets(asset);
    bs.setLiabilities(liability);
    bs.setEquity(equity);
    assert(bs.getAssets().cash == CASH2);
    assert(bs.getLiabilities().short_term_debt == SHORT_TERM_DEBT2);
    assert(bs.getEquity().equity == EQUITY2);
    assert(bs.getEquity().num_of_shares == NUM_OF_SHARES2);
    cout << "Done testGettersAndSetters of BalanceSheet" << endl;
    #undef CASH1
    #undef SHORT_TERM_DEBT1 
    #undef NUM_OF_SHARES1
    #undef EQUITY1
    #undef CASH2
    #undef SHORT_TERM_DEBT2
    #undef NUM_OF_SHARES2
    #undef EQUITY2
}

void BS_testOperators()
{
    #define CASH1 10.1
    #define SHORT_TERM_DEBT1 17.2
    #define NUM_OF_SHARES1 100
    #define EQUITY1 19
    #define CASH2 8.15
    #define SHORT_TERM_DEBT2 4.1
    #define NUM_OF_SHARES2 98
    #define EQUITY2 9
    cout << "Start testOperators of BalanceSheet" << endl;
    BalanceSheet bs1 = CreateBalanceSheet(CASH1, SHORT_TERM_DEBT1, NUM_OF_SHARES1, EQUITY1);
    BalanceSheet bs2 = CreateBalanceSheet(CASH2, SHORT_TERM_DEBT2, NUM_OF_SHARES2, EQUITY2);
    
    Assets asset1 = bs1.getAssets() + bs2.getAssets();
    assert(abs(asset1.cash - (CASH1 + CASH2)) < EPSILON);
    Assets asset2 = bs1.getAssets() - bs2.getAssets();
    assert(abs(asset2.cash - (CASH1 - CASH2)) < EPSILON);
    Assets asset3 = {0};
    asset3 += bs1.getAssets();
    assert(abs(asset3.cash - CASH1) < EPSILON);
    asset1 -= bs1.getAssets();
    assert(abs(asset1.cash - CASH2) < EPSILON);
    
    Liabilities liability1 = bs1.getLiabilities() + bs2.getLiabilities();
    assert(abs(liability1.short_term_debt - (SHORT_TERM_DEBT1 + SHORT_TERM_DEBT2)) < EPSILON);
    Liabilities liability2 = bs1.getLiabilities() - bs2.getLiabilities();
    assert(abs(liability2.short_term_debt - (SHORT_TERM_DEBT1 - SHORT_TERM_DEBT2)) < EPSILON);
    Liabilities liability3 = {0};
    liability3 += bs1.getLiabilities();
    assert(abs(liability3.short_term_debt - SHORT_TERM_DEBT1) < EPSILON);
    liability1 -= bs1.getLiabilities();
    assert(abs(liability1.short_term_debt - SHORT_TERM_DEBT2) < EPSILON);
    
    Equity equity1 = bs1.getEquity() + bs2.getEquity();
    assert(abs(equity1.equity - (EQUITY1 + EQUITY2)) < EPSILON);
    assert(abs(equity1.num_of_shares - (NUM_OF_SHARES1 + NUM_OF_SHARES2)) < EPSILON);
    Equity equity2 = bs1.getEquity() - bs2.getEquity();
    assert(abs(equity2.equity - (EQUITY1 - EQUITY2)) < EPSILON);
    assert(abs(equity2.num_of_shares - (NUM_OF_SHARES1 - NUM_OF_SHARES2)) < EPSILON);
    Equity equity3 = {0};
    equity3 += bs1.getEquity();
    assert(abs(equity3.equity - EQUITY1) < EPSILON);
    assert(abs(equity3.num_of_shares - NUM_OF_SHARES1) < EPSILON);
    equity1 -= bs1.getEquity();
    assert(abs(equity1.equity - EQUITY2) < EPSILON);
    assert(abs(equity1.num_of_shares - NUM_OF_SHARES2) < EPSILON);
    
    BalanceSheet bs3 = bs1 + bs2;
    assert(abs(bs3.getAssets().cash - (CASH1 + CASH2)) < EPSILON);
    assert(abs(bs3.getLiabilities().short_term_debt - (SHORT_TERM_DEBT1 + SHORT_TERM_DEBT2)) < EPSILON);
    assert(abs(bs3.getEquity().equity - (EQUITY1 + EQUITY2)) < EPSILON);
    assert(abs(bs3.getEquity().num_of_shares - (NUM_OF_SHARES1 + NUM_OF_SHARES2)) < EPSILON);
    
    BalanceSheet bs4 = bs1 - bs2;
    assert(abs(bs4.getAssets().cash - (CASH1 - CASH2)) < EPSILON);
    assert(abs(bs4.getLiabilities().short_term_debt - (SHORT_TERM_DEBT1 - SHORT_TERM_DEBT2)) < EPSILON);
    assert(abs(bs4.getEquity().equity - (EQUITY1 - EQUITY2)) < EPSILON);
    assert(abs(bs4.getEquity().num_of_shares - (NUM_OF_SHARES1 - NUM_OF_SHARES2)) < EPSILON);
    
    bs4 += bs2;
    assert(abs(bs4.getAssets().cash - (CASH1)) < EPSILON);
    assert(abs(bs4.getLiabilities().short_term_debt - (SHORT_TERM_DEBT1)) < EPSILON);
    assert(abs(bs4.getEquity().equity - (EQUITY1)) < EPSILON);
    assert(abs(bs4.getEquity().num_of_shares - (NUM_OF_SHARES1)) < EPSILON);
    
    bs3 -= bs1;
    assert(abs(bs3.getAssets().cash - (CASH2)) < EPSILON);
    assert(abs(bs3.getLiabilities().short_term_debt - (SHORT_TERM_DEBT2)) < EPSILON);
    assert(abs(bs3.getEquity().equity - (EQUITY2)) < EPSILON);
    assert(abs(bs3.getEquity().num_of_shares - (NUM_OF_SHARES2)) < EPSILON);
    
    
    #undef CASH1
    #undef SHORT_TERM_DEBT1 
    #undef NUM_OF_SHARES1
    #undef EQUITY1
    #undef CASH2
    #undef SHORT_TERM_DEBT2
    #undef NUM_OF_SHARES2
    #undef EQUITY2
}



BalanceSheet CreateBalanceSheet(const dollars _cash, const dollars _short_term_debt, const shares _num_of_shares, const dollars _equity )
{
    cout << "CreateBalanceSheet" << endl;
    Assets asset;
    asset.cash = _cash;
    Liabilities liability;
    liability.short_term_debt = _short_term_debt;
    Equity equity;
    equity.num_of_shares = _num_of_shares;
    equity.equity = _equity;
    BalanceSheet bs(asset, liability, equity);
    return bs;
}

