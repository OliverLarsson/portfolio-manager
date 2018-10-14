/**
 * Oliver Larsson 
 * CU Boulder - CSCI 3010 - Felix Muzny 
 * Portfolio Manager Individual Project 
*/ 

// My header files 
#include "Investor.h" 
#include "Assets.h"
#include "Portfolio.h"
#include "Forecast.h" 

// Libraries 
#include <iostream> 
#include <stdio.h>  


using namespace std; 

int main() {   

    string name; 
    double age; 
    double wealth;
    double risk_tolerance; 
    Sector sector; 
    string sector_; 

    // Get parameters for Investor class
    cout << "Welcome to your Portfolio Manager! Please provide some more information about yourself." << endl; 
    cout << "What is your name? ";
    getline(cin, name); 
    cout << "What is your age? "; 
    cin >> age; 
    cout << "How much money do you have for your portfolio? (Please exclude $ and commas) "; 
    cin >> wealth; 
    cout << "Would you prefer to invest in technology (t) or industrial (i) businesses? "; 
    cin >> sector_; // cannot cin >> to an enum, so cin to string and assign to enum 
    if(sector_ == "t") {
        sector = Sector::tech;  
    } else {
        sector = Sector::industrial; 
    }   

    cout << endl;
    cout << "On a whole number scale of 1 to 10, 1 being lowest, how tolerant to investment risk are you? "; 
    cin >> risk_tolerance; 

    Investor investor(name, age, wealth, risk_tolerance, sector); 

    cout << endl; 
    cout << "From what you provided, these are your attributes:" << endl; 
    cout << "   Name: " << investor.get_name() << "." << endl;
    cout << "   Age: " << investor.get_age() << "." << endl;
    cout << "   Wealth: " << investor.get_wealth() << "." << endl;
    cout << "   Sector preference: " << investor.get_sector() << "." << endl;

    cout << endl;
    cout << "Based on the risk assessment you provided: " << endl; 
    cout << "   Risk tolerance: " << investor.get_risk_tolerance() << "." << endl;
    cout << "While considering your profile size:" << endl;
    cout << "   " << investor.get_wealth() << " dollars." <<endl; 
    cout << "And your age: " << endl;
    cout << "   " << investor.get_age() << " years old." << endl; 
    cout << "We decided you have a risk capacity of " << investor.get_risk_capacity() << " dollars." << endl; 
    cout << "We believe you should have a profile with " << investor.risk_profile() << "% securites, " << (100 - investor.risk_profile() - 5) << "% fixed incomes, and 5% cash." << endl; 
    cout << endl; 
    string yes; 
    cout << "Ready to move on to the portfolio? " << endl; 
    cin >> yes; 

    // Moving to Portfolio 
    double risk_requirement; 

    cout << endl; 
    cout << endl; 
    cout << "Now that we know more about you, we'll move on to which assets best fit your needs." << endl; 
    cout << endl; 
    cout << "On a whole number percentage scale of 0-100, what is your required return on investment (ROI)? " << endl; 
    cout << "Keep in mind that investing is a balance of risk vs reward. What you are requesting to gain, you must be willing to lose." << endl; 
    cout << "ROI: "; 
    cin >> risk_requirement; // compare this against their risk capacity 











    
    return 0; 
}