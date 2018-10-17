/**
 * Market.h
 * Header for the Market class
*/ 

#ifndef _Market_H_
#define _Market_H_

// Libraries
#include <iostream> 

using namespace std; 

// might also be singleton? 
class Market {
    public: 
        Market(string ticker, double price, double variance, double sector); 

        void fill_market(); // my idea is to fill a vector with structs that will be used by the Portfolio class 
                            // structs are filled with 
        void print_market(string ticker_); // print the asset by ticker and price 
        double calculate_risk(); // calculate the risk of an asset by it's year-to-date variance and current price 

    private: 
        // fields all used for calculation and/or printing 
        string ticker_; 
        double price_; 
        double variance_; 
        double sector_; 

}; // class Market

#endif //_Market_H_ 