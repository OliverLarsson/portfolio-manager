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
        static Forecast* Create(forecast_method);

        void print_options(); 
        void print_info(int option); 

}; 

/** Derived classes
 * 
 * Industry: 
 *  - creates forecast based on the entire Market
 * 
 * Solo: 
 *  - creates forecast based on just the Portfolio 
 * 
 * Econometric: 
 *  - creates forecast based on both Market and Portfolio 
*/ 

class Industry: public Forecast {
    public: 
        void print_forecast() {
            cout << "Industry forecast method" << endl; 
        }
}; 

class Solo: public Forecast {
    public: 
        void print_forecast() {
            cout << "Solo forecast method" << endl; 
        }
};

class Econometric: public Forecast {
    public: 
        void print_forecast() {
            cout << "Econometric forecast method" << endl; 
        }
}; 

/**
 *  Client class 
*/ 

class Client {
    public: 
        Client(forecast_method type) {
            f_select = Forecast::Create(type); 
        }
        Forecast* get_forecast() {
            return f_select; 
        }
    private: 
        Forecast *f_select; 
};


#endif //_FORECAST_H_