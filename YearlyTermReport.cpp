#include "YearlyTermReport.h"

//Private
TermReport YearlyTermReport::get_term4_from_yearly()
{ 
    return term1;
}

TermReport& YearlyTermReport::getTermReport(const e_term t)
{
    return term4;
}

void YearlyTermReport::setTermReport(const e_term t, TermReport& tr, bool calculate)
{
    return;
}