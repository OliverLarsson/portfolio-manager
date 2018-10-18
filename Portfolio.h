/**
 * Portfolio.h
 * Header for the Portfolio class
*/ 

#ifndef _PORTFOLIO_H_
#define _PORTFOLIO_H_

// Libraries
#include <iostream> 
#include <vector>
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include "sqlite3.h" // header file for the SQLite database

using namespace std; 

// singleton implementation 
class Portfolio {
    public: 
        static Portfolio& GetInstance() {
            static Portfolio instance; 
            return instance; 
        }

        vector <string> portfolio_contents; // store the stocks that fit an investor in vector 

        void add_contents(); // adds contents to portfolio_contents 
        void print_portfolio(); // printing from the tickers and prices in portfolio contents
        double portfolio_value(); // calculate the value of the whole porfolio by price and units in Investor.portfolio table

        Portfolio(Portfolio const&) = delete; 
        void operator = (Portfolio const&) = delete; 

    private: 
        Portfolio(); // private constructor 

}; // class Portfolio

#endif //_PORTFOLIO_H_