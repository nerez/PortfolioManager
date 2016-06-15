#ifndef COMPANY_H 
#define COMPANY_H

#include "YearlyTermReport.h"
#include <string>
#include <map>


class Company 
{    
    private:
        std::map<Year, YearlyTermReport> reports_list;
        std::string name;
        dollars current_market_price;
        
    public:
        //Constructors
        Company(){};
        Company(std::string _name): name(_name){};
        
        //Getters
        YearlyTermReport& getYearlyTermReport(const Year y);
        std::string getCompanyName();
        dollars getCurrentMarketPrice();
        
        //Setters
        void insertYearlyTermReport(Year y, YearlyTermReport ytr);
        void setCompanyName(std::string name);
};

#endif