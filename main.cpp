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
#include <istream> 

using namespace std; 

int main() {

    int age; 
    int wealth;
    int risk; 
    Sector sector; 
    string sector_; 
    
    // Get parameters for Investor class
    cout << "Welcome to your Portfolio Manager! Please provide some more information about yourself." << endl; 
    cout << "What is your age? "; 
    cin >> age; 
    cout << "How much money do you have for your portfolio? (Please exclude $ and commas) "; 
    cin >> wealth; 
    cout << "On a whole number scale of 1 to 10, 1 being lowest, how tolerant to investment risk are you? "; 
    cin >> risk; 
    cout << "Would you prefer to invest in technology (t) or industrial (i) businesses? "; 
    cin >> sector_; // cannot cin >> to an enum, so cin to string and assign to enum 
    if(sector_ == "t") {
        sector = Sector::tech;  
    } else if(sector_ == "i") {
        sector = Sector::industrial; 
    } else {
        cout << "That is not a sector. Please enter technology (t) or industrial (i): ";
        cin >> sector_;
    }

    Investor investor(age, wealth, risk, sector); 







    
    return 0; 
}