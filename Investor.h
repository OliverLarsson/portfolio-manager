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
    Investor(string name, int age, int wealth, int risk_tolerance, int risk_required, Sector sector); // constructor

    string get_name() { return name_; }; // inline implementation
    int get_age() { return age_; }; // inline
    int get_wealth() { return wealth_; }; //inline
    int get_risk_tolerance() { return risk_tolerance_; }; //inline
    int get_risk_required() { return risk_required_; }; //inline
    int get_risk_capacity() {
        return 2; 
    };
    string get_sector(); 
    double risk_profile(); 

    private: 
    string name_; 
    int age_; 
    int wealth_; 
    int risk_tolerance_; // what the investor claims
    int risk_required_;
    Sector sector_; 

}; // class Investor

#endif //_INVESTOR_H_ 