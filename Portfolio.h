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
#include <sqlite3.h> // header file for the SQLite database

using namespace std; 

/**
 * Singleton implementation 
*/ 
class Portfolio {
    public: 
        static Portfolio& GetInstance() {
            static Portfolio instance; 
            return instance; 
        }

        // Database handlers 
        static int callback(void *NotUsed, int argc, char **argv, char **azColName);
        void access_database(int option); 
        void database_controller(int option, sqlite3 *db, char *zErrMsg, const char *sql, int rc); 
        void portfolio_controller(int option); 

        void print_options(); 
        void add_contents(); // adds contents to portfolio_contents 
        void print_portfolio(sqlite3 *db, char *zErrMsg, const char *sql, int rc);
        void print_by_units(sqlite3 *db, char *zErrMsg, const char *sql, int rc);
        void print_by_price(sqlite3 *db, char *zErrMsg, const char *sql, int rc);
        double portfolio_value(); // calculate the value of the whole porfolio by price and units in Investor.portfolio table

        Portfolio(Portfolio const&) = delete; 
        void operator = (Portfolio const&) = delete; 

    private: 
        Portfolio(); // private constructor 

}; // class Portfolio

#endif //_PORTFOLIO_H_