#ifndef CashFlow_H
#define CashFlow_H

#include "Infrastructure.h"

struct Operations
{
    dollars sum;
    
    //Operators
    Operations& operator+=(const Operations& other)
    {
        sum += other.sum;
    }
    
    Operations& operator-=(const Operations& other)
    {
        sum -= other.sum;
    }
};

inline Operations operator+(Operations left, const Operations& right)
{
    left += right;
    return left;
}

inline Operations operator-(Operations left, const Operations& right)
{
    left -= right;
    return left;
}

struct Financing
{
    dollars sum;
    
    //Operators
    Financing& operator+=(const Financing& other)
    {
        sum += other.sum;
    }
    
    Financing& operator-=(const Financing& other)
    {
        sum -= other.sum;
    }
};

inline Financing operator+(Financing left, const Financing& right)
{
    left += right;
    return left;
}

inline Financing operator-(Financing left, const Financing& right)
{
    left -= right;
    return left;
}


struct Investing
{
    dollars sum;
    
    //Operators
    Investing& operator+=(const Investing& other)
    {
        sum += other.sum;
    }
    
    Investing& operator-=(const Investing& other)
    {
        sum -= other.sum;
    }
};

inline Investing operator+(Investing left, const Investing& right)
{
    left += right;
    return left;
}

inline Investing operator-(Investing left, const Investing& right)
{
    left -= right;
    return left;
}



class CashFlow
{
        public:
        //Constructors
        CashFlow(){};
        CashFlow(Operations& o, Financing& f, Investing& i): operations(o), financing(f), investing(i){};
        
        //Getters
        Operations getOperations(){return operations;};
        Financing getFinancing(){return financing;};
        Investing getInvesting(){return investing;};
        
        //Setters
        void setOperations(Operations val){operations = val;};
        void setFinancing(Financing val){financing = val;};
        void setInvesting(Investing val){investing = val;};
        
    //Operators
    CashFlow& operator+=(const CashFlow& other)
    {
        operations += other.operations;
        financing  += other.financing;
        investing  += other.investing;
    }
    
    CashFlow& operator-=(const CashFlow& other)
    {
        operations -= other.operations;
        financing  -= other.financing;
        investing  -= other.investing;
    }
    
    private:
        Operations      operations;
        Financing       financing;
        Investing       investing;
        
};

inline CashFlow operator+(CashFlow left, const CashFlow& right)
{
    left += right;
    return left;
}

inline CashFlow operator-(CashFlow left, const CashFlow& right)
{
    left -= right;
    return left;
}
        
#endif
