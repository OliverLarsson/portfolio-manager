/**
 * Forecast.h
 * Header for the Portfolio class
*/ 

#ifndef _FORECAST_H_
#define _FORECAST_H_

// Libraries
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include <sqlite3.h> // header file for the SQLite database


using namespace std; 

/** Forecasting methods (classes) include:
 * Industry-wide (Industry class)
 * Porfolio-specific (Solo class)
 * Econometric (Econometric class)
*/ 

enum forecast_method{industry, solo, econometric}; 

/**
 *  Base class
*/ 
class Forecast {
    public: 
        virtual void print_forecast() = 0; 
        static Forecast* Create(forecast_method, string);
        static int callback(void *NotUsed, int argc, char **argv, char **azColName); // done
        void print_options(); 
        void print_create(); 
        void print_info(int option); 
        void forecast_handler(int option, string sector); 
}; 

/** Derived classes
 * 
 * Each forecast takes a desired confidence interval and returns three optional growth predictions
 * 
 * Z-scores: 
 *      - 99% = 2.576
 *      - 95% = 1.96
 *      - 90% = 1.645
 * Z-score is a standardized stat that accounts for sample size and the desired confidence interval 
 * 
 * Confidence Interval = Sample Mean +/- Z-score * (Standard Deviation / sqrt(Sample Size))
 * 
 * Confidence interval will give a portfolio growth estimate based on historical stats
 * 
 * Industry: 
 *  - creates forecast based on the industry you chose 
 * 
 * Solo: 
 *  - creates forecast based on just your portfolio 
 * 
 * Econometric: 
 *  - creates forecast based on all industries aka entire "market" table
*/ 
class Industry: public Forecast {
    public: 
        Industry(string sector) {
            sector_ = sector; // This is the only forecast constructor that needs to be dealt with because of sector 
        }
        void print_forecast(); 
    private: 
        string sector_; 
}; 

class Solo: public Forecast {
    public:  
        Solo(string sector) {
            sector_ = sector; 
        }
        void print_forecast(); 
    private: 
        string sector_; 
};

class Econometric: public Forecast {
    public: 
        Econometric(string sector) {
            sector_ = sector; 
        }
        void print_forecast();
    private: 
        string sector_; 
}; 

/**
 *  Client class 
*/ 

class Client {
    public: 
        Client(forecast_method type, string sector) {
            f_select = Forecast::Create(type, sector);
        }
        Forecast* get_forecast() {
            return f_select; 
        }
    private: 
        Forecast *f_select;  
};


#endif //_FORECAST_H_