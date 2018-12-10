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
#include <chrono> 
#include <thread> 

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // ns, us, ms, s, h, etc.


int main() {
    
    string name;
    double age;
    string wealth_;
    double wealth; 
    double risk_tolerance; 
    Sector sector;
    string sector_;
    double risk_requirement;

    /**
     * Start TextUI 
     * Gather user input for Investor object instantiation
    */ 
    cout << "\n\n\e[1mWelcome to your Portfolio Manager! Please provide some more information about yourself.\e[0m" << endl;
    cout << "\e[1mWhat is your name?\e[0m ";
    getline(cin, name);
    cout << "\e[1mHi, " << name << "\e[1m. What is your age?\e[0m ";
    cin >> age;
    if(age < 18) {
        cout << "\e[1mYou are too young to invest!\e[0m" << endl; 
        exit(0); 
    }
    cout << "\e[1mHow much money do you have for your portfolio? \nWe have a minimum of $11k to ensure proper diversification. (Please exclude $ and commas) \e[0m";
    cin >> wealth;
    if(wealth < 11000) {
        cout << "\e[1mSorry, your investment doesn't reach our minimum.\e[0m" << endl; 
        exit(0); 
    }
    cout << "\e[1mWould you prefer to invest in technology (t) or industrial (i) businesses? \e[0m"; 
    cin >> sector_; // cannot cin >> to an enum, so cin to string and assign to enum
    if(sector_ == "t") {
        sector = Sector::tech;
    } else {
        sector = Sector::industrial;
    }

    cout << endl;
    cout << "\e[1mLet's talk about risk.\e[0m" << endl;
    cout << "\e[1mRisk is any uncertainty within investing that may lead to a negative financial impact.\e[0m" << endl;
    cout << "\e[1mOn a whole number scale of 1 to 10, 1 being lowest, how tolerant to investment risk are you? \e[0m";
    cin >> risk_tolerance; 
    while(risk_tolerance < 1 or risk_tolerance > 10) {
        cout << "\e[1mPlease enter a value between 1 and 10. \e[0m" << endl; 
        cin >> risk_tolerance; 
    }
    cout << endl;
    cout << "\e[1mOn a whole number percentage scale of 0-100, what is your required return on investment (ROI)? \e[0m" << endl;
    cout << "\e[1mKeep in mind that investing is a balance of risk vs reward. What you are requesting to gain, you must be willing to lose.\e[0m" << endl;
    cout << "\e[1mROI: \e[0m";
    cin >> risk_requirement; // compare this against their risk capacity
    while(risk_requirement < 0 or risk_requirement > 100) {
        cout << "\e[1mPlease enter a value between 0 and 100. \e[0m" << endl; 
        cin >> risk_requirement; 
    }

    /**
     * Creating Investor object 
    */ 
    Investor investor(name, age, wealth, risk_tolerance, risk_requirement, sector);

    cout << endl;
    cout << "\e[1mFrom what you provided, these are your attributes:\e[0m" << endl;
    cout << "   \e[1mName:\e[0m " << investor.get_name() << "\e[1m.\e[0m" << endl;
    cout << "   \e[1mAge:\e[0m " << investor.get_age() << "\e[1m.\e[0m" << endl;
    cout << "   \e[1mWealth:\e[0m $" << investor.get_wealth() << "\e[1m.\e[0m" << endl;
    cout << "   \e[1mSector preference:\e[0m " << investor.get_sector() << "\e[1m.\e[0m" << endl;

    cout << endl;
    cout << "\e[1mLooking at your answers on risk: " << endl;
    cout << "   \e[1mRisk tolerance:\e[0m " << investor.get_risk_tolerance() << "\e[1m." << endl;
    cout << "   \e[1mRisk requirement:\e[0m " << investor.get_risk_requirement() << "\e[1m." << endl; 
    cout << "\e[1mWe decided you have a risk capacity of \e[0m$" << investor.get_risk_capacity() << "\e[1m.\e[0m" << endl;
    cout << "\e[1mWe believe you should have a profile with\e[0m " << investor.risk_profile() << "\e[1m% stocks,\e[0m " << (100 - investor.risk_profile() - 5) << "\e[1m% ETFs, and\e[0m \e[1m5%\e[0m \e[1mcash.\e[0m" << endl;
    cout << endl;

    // Market and Portfolio class implementations 
    
    /**
     * Creating Market object 
    */

    Market market(sector_); // creating market object with their sector preference 

    int option; 
    cout << "\e[1mEarlier you selected\e[0m " << investor.get_sector() << " \e[1mas your preferred sector.\e[0m" << endl;
    cout << "\e[1mPlease select options to view the financial assets in this sector.\e[0m" << endl;
    cout << "\e[1mIf you would like to move on to your Portfolio without viewing the markets, enter '6'. \e[0m" << endl;
    cout << "\e[1mHere are your market options:\e[0m " << endl; 
    
    market.print_options(); 
    cin >> option; 
    if(option != 6) { 
        market.market_controller(option); 
    } else {
        cout << "\n\e[1mYou've selected to move on to your portfolio. Let's check it out!\e[0m" << endl;
    }

    /** 
     * Creating Portfolio object 
    */ 
    string yes; 
    cout << "\e[1mReady to view your Portfolio?\e[0m " << endl; 
    cin >> yes; // break in info
    Portfolio& portfolio = Portfolio::GetPortfolio(); // singleton implementation 
    portfolio.delete_contents(); // in case user quit out early on last play 

    double a = investor.get_risk_capacity();
    double b = investor.risk_profile(); 
    portfolio.set_risk_capacity(a); 
    portfolio.set_risk_profile(b); 
    portfolio.set_risk_tolerance(risk_tolerance); 
    portfolio.get_worth(wealth - (wealth * .05)); // account for cash in portfolio 
    portfolio.risk_path(); 
    cout << "\n\e[1mFirst we're going to match \e[0m" << investor.risk_profile() << "\e[1m% of your portfolio with stocks.\e[0m" << endl; 
    cout << "\e[1mBecause of your risk tolerance of\e[0m " << investor.get_risk_tolerance() << " \e[1mand your risk capacity of \e[0m$" << investor.get_risk_capacity() << "\e[1m,\e[0m" << endl; 
    cout << "\e[1mthese stocks will be on a level\e[0m " << portfolio.get_risk_path() << " \e[1mrisk path, where 1 is the lowest and 9 is the highest.\e[0m" << endl; 
    
    cout << "\n\e[1mBuilding your portfolio\e[0m" << endl; 

    sleep_for(milliseconds(500));

    cout << "..." << endl;

    sleep_for(milliseconds(500));

    cout << "..." << endl;

    sleep_for(milliseconds(500));

    cout << "..." << endl;

    sleep_for(milliseconds(500));
    
    portfolio.add_contents(sector_); 
    cout << "\e[1mDone!\e[0m" << endl; 

    portfolio.set_units(wealth); 

    sleep_for(milliseconds(1000));

    cout << "\n\e[1mPlease select options to view your Portfolio.\e[0m" << endl; 
    cout << "\e[1mIf you would like to move on to the forecast, enter '9'.\e[0m" << endl; 
    cout << "\e[1mere are your options: \e[0m" << endl; 

    portfolio.print_options(); 
    cin >> option; 
    if(option != 9) {
        portfolio.portfolio_controller(option);
    } else {
        cout << "\n\e[1mYou've selected to move on to the forecast. Let's see how your money might grow!\e[0m" << endl; 
    }
    
    /** 
     * Creating Forecast object 
    */ 

    // null assignment until user's input is processed 
    Forecast * f_select = nullptr;

    cout << "\e[1mForecasting can be done through a variety of methods. To learn more about each method, select its number.\e[0m " << endl;
    cout << "\e[1mIf you would like to move on to your choice, enter '4'.\e[0m" << endl; 
    cout << "\e[1mMethod information:\e[0m" << endl; 
    f_select->print_options(); 
    cin >> option; 
    if(option != 4) {
        f_select->print_info(option);
    } else {
        cout << "\n\e[1mYou've selected to move on to the forecast choice.\e[0m" << endl; 
    }
    
    cout << "\e[1mWhich forecast method would you like to use? \e[0m" << endl; 
    cout << "\e[1mIf you would like to wrap things up, enter '4'.\e[0m" << endl; 
    cout << "\e[1mForecasts:\e[0m" << endl; 
    f_select->print_create(); 
    cin >> option; 
    if(option != 4) {
        f_select->forecast_handler(option, sector_);
    } else {
        cout << "\n\e[1mYou've selected to wrap things up.\e[0m" << endl; 
    }

    cout << "\n\n\e[1mThanks for playing!\e[0m\n\n"; 
 
    portfolio.delete_contents(); 
    return 0;
}
