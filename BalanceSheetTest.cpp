#include <iostream>
#include <cassert>
#include "BalanceSheet.h"
#include "BalanceSheetTest.h"

using namespace std;

void BS_testGettersAndSetters();


void testBalanceSheet()
{
    cout << "Start Testing BalanceSheet" << endl;
    BS_testGettersAndSetters();
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