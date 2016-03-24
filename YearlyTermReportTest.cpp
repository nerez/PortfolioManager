#include <iostream>
#include <cassert>
#include "YearlyTermReportTest.h"
#include "TermReportTest.h"
#include "BalanceSheetTest.h"
#include "IncomeStatementTest.h"
#include "CashFlowTest.h"
#include "YearlyTermReport.h"
#include "TermReport.h"
#include "BalanceSheet.h"
#include "IncomeStatement.h"
#include "CashFlow.h"

using namespace std;

/*Test that checks that set_term4_from_yearly() is working properly*/
static void testSetTerm4FromYearly(YearlyTermReport& _ytr, const dollars _cash1, const dollars _short_term_debt1, const shares _num_of_shares1, const dollars _equity1, const dollars _revenues1, 
                        const dollars _expenses1, const dollars _net_income1, const dollars _operations1, const dollars _financing1, const dollars _investing1,
                        const dollars _cash2, const dollars _short_term_debt2, const shares _num_of_shares2, const dollars _equity2, const dollars _revenues2, 
                        const dollars _expenses2, const dollars _net_income2, const dollars _operations2, const dollars _financing2, const dollars _investing2,
                        const dollars _cash3, const dollars _short_term_debt3, const shares _num_of_shares3, const dollars _equity3, const dollars _revenues3, 
                        const dollars _expenses3, const dollars _net_income3, const dollars _operations3, const dollars _financing3, const dollars _investing3,
                        const dollars _cash4, const dollars _short_term_debt4, const shares _num_of_shares4, const dollars _equity4, const dollars _revenues4, 
                        const dollars _expenses4, const dollars _net_income4, const dollars _operations4, const dollars _financing4, const dollars _investing4);
                        
/*Test that 'setTermReport works*/
static void testSetTermReport();

/*Test that all the membrs of the TermReport tr are equal to 'num'*/
static void testAllTermMemberEqualToParam(TermReport& tr, int num);

int main()
{
    cout << "Start Testing YearlyTermReport" << endl;
    testYearlyTermReport();
    testTermReport();
    testBalanceSheet();
    testIncomeStatement();
    testCashFlow();
    cout << "Done Testing YearlyTermReport" << endl;
    
    return 0;
}

void testYearlyTermReport()
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
    #define CASH2 15.1
    #define SHORT_TERM_DEBT2 21.2
    #define NUM_OF_SHARES2 96
    #define EQUITY2 22
    #define REVENUES2 4.1
    #define EXPENSES2 13.2
    #define NETINCOME2 81
    #define OPERATIONS2 18.1
    #define FINANCING2 14.0
    #define INVESTING2 86
    #define CASH3 26.1
    #define SHORT_TERM_DEBT3 29.2
    #define NUM_OF_SHARES3 106
    #define EQUITY3 31
    #define REVENUES3 12.1
    #define EXPENSES3 21.2
    #define NETINCOME3 87
    #define OPERATIONS3 26.1
    #define FINANCING3 22.0
    #define INVESTING3 93
    #define CASH4 42.1
    #define SHORT_TERM_DEBT4 42.2
    #define NUM_OF_SHARES4 119
    #define EQUITY4 43
    #define REVENUES4 27.1
    #define EXPENSES4 38.2
    #define NETINCOME4 104
    #define OPERATIONS4 46.1
    #define FINANCING4 43.0
    #define INVESTING4 105
    YearlyTermReport yearly = CreateYearlyTermReport(CASH1, SHORT_TERM_DEBT1, NUM_OF_SHARES1, EQUITY1, REVENUES1, EXPENSES1, NETINCOME1, OPERATIONS1, FINANCING1, INVESTING1, 
                                             CASH2, SHORT_TERM_DEBT2, NUM_OF_SHARES2, EQUITY2, REVENUES2, EXPENSES2, NETINCOME2, OPERATIONS2, FINANCING2, INVESTING2, 
                                             CASH3, SHORT_TERM_DEBT3, NUM_OF_SHARES3, EQUITY3, REVENUES3, EXPENSES3, NETINCOME3, OPERATIONS3, FINANCING3, INVESTING3, 
                                             CASH4, SHORT_TERM_DEBT4, NUM_OF_SHARES4, EQUITY4, REVENUES4, EXPENSES4, NETINCOME4, OPERATIONS4, FINANCING4, INVESTING4);
    testSetTermReport();
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
    #undef CASH2 
    #undef SHORT_TERM_DEBT2
    #undef NUM_OF_SHARES2 
    #undef EQUITY2 
    #undef REVENUES2
    #undef EXPENSES2
    #undef NETINCOME2
    #undef OPERATIONS2
    #undef FINANCING2
    #undef INVESTING2
    #undef CASH3 
    #undef SHORT_TERM_DEBT3
    #undef NUM_OF_SHARES3 
    #undef EQUITY3 
    #undef REVENUES3
    #undef EXPENSES3
    #undef NETINCOME3
    #undef OPERATIONS3
    #undef FINANCING3
    #undef INVESTING3
    #undef CASH4 
    #undef SHORT_TERM_DEBT4
    #undef NUM_OF_SHARES4 
    #undef EQUITY4 
    #undef REVENUES4
    #undef EXPENSES4
    #undef NETINCOME4
    #undef OPERATIONS4
    #undef FINANCING4
    #undef INVESTING4
}

