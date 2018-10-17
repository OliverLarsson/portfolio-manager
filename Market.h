/**
 * Market.h
 * Header for the Market class
*/ 

#ifndef _Market_H_
#define _Market_H_

// Libraries
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 

using namespace std; 

// runs queries for stocks in decided sector
class Market {
    public: 
       Market(string sector); 

       void print_market(); // prints Technology if Market object created with t and Industrial if created with i 
       void print_by_price(); // prints a specific query based on the price limit a user gives 
       void print_by_ticker(); // prints the information of an asset by ticker 
       void print_by_name(); // prints the information of an asset by name 
       void print_by_variance(); // prints the information of an asset by YTD variance limit

    private: 
        string sector_; // needed for queries done by price, ticker, name, or variance

}; // class Market

#endif //_Market_H_ 