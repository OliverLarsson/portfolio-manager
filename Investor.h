/**
 * Investor.h
 * Header for the Investor class
*/ 

#ifndef _INVESTOR_H_
#define _INVESTOR_H_

// Libraries
#include <iostream> 

using namespace std; 

enum class Sector { tech, industrial };

class Investor {
    public: 
    Investor(string name, double age, double wealth, double risk_tolerance, double risk_required, Sector sector); // constructor

    string get_name() { return name_; }; // inline implementation
    double get_age() { return age_; }; // inline
    double get_wealth() { return wealth_; }; //inline
    double get_risk_tolerance() { return risk_tolerance_; }; //inline
    double get_risk_required() { return risk_required_; }; //inline
    double get_risk_capacity() { return ((wealth_ * (risk_tolerance_ / 10))); };
    string get_sector(); 
    double risk_profile(); 

    private: 
    string name_; 
    double age_; 
    double wealth_; 
    double risk_tolerance_; // what the investor claims
    double risk_required_;
    Sector sector_; 

}; // class Investor

#endif //_INVESTOR_H_ 