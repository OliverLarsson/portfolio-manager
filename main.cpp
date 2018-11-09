/**
 * Oliver Larsson
 * CU Boulder - CSCI 3010 - Felix Muzny
 * Portfolio Manager Individual Project
*/

// My header files
#include "Investor.h"
#include "Market.h"
#include "Portfolio.h"
#include "Forecast.h"
//$(Users/Ollie/Documents/Project/portfolio-manager/Ultralight)/include/ -> put in the include directories in XCode
// $(Users/Ollie/Documents/Project/portfolio-manager/Ultralight)/deps/ -> also
//#include <Ultralight/Ultralight.h> // include for Ultralight API

// Libraries
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> // header file for the SQLite database

using namespace std;

int main() {
    
    string name;
    double age;
    double wealth;
    double risk_tolerance;
    Sector sector;
    string sector_;

    /**
     * Start TextUI 
     * Gather user input for Investor object instantiation
    */ 
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
    cout << "Let's talk about risk." << endl;
    cout << "Risk is any uncertainty within investing that may lead to a negative financial impact." << endl;
    cout << "On a whole number scale of 1 to 10, 1 being lowest, how tolerant to investment risk are you? ";
    cin >> risk_tolerance;

    /**
     * Creating Investor object 
    */ 
    Investor investor(name, age, wealth, risk_tolerance, sector);

    cout << endl;
    cout << "From what you provided, these are your attributes:" << endl;
    cout << "   Name: " << investor.get_name() << "." << endl;
    cout << "   Age: " << investor.get_age() << "." << endl;
    cout << "   Wealth: " << investor.get_wealth() << "." << endl;
    cout << "   Sector preference: " << investor.get_sector() << "." << endl;

    cout << endl;
    cout << "Based on the answers you provided: " << endl;
    cout << "   Risk tolerance: " << investor.get_risk_tolerance() << "." << endl;
    cout << "   Profile size: " << investor.get_wealth() << " dollars." <<endl;
    cout << "   Your age: " << investor.get_age() << " years old." << endl;
    cout << "We decided you have a risk capacity of " << investor.get_risk_capacity() << " dollars." << endl;
    cout << "We believe you should have a profile with " << investor.risk_profile() << "% securites, " << (100 - investor.risk_profile() - 5) << "% fixed incomes, and 5% cash." << endl;
    cout << endl;

    // Market and Portfolio class implementations 

    // This is just to slow down the Text UI since there's a break in topics/classes 
    string yes;
    cout << "Ready to move on to the portfolio? " << endl;
    cin >> yes;


    // risk_requirement will be used in the Porfolio object 
    double risk_requirement;

    cout << endl;
    cout << endl;
    cout << "Now that we know more about you, we'll move on to which assets best fit your needs." << endl;
    cout << endl;
    cout << "On a whole number percentage scale of 0-100, what is your required return on investment (ROI)? " << endl;
    cout << "Keep in mind that investing is a balance of risk vs reward. What you are requesting to gain, you must be willing to lose." << endl;
    cout << "ROI: ";
    cin >> risk_requirement; // compare this against their risk capacity
    
    /**
     * Creating Market object 
    */

    Market market(sector_); // creating market object with their sector preference 

    int option; 
    cout << "Earlier you selected " << sector_ << " as your preferred sector." << endl;
    cout << "Please select options to view the financial assets in this sector." << endl;
    cout << "If you would like to move on to your Portfolio without viewing the markets, enter '6'. " << endl;
    cout << "Here are your market options: " << endl; 
    
    market.print_options(); 
    cin >> option; 
    if(option != 6) { 
        market.market_controller(option); 
    } else {
        cout << "\nYou've selected to move on to your portfolio. Let's check it out!" << endl;
    }

    /** 
     * Creating Portfolio object 
    */ 

    cout << "Ready to view your Portfolio? " << endl; 
    cin >> yes; // break in info
    Portfolio& portfolio = Portfolio::GetPortfolio(); // singleton implementation 

    
    cout << "Adding" << endl; 
    portfolio.add_contents(sector_); 
    cout << "Added" << endl; 

    cout << "Your portfolio contains financial assets from the " << portfolio.get_sector(sector_) << " sector." << endl; 
    cout << "Please select options to view your Portfolio." << endl; 
    cout << "If you would like to move on to the forecast, enter '8'." << endl; 
    cout << "Here are your options: " << endl; 

    portfolio.print_options(); 
    cin >> option; 
    if(option != 8) {
        portfolio.portfolio_controller(option);
    } else {
        cout << "\nYou've selected to move on to the forecast. Let's see how your money might grow!" << endl; 
    }

    portfolio.delete_contents(); // have to delete the portfolio table contents or else they'll stay for next run through of this program 
    
    /** 
     * Creating Forecast object 
    */ 

   // we need to pass some values of the portfolio through to the Forecast object 
   // double value = portfolio.get_value(); 
   // double avg_change = portfolio.get_change(); 
   // double avg_vol = portfolio.get_volatility(); 

   // Forecast forecast(value, avg_change, avg_vol); 

   








    return 0;
}
