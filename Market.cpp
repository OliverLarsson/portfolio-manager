/**
 * Market.cpp 
 * Deals with all information related to the financial assets 
*/ 

// Header file
#include "Market.h" 

// Libraries 
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include <sqlite3.h> // header file for the SQLite database

using namespace std; 

// Methods 

/**
 * Constructor
 * Takes parameters for Market industry 
*/
Market::Market(string sector) {
    sector_ = sector; 

} 

/**
 * print_options
 * Prints options for viewing the market  
*/
void Market::print_options() {
    cout << "View entire market info (1)." << endl;
    cout << "View market by asset name (2)." << endl;
    cout << "View market by asset ticker (3)." << endl;
    cout << "View market by asset price (4)." << endl;
    cout << "View market by asset variance (5)." << endl;
    cout << "Move on to your portfolio (6)." << endl;
} 

/**
 * market_controller
 * Controller for viewing market db 
 * Mainly to declutter main.cpp 
*/
void Market::market_controller(int option) {
    int option_; 
    if(option == 1) {
        cout << "You chose to view the entire market information." <<endl; 
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 2) {
        cout << "You chose to view the market by asset name." <<endl;
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 3) {
        cout << "You chose to view the market by asset ticker." <<endl;
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 4) {
        cout << "You chose to view the market by asset price." <<endl; 
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 5) {
        cout << "You chose to view the market by asset variance." <<endl; 
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 6) {
        cout << "You chose to move on." <<endl; 
    }
    else {
        cout << "That is not an option. Please choose one of the following" << endl;  
        print_options(); 
        cin>> option_; 
        market_controller(option_); 
    }
} 

/**
 * print_market
 * Queries entire db market  
*/
void Market::print_market() {

} 

/**
 * print_by_name
 * Queries db market table by name  
*/
void Market::print_by_name() {

} 

/**
 * print_by_ticker
 * Queries db market table by ticker  
*/
void Market::print_by_ticker() {

} 

/**
 * print_by_price
 * Queries db market table by price  
*/
void Market::print_by_price() {

} 

/**
 * print_by_variance
 * Queries db market table by variance 
*/
void Market::print_by_variance() {

} 