/**
 * Investor.h
 * Header for the Investor class
*/ 

#ifndef _INVESTOR_H_
#define _INVESTOR_H_

// Libraries
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 

using namespace std; 

enum class Sector { tech, industrial };

class Investor {
    public: 
    Investor(string name, double age, double wealth, double risk_tolerance, double risk_requirement_, Sector sector); // constructor

    /**
     * Below are inline method implementations to get an Investor object's attributes
    */ 
    string get_name() { return name_; }; 
    double get_age() { return age_; }; 
    double get_wealth() { return wealth_; }; 
    double get_risk_tolerance() { return risk_tolerance_; }; 
    double get_risk_capacity() { 
        return ((wealth_*(risk_tolerance_/100)) + (wealth_*(risk_requirement_/100))); 
    }
    double get_risk_requirement() { return risk_requirement_; }
    string get_sector(); 
    double risk_profile(); 

    private: 
    string name_; 
    double age_; 
    double wealth_; 
    double risk_tolerance_; 
    double risk_requirement_; 
    Sector sector_; 

}; // class Investor

#endif //_INVESTOR_H_ 