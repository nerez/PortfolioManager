#include <iostream>
#include <cassert>
#include "BalanceSheet.h"
#include "BalanceSheetTest.h"

using namespace std;

void BS_testGettersAndSetters();

/*
int main()
{
    testBalanceSheet();
    return 0;
}
*/

void testBalanceSheet()
{
    cout << "Start Testing BalanceSheet" << endl;
    BS_testGettersAndSetters();
    cout << "Done Testing BalanceSheet" << endl;
}

void BS_testGettersAndSetters()
{
    #define CASH1 10.1
    #define CASH2 8.15
    #define SHORT_TERM_DEBT1 17.2
    #define SHORT_TERM_DEBT2 29.0
    #define NUM_OF_SHARES1 100
    #define NUM_OF_SHARES2 147
    #define EQUITY1 19
    #define EQUITY2 38
    cout << "Start testGettersAndSetters of BalanceSheet" << endl;
    Assets asset;
    asset.cash = CASH1;
    Liabilities liability;
    liability.short_term_debt = SHORT_TERM_DEBT1;
    Equity equity;
    equity.num_of_shares = NUM_OF_SHARES1;
    equity.equity = EQUITY1;
    BalanceSheet bs(asset, liability, equity);
    assert(bs.getAssets().cash == CASH1);
    assert(bs.getLiabilities().short_term_debt == SHORT_TERM_DEBT1);
    assert(bs.getEquity().equity == EQUITY1);
    assert(bs.getEquity().num_of_shares == NUM_OF_SHARES1);
    asset.cash = CASH2;
    liability.short_term_debt = SHORT_TERM_DEBT2;
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
    #undef CASH2
    #undef SHORT_TERM_DEBT1 
    #undef SHORT_TERM_DEBT2
    #undef NUM_OF_SHARES1
    #undef NUM_OF_SHARES2
    #undef EQUITY1
    #undef EQUITY2
}
