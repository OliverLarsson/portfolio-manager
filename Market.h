/**
 * Market.h
 * Header for the Market class
*/ 

#ifndef _Market_H_
#define _Market_H_

// Libraries
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include <sqlite3.h> // header file for the SQLite database

using namespace std; 

// runs queries for stocks in decided sector
class Market {
    public: 
        Market(string sector); // constructor

        void market_controller(int option); 
        void print_options(); 
        void print_market();  
        void print_by_price(); 
        void print_by_ticker(); 
        void print_by_name(); 
        void print_by_variance(); 

    private: 
        string sector_; // needed for queries done by price, ticker, name, or variance

}; // class Market

#endif //_Market_H_ 