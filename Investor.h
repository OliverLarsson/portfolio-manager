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
    Investor(int age, int wealth, int risk, Sector sector); // constructor

    int get_age() { return age_; }; // inline implementation 
    int get_wealth() { return wealth_; }; //inline
    int get_risk() { return risk_; }; //inline
    Sector get_sector() { return sector_; }; 

    private: 
    int age_; 
    int wealth_; 
    int risk_; // what the investor claims
    Sector sector_; 
    int risk_profile; // what is calculated by Investor::risk_profile; 

}; // class Investor

#endif //_INVESTOR_H_ 