#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include "Infrastructure.h"

struct Assets
{
    dollars cash;
    
    //Operators
    Assets& operator+=(const Assets& other)
    {
        cash += other.cash;
    }
    
    Assets& operator-=(const Assets& other)
    {
        cash -= other.cash;
    }
};

inline Assets operator+(Assets left, const Assets& right)
{
    left += right;
    return left;
}

inline Assets operator-(Assets left, const Assets& right)
{
    left -= right;
    return left;
}


struct Liabilities
{
    dollars short_term_debt;
    
    //Operators
    Liabilities& operator+=(const Liabilities& other)
    {
        short_term_debt += other.short_term_debt;
    }
    
    Liabilities& operator-=(const Liabilities& other)
    {
        short_term_debt -= other.short_term_debt;
    }
};

inline Liabilities operator+(Liabilities left, const Liabilities& right)
{
    left += right;
    return left;
}

inline Liabilities operator-(Liabilities left, const Liabilities& right)
{
    left -= right;
    return left;
}


struct Equity
{
    dollars equity;
    shares num_of_shares;
    
    //Operators
    Equity& operator+=(const Equity& other)
    {
        equity += other.equity;
        num_of_shares += other.num_of_shares;
    }
    
    Equity& operator-=(const Equity& other)
    {
        equity -= other.equity;
        num_of_shares -= other.num_of_shares;
    }
};

inline Equity operator+(Equity left, const Equity& right)
{
    left += right;
    return left;
}

inline Equity operator-(Equity left, const Equity& right)
{
    left -= right;
    return left;
}

class BalanceSheet
{
    public:
        //Constructors
        BalanceSheet(){};
        BalanceSheet(Assets& a, Liabilities& l, Equity& e): assets(a), liabilities(l), equity(e){};
        
        //Getters
        Assets getAssets(){return assets;};
        Liabilities getLiabilities(){return liabilities;};
        Equity getEquity(){return equity;};
        
        //Setters
        void setAssets(Assets val){assets = val;};
        void setLiabilities(Liabilities val){liabilities = val;};
        void setEquity(Equity val){equity = val;};
        
        //Operators
        BalanceSheet& operator+=(const BalanceSheet& other)
        {
            assets += other.assets;
            liabilities += other.liabilities;
            equity += other.equity;
        }
        
        BalanceSheet& operator-=(const BalanceSheet& other)
        {
            assets -= other.assets;
            liabilities -= other.liabilities;
            equity -= other.equity;
        }
        
    private:
        Assets       assets;
        Liabilities  liabilities;
        Equity       equity;
};

inline BalanceSheet operator+(BalanceSheet left, const BalanceSheet& right)
{
    left += right;
    return left;
}

inline BalanceSheet operator-(BalanceSheet left, const BalanceSheet& right)
{
    left -= right;
    return left;
}

#endif
