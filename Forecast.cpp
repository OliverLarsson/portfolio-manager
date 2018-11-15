/**
 * Forecast.cpp 
 * Deals with all information related to the the portfolio of financial assets 
*/ 

// Header file
#include "Forecast.h" 

//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include <sqlite3.h> // header file for the SQLite database


// Libraries 
#include <iostream> 

using namespace std; 

// Methods 

/**
 * Factory method to create object
*/ 
Forecast * Forecast::Create(forecast_method type) {
    if(type == industry) {
        return new Industry(); 
    }
    else if(type == solo) {
        return new Solo(); 
    }
    else if(type == econometric) {
        return new Econometric(); 
    }
}