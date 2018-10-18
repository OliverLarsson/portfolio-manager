/**
 * Investor.h
 * Header for the Investor class
*/ 

#ifndef _INVESTOR_H_
#define _INVESTOR_H_

// Libraries
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include "sqlite3.h" // header file for the SQLite database

using namespace std; 

enum class Sector { tech, industrial };

class Investor {
    public: 
    Investor(string name, double age, double wealth, double risk_tolerance, Sector sector); // constructor

    /**
     * Below are inline method implementations to get an Investor object's attributes
    */ 
    string get_name() { return name_; }; 
    double get_age() { return age_; }; 
    double get_wealth() { return wealth_; }; 
    double get_risk_tolerance() { return risk_tolerance_; }; 
    double get_risk_capacity() { return (wealth_ * (risk_tolerance_ / 10)); };
    string get_sector(); 
    double risk_profile(); 

    private: 
    string name_; 
    double age_; 
    double wealth_; 
    double risk_tolerance_; 
    Sector sector_; 

}; // class Investor

#endif //_INVESTOR_H_ 