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
        void get_worth(double worth) {
            worth_ = worth; 
        }

        // Database handlers 
        static int callback(void *NotUsed, int argc, char **argv, char **azColName); // done
        //int callback2(void *NotUsed, int argc, char **argv, char **azColName); 
        //int callback3(void *NotUsed, int argc, char **argv, char **azColName);
        void access_database(int option); // done
        void database_controller(int option, sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void portfolio_controller(int option); // done
        int get_value(); 
        void print_options(); // done
        void add_contents(string sector); 
        void delete_contents(); // done
        void print_portfolio(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_by_ticker(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_by_units(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_by_price(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_avg_change(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_value(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done
        void print_avg_val(sqlite3 *db, char *zErrMsg, const char *sql, int rc); 
        void print_avg_unit(sqlite3 *db, char *zErrMsg, const char *sql, int rc); // done 

        void set_risk_capacity(double risk_capacity) { risk_capacity_ = risk_capacity; }
        void set_risk_tolerance(double risk_tolerance) { risk_tolerance_ = risk_tolerance; }
        void set_risk_profile(double risk_profile) { risk_profile = risk_profile_; }
        void risk_path(); 
        int get_risk_path() {
            return path_; 
        }

        Portfolio(Portfolio const&) = delete; 
        void operator = (Portfolio const&) = delete; 

    private: 
        Portfolio(); 
        string sector_; 
        double worth_; 
        double risk_capacity_; 
        double risk_tolerance_; 
        double risk_profile_; 
        int path_; // variable of which types of stocks will be selected 

}; // class Portfolio

#endif //_PORTFOLIO_H_