YearlyTermReport CreateYearlyTermReport(const dollars _cash1, const dollars _short_term_debt1, const shares _num_of_shares1, const dollars _equity1, const dollars _revenues1, 
                        const dollars _expenses1, const dollars _net_income1, const dollars _operations1, const dollars _financing1, const dollars _investing1,
                        const dollars _cash2, const dollars _short_term_debt2, const shares _num_of_shares2, const dollars _equity2, const dollars _revenues2, 
                        const dollars _expenses2, const dollars _net_income2, const dollars _operations2, const dollars _financing2, const dollars _investing2,
                        const dollars _cash3, const dollars _short_term_debt3, const shares _num_of_shares3, const dollars _equity3, const dollars _revenues3, 
                        const dollars _expenses3, const dollars _net_income3, const dollars _operations3, const dollars _financing3, const dollars _investing3,
                        const dollars _cash4, const dollars _short_term_debt4, const shares _num_of_shares4, const dollars _equity4, const dollars _revenues4, 
                        const dollars _expenses4, const dollars _net_income4, const dollars _operations4, const dollars _financing4, const dollars _investing4)
{
    cout << "CreateYearlyTermReport" << endl;
    TermReport tr1 = CreateTermReport(_cash1, _short_term_debt1, _num_of_shares1, _equity1, _revenues1, _expenses1, _net_income1, _operations1, _financing1, _investing1);
    TermReport tr2 = CreateTermReport(_cash2, _short_term_debt2, _num_of_shares2, _equity2, _revenues2, _expenses2, _net_income2, _operations2, _financing2, _investing2);
    TermReport tr3 = CreateTermReport(_cash3, _short_term_debt3, _num_of_shares3, _equity3, _revenues3, _expenses3, _net_income3, _operations3, _financing3, _investing3);
    TermReport k10 = CreateTermReport(_cash4, _short_term_debt4, _num_of_shares4, _equity4, _revenues4, _expenses4, _net_income4, _operations4, _financing4, _investing4);
    YearlyTermReport ytr(tr1, tr2, tr3, k10);
    return ytr;
}


