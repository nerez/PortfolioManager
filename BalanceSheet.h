#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include "Infrastructure.h"

struct Assets
{
    dollars cash;
};

struct Liabilities
{
    dollars short_term_debt;
};

struct Equity
{
    dollars equity;
    shares num_of_shares;
};

class BalanceSheet
{
    public:
        //Constructors
        BalanceSheet(Assets& a, Liabilities& l, Equity& e): assets(a), liabilities(l), equity(e){};
        
        //Getters
        Assets getAssets(){return assets;};
        Liabilities getLiabilities(){return liabilities;};
        Equity getEquity(){return equity;};
        
        //Setters
        void setAssets(Assets val){assets = val;};
        void setLiabilities(Liabilities val){liabilities = val;};
        void setEquity(Equity val){equity = val;};
        
    private:
        Assets       assets;
        Liabilities  liabilities;
        Equity       equity;
};


#endif
