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

using namespace std; 

int main() {   

    string name; 
    double age; 
    double wealth;
    double risk_tolerance; 
    double risk_required; 
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
    cout << "It's important to consider how much growth you need to see in your portfolio." << endl;
    cout << "What would you consider to be your necessary financial gain?" << endl;
    cout << "   1. I cannot lose money. I would prefer to stay even over any monetary growth." <<endl;
    cout << "   2. I need to see at least 2% year-over-year growth." << endl; 
    cout << "   3. I need to see at least 5% year-over-year growth." << endl; 
    cout << "   4. I need to see at least 10% year-over-year growth." << endl; 
    cout << "   5. I need to see at least 15% year-over-year growth." << endl; 
    cin >> risk_required; 

    Investor investor(name, age, wealth, risk_tolerance, risk_required, sector); 

    cout << endl; 
    cout << "From what you provided, these are your attributes:" << endl; 
    cout << "   Name: " << investor.get_name() << "." << endl;
    cout << "   Age: " << investor.get_age() << "." << endl;
    cout << "   Wealth: " << investor.get_wealth() << "." << endl;
    cout << "   Sector preference: " << investor.get_sector() << "." << endl;

    cout << endl;
    cout << "Based on the risk assessment you provided: " << endl; 
    cout << "   Risk tolerance: " << investor.get_risk_tolerance() << "." << endl;
    cout << "   Risk required: " << investor.get_risk_required() << "." << endl;
    cout << "While considering your profile size:" << endl;
    cout << "   " << investor.get_wealth() << " dollars." <<endl; 
    cout << "We decided you have a risk capacity of " << investor.get_risk_capacity() << " dollars." << endl; 
    cout << "We believe you should have a " << investor.risk_profile() << " profile." << endl;
    cout << "Roughly, this will consist of: " << endl;
    cout << "   Equities, bonds, etc." << endl;








    
    return 0; 
}