static void testSetTermReport()
{
    cout << "start testSetTermReport of YearlyTermReport" << endl;
    const e_term t1 = TERM1;
    const e_term t2 = TERM2;
    const e_term t3 = TERM3;
    const e_term t4 = TERM4;
    const e_term yr = YEARLY;
    
    YearlyTermReport ytr = CreateYearlyTermReport(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    TermReport tr1 = CreateTermReport(1,1,1,1,1,1,1,1,1,1);
    TermReport tr1_2 = CreateTermReport(2,2,2,2,2,2,2,2,2,2);
    TermReport tr2 = CreateTermReport(2,2,2,2,2,2,2,2,2,2);
    TermReport tr2_2 = CreateTermReport(3,3,3,3,3,3,3,3,3,3);
    TermReport tr3 = CreateTermReport(3,3,3,3,3,3,3,3,3,3);
    TermReport tr3_2 = CreateTermReport(2,2,2,2,2,2,2,2,2,2);
    TermReport tr4 = CreateTermReport(4,4,4,4,4,4,4,4,4,4);
    TermReport yearly = CreateTermReport(5,5,5,5,5,5,5,5,5,5);
    ytr.setTermReport(t1, tr1);
    ytr.setTermReport(t2, tr2);
    ytr.setTermReport(t3, tr3);
    ytr.setTermReport(t4, tr4);
    
    // Checking that the yearly report is set to 0
    cout << "start checking that the yearly report is set to 0" << endl;
    testAllTermMemberEqualToParam(yearly, 0);
    
    // Setting the yearly report to 5
    ytr.setTermReport(yr, yearly);
    
    // Checking that the yearly report is set to 5
    cout << "start checking that the yearly report is set to 5" << endl;
    testAllTermMemberEqualToParam(yearly, 5);
    
    // Setting the term4 report with calculation option
    ytr.setTermReport(t4, tr4, true);
    
    // Checking that the term4 report is set to 4
    cout << "start checking that the term4 report is set to 4" << endl;
    testAllTermMemberEqualToParam(tr4, 4);
    
    // Checking that the yearly report is therefore set to 10 (1 + 2 + 3 + 4)
    cout << "start checking that the yearly report is set to 10" << endl;
    testAllTermMemberEqualToParam(yearly, 10);
    
    // Setting the yearly report to 5 with calculation option on
    ytr.setTermReport(yr, yearly, true);
    
    // Checking that term4 values are changed to -1 because of the yearly calculation
    cout << "start checking that the term4 report is set to -1" << endl;
    testAllTermMemberEqualToParam(tr4, -1);
    
    // Setting the first term to '2' with calculation option on
    ytr.setTermReport(t1, tr1_2, true);
    
    // Checking that term4 values are changed to -2 (5 - 2 - 2 - 3)
    cout << "start checking that the term4 report is set to -2" << endl;
    testAllTermMemberEqualToParam(tr4, -2);
    
    // Setting the second term to '3' with calculation option on
    ytr.setTermReport(t2, tr2_2, true);
    
    // Checking that term4 values are changed to -3 (5 - 2 - 3 - 3)
    cout << "start checking that the term4 report is set to -3" << endl;
    testAllTermMemberEqualToParam(tr4, -3);
    
    // Setting the third term to '2' with calculation option on
    ytr.setTermReport(t3, tr3_2, true);
    
    // Checking that term4 values are changed to -2 (5 - 2 - 3 - 2)
    cout << "start checking that the term4 report is set to -2" << endl;
    testAllTermMemberEqualToParam(tr4, -2);
    cout << "Done testSetTermReport of YearlyTermReport" << endl;
    
}

static void testAllTermMemberEqualToParam(TermReport& tr, int num)
{
    cout << "start testAllTermMemberEqualToParam of param: " << num << endl;
    BalanceSheet trbs = tr.getBalanceSheet();
    assert(trbs.getAssets().cash == (dollars)num);
    assert(trbs.getLiabilities().short_term_debt == (dollars)num);
    assert(trbs.getEquity().num_of_shares == (shares)num);
    assert(trbs.getEquity().equity == (dollars)num);
    IncomeStatement tris = tr.getIncomeStatement();
    assert(tris.getRevenues() == (dollars)num);
    assert(tris.getExpenses() == (dollars)num);
    assert(tris.getNetIncome() == (dollars)num);
    CashFlow trcf = tr.getCashFlow();
    assert(trcf.getOperations().sum == (dollars)num);
    assert(trcf.getFinancing().sum == (dollars)num);
    assert(trcf.getInvesting().sum == (dollars)num); 
    cout << "Done testAllTermMemberEqualToParam" << endl;
}

