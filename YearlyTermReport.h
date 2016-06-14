#ifndef YEARLYTERMREPORT_H 
#define YEARLYTERMREPORT_H

#include "TermReport.h"

enum e_term {TERM1, TERM2, TERM3, TERM4, YEARLY};

class Year
{
    private:
        int year;
        void checkYear( u_int _year );
        
    public:
        Year(u_int year){ checkYear(year); };
        u_int getYear(){ return year; };
};



class YearlyTermReport
{    
    private:
        TermReport term1;
        TermReport term2;
        TermReport term3;
        TermReport term4;
        TermReport yearly;
        
    public:
        //Constructors
        YearlyTermReport(){};
        YearlyTermReport(TermReport Q1, TermReport Q2, TermReport Q3, TermReport K10): term1(Q1), term2(Q2), term3(Q3), yearly(K10){ term4 = yearly - term1 - term2 - term3; };
        
        //Getters
        TermReport& getTermReport(const e_term t);
        
        //Setters
        
        //Input:    const e_term t, 
        //          TermReport& tr, 
        //          bool calculate=false
        //Output:   void
        //Functionality: The function sets TermReport& tr according to the e_term t of the object. if calculate is 'true' and e_term t TERM4, the function also sets 
        //              the yearly TermReport (the values are calculated by adding the other 4 terms). If e_term t is YEARLY, and calculated is 'true' the function also
        //              sets the TERM4 TermReport (the values are calculated by the yearly report and the other 3 terms). If calculated is 'false', no calculation
        //              is taken place. If calculated is 'true' but t is not TERM4 nor YEARLY then no calculation is taken place.
        void setTermReport(const e_term t, TermReport& tr, bool calculate=false);
        

};

#endif