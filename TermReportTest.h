#ifndef TERMREPORTTEST_H 
#define TERMREPORTTEST_H

#include "TermReport.h"

void testTermReport();
TermReport CreateTermReport(const dollars _cash, const dollars _short_term_debt, const shares _num_of_shares, const dollars _equity, const dollars _revenues, 
                        const dollars _expenses, const dollars _net_income, const dollars _operations, const dollars _financing, const dollars _investing);

#endif