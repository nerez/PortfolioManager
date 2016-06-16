#include <iostream>
#include <cassert>
#include "CompanyTest.h"
#include "YearlyTermReportTest.h"
#include "TermReportTest.h"
#include "BalanceSheetTest.h"
#include "IncomeStatementTest.h"
#include "CashFlowTest.h"
#include "Company.h"
#include "YearlyTermReport.h"
#include "TermReport.h"
#include "BalanceSheet.h"
#include "IncomeStatement.h"
#include "CashFlow.h"

using namespace std;


void testCompany();
void testSetGetCompanyName();
void testGetCurrentMarketPrice();
void testInsertYearlyTermReport();
void testGetYearlyTermReport();


int main()
{
    cout << "Start Testing YearlyTermReport" << endl;
    testCompany();
    cout << "Done Testing YearlyTermReport" << endl;
    
    return 0;
}

void testCompany()
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
    YearlyTermReport yearly1 = CreateYearlyTermReport(CASH1, SHORT_TERM_DEBT1, NUM_OF_SHARES1, EQUITY1, REVENUES1, EXPENSES1, NETINCOME1, OPERATIONS1, FINANCING1, INVESTING1, 
                                             CASH2, SHORT_TERM_DEBT2, NUM_OF_SHARES2, EQUITY2, REVENUES2, EXPENSES2, NETINCOME2, OPERATIONS2, FINANCING2, INVESTING2, 
                                             CASH3, SHORT_TERM_DEBT3, NUM_OF_SHARES3, EQUITY3, REVENUES3, EXPENSES3, NETINCOME3, OPERATIONS3, FINANCING3, INVESTING3, 
                                             CASH4, SHORT_TERM_DEBT4, NUM_OF_SHARES4, EQUITY4, REVENUES4, EXPENSES4, NETINCOME4, OPERATIONS4, FINANCING4, INVESTING4);
    YearlyTermReport yearly2 = CreateYearlyTermReport(CASH2, SHORT_TERM_DEBT2, NUM_OF_SHARES2, EQUITY2, REVENUES2, EXPENSES2, NETINCOME2, OPERATIONS2, FINANCING2, INVESTING2, 
                                             CASH2, SHORT_TERM_DEBT2, NUM_OF_SHARES2, EQUITY2, REVENUES2, EXPENSES2, NETINCOME2, OPERATIONS2, FINANCING2, INVESTING2, 
                                             CASH3, SHORT_TERM_DEBT3, NUM_OF_SHARES3, EQUITY3, REVENUES3, EXPENSES3, NETINCOME3, OPERATIONS3, FINANCING3, INVESTING3, 
                                             CASH4, SHORT_TERM_DEBT4, NUM_OF_SHARES4, EQUITY4, REVENUES4, EXPENSES4, NETINCOME4, OPERATIONS4, FINANCING4, INVESTING4);
    testSetGetCompanyName();
    testGetCurrentMarketPrice();
    testInsertYearlyTermReport();
    testGetYearlyTermReport();
    
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


void testGetYearlyTermReport()
{
    cout << "Start testGetYearlyTermReport" << endl;
    cout << "Done testGetYearlyTermReport" << endl;
}

void testInsertYearlyTermReport()
{
    cout << "Start testInsertYearlyTermReport" << endl;
    cout << "Done testInsertYearlyTermReport" << endl;
}

void testGetCurrentMarketPrice()
{
    cout << "Start testGetCurrentMarketPrice" << endl;
    cout << "Done testGetCurrentMarketPrice" << endl;
}

void testSetGetCompanyName()
{
    #define COMPANYNAME "Apple"
    cout << "Start testGetCompanyName" << endl;
    
    Company company_w_name = Company(COMPANYNAME);
    assert(company_w_name.getCompanyName().compare(COMPANYNAME) == 0 );
    Company company_wo_name = Company();
    company_wo_name.setCompanyName(COMPANYNAME);
    assert(company_wo_name.getCompanyName().compare(COMPANYNAME) == 0);
    
    cout << "Done testGetCompanyName" << endl;
    #undef COMPANYNAME
}