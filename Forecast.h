/**
 * Forecast.h
 * Header for the Portfolio class
*/ 

#ifndef _FORECAST_H_
#define _FORECAST_H_

// Libraries
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 

using namespace std; 

class Forecast {
    public: 
        Forecast(double value, double variance, double risk); 

        double calculate_value(); // calculate value of the future portfolio based on current value, variance, and risk 
        double calculate_risk(); // calculate future risk 
        double calculate_growth(); // calculate future growth 

    private: 
        double value_; 
        double variance_; 
        double risk_; 

}; // class Forecast

#endif //_FORECAST_H_