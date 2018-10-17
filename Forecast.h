/**
 * Forecast.h
 * Header for the Portfolio class
*/ 

#ifndef _FORECAST_H_
#define _FORECAST_H_

// Libraries
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
*/

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