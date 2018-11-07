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
 * print_market
 * Queries entire db market  
*/
void Market::print_market() {

} 

/**
 * print_by_price
 * Queries db market table by price  
*/
void Market::print_by_price() {

} 

/**
 * print_by_ticker
 * Queries db market table by ticker  
*/
void Market::print_by_ticker() {

} 

/**
 * print_by_name
 * Queries db market table by name  
*/
void Market::print_by_name() {

} 

/**
 * print_by_variance
 * Queries db market table by variance 
*/
void Market::print_by_variance() {

} 