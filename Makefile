all: PortfolioManager

PortfolioManager: BalanceSheetTest.cpp IncomeStatementTest.cpp CashFlowTest.cpp TermReportTest.cpp YearlyTermReport.cpp YearlyTermReportTest.cpp
	g++ -std=c++11 BalanceSheetTest.cpp IncomeStatementTest.cpp CashFlowTest.cpp TermReportTest.cpp YearlyTermReport.cpp YearlyTermReportTest.cpp -o PortfolioManager
	
