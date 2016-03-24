#ifndef YEARLYTERMREPORT_H 
#define YEARLYTERMREPORT_H

#include "TermReport.h"

enum e_term {TERM1, TERM2, TERM3, TERM4, YEARLY};


class YearlyTermReport
{
    public:
        //Constructors
        YearlyTermReport(){};
        YearlyTermReport(TermReport Q1, TermReport Q2, TermReport Q3, TermReport K10): term1(Q1), term2(Q2), term3(Q3), yearly(K10){ term4 = get_term4_from_yearly(); };
        
        //Getters
        TermReport& getTermReport(const e_term t);
        
        //Setters
        void setTermReport(const e_term t, TermReport& tr, bool calculate=false);
        
    private:
        TermReport term1;
        TermReport term2;
        TermReport term3;
        TermReport term4;
        TermReport yearly;
        
        TermReport get_term4_from_yearly();
};

#endif