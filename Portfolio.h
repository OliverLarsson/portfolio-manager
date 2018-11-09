/**
 * Portfolio.h
 * Header for the Portfolio class
*/ 

#ifndef _PORTFOLIO_H_
#define _PORTFOLIO_H_

// Libraries
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include <sqlite3.h> // header file for the SQLite database

using namespace std; 

/**
 * Singleton implementation 
*/ 
class Portfolio {
    public: 
        static Portfolio& GetPortfolio() {
            static Portfolio portfolio; 
            return portfolio; 
        }

        // Database handlers 
        static int callback(void *NotUsed, int argc, char **argv, char **azColName); // done
        void access_database(int option); // done
        void database_controller(int option, sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void portfolio_controller(int option); // done

        string get_sector(string sector) { 
            sector_ = sector; 
            return sector_; 
        } // done 
        void print_options(); // done
        void add_contents(string sector); 
        void delete_contents();
        void print_portfolio(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_by_ticker(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_by_units(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_by_price(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_value(sqlite3 *db, char *zErrMsg, const char *sql, int rc); 
        void print_avg_val(sqlite3 *db, char *zErrMsg, const char *sql, int rc); 
        void print_avg_unit(sqlite3 *db, char *zErrMsg, const char *sql, int rc); 
        double portfolio_value(); 




        Portfolio(Portfolio const&) = delete; 
        void operator = (Portfolio const&) = delete; 

    private: 
        Portfolio(); 
        string sector_; 

}; // class Portfolio

#endif //_PORTFOLIO_H_