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

        static int callback(void *NotUsed, int argc, char **argv, char **azColName);
        void access_database(int option); 
        void database_controller(int option, sqlite3 *db, char *zErrMsg, const char *sql, int rc); 
        void market_controller(int option); 
        void print_options(); 
        void print_market(sqlite3 *db, char *zErrMsg, const char *sql, int rc);  
        void print_by_price(sqlite3 *db, char *zErrMsg, const char *sql, int rc); 
        void print_by_ticker(sqlite3 *db, char *zErrMsg, const char *sql, int rc); 
        void print_by_name(sqlite3 *db, char *zErrMsg, const char *sql, int rc); 
        void print_by_variance(sqlite3 *db, char *zErrMsg, const char *sql, int rc); 

    private: 
        string sector_; // needed for queries done by price, ticker, name, or variance

}; // class Market

#endif //_Market_H_ 