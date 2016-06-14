#include <stdexcept>
#include "YearlyTermReport.h"


void Year::checkYear(u_int _year)
{
    if ((_year >= 2009) && (_year < 2020))
        year = _year;
    else throw std::invalid_argument("Invalid input of year");
}

//Public
TermReport& YearlyTermReport::getTermReport(const e_term t)
{
    switch(t)
    {
        case TERM1:
            return term1;
        case TERM2:
            return term2;
        case TERM3:
            return term3;
        case TERM4:
            return term4;
        case YEARLY:
            return yearly;
    };
}

void YearlyTermReport::setTermReport(const e_term t, TermReport& tr, bool calculate)
{
    switch(t)
    {
        case TERM1:
            term1 = tr;
            break;
        case TERM2:
            term2 = tr;
            break;
        case TERM3:
            term3 = tr;
            break;
        case TERM4:
            term4 = tr;
            break;
        case YEARLY:
            yearly = tr;
            break;
    };
    
    if (calculate == false)
        return;
        
    e_term calc_t = TERM1;
    if ((t == TERM4) || (t == YEARLY))
    {
         calc_t = t;
    }
    else
        return;
    
    switch(calc_t)
    {
        case TERM4:
            yearly = term1 + term2 + term3 + term4;
            break;
        case YEARLY:
            term4 = yearly - term1 - term2 - term3;
            break;
    }
    
}