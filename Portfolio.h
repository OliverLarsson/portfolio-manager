/**
 * Portfolio.h
 * Header for the Portfolio class
*/ 

#ifndef _PORTFOLIO_H_
#define _PORTFOLIO_H_

// Libraries
#include <iostream> 

using namespace std; 

// singleton implementation 
class Portfolio {
    public: 
        static Portfolio& GetInstance() {
            static Portfolio instance; 
            return instance; 
        }

        void fill_portfolio(); 
        void print_portfolio(vector <struct> asset_vec); // printing from the tickers and prices in a map parameter
        double portfolio_value(); // calculate the value of the whole porfolio 

        Portfolio(Portfolio const&) = delete; 
        void operator = (Portfolio const&) = delete; 

    private: 
        Portfolio(); // private constructor 

}; // class Portfolio

#endif //_PORTFOLIO_H_