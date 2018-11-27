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
    cout << "Welcome to your Portfolio Manager! Please provide some more information about yourself." << endl;
    cout << "What is your name? ";
    getline(cin, name);
    cout << "Hi, " << name << ". What is your age? ";
    cin >> age;
    if(age < 18) {
        cout << "You are too young to invest!" << endl; 
        exit(0); 
    }
    cout << "How much money do you have for your portfolio? (Please exclude $ and commas) ";
    cin >> wealth_;
    wealth = stod(wealth_); 
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
    while(risk_tolerance < 1 or risk_tolerance > 10) {
        cout << "Please enter a value between 1 and 10. " << endl; 
        cin >> risk_tolerance; 
    }
    cout << endl;
    cout << "On a whole number percentage scale of 0-100, what is your required return on investment (ROI)? " << endl;
    cout << "Keep in mind that investing is a balance of risk vs reward. What you are requesting to gain, you must be willing to lose." << endl;
    cout << "ROI: ";
    cin >> risk_requirement; // compare this against their risk capacity
    while(risk_requirement < 0 or risk_requirement > 100) {
        cout << "Please enter a value between 0 and 100. " << endl; 
        cin >> risk_requirement; 
    }

    /**
     * Creating Investor object 
    */ 
    Investor investor(name, age, wealth, risk_tolerance, risk_requirement, sector);

    cout << endl;
    cout << "From what you provided, these are your attributes:" << endl;
    cout << "   Name: " << investor.get_name() << "." << endl;
    cout << "   Age: " << investor.get_age() << "." << endl;
    cout << "   Wealth: $" << investor.get_wealth() << "." << endl;
    cout << "   Sector preference: " << investor.get_sector() << "." << endl;

    cout << endl;
    cout << "Looking at your answers on risk: " << endl;
    cout << "   Risk tolerance: " << investor.get_risk_tolerance() << "." << endl;
    cout << "   Risk requirement: " << investor.get_risk_requirement() << "." << endl; 
    cout << "We decided you have a risk capacity of $" << investor.get_risk_capacity() << endl;
    cout << "We believe you should have a profile with " << investor.risk_profile() << "% stocks, " << (100 - investor.risk_profile() - 5) << "% ETFs, and 5% cash." << endl;
    cout << endl;

    // Market and Portfolio class implementations 
    
    /**
     * Creating Market object 
    */

    Market market(sector_); // creating market object with their sector preference 

    int option; 
    cout << "Earlier you selected " << investor.get_sector() << " as your preferred sector." << endl;
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
    string yes; 
    cout << "Ready to view your Portfolio? " << endl; 
    cin >> yes; // break in info
    Portfolio& portfolio = Portfolio::GetPortfolio(); // singleton implementation 

    double a = investor.get_risk_capacity();
    double b = investor.risk_profile(); 
    portfolio.set_risk_capacity(a); 
    portfolio.set_risk_profile(b); 
    portfolio.set_risk_tolerance(risk_tolerance); 

    portfolio.get_worth(wealth_); 
    portfolio.risk_path(); 
    cout << "\nFirst we're going to match " << investor.risk_profile() << "% of your portfolio with stocks." << endl; 
    cout << "Because of your risk tolerance of " << investor.get_risk_tolerance() << " and your risk capacity of $" << investor.get_risk_capacity() << "," << endl; 
    cout << "these stocks will be on a level " << portfolio.get_risk_path() << " risk path, where 1 is the lowest and 9 is the highest." << endl; 
    
    cout << "Building your portfolio" << endl; 

    sleep_for(seconds(1));

    cout << "..." << endl;

    sleep_for(seconds(1));

    cout << "..." << endl;

    sleep_for(seconds(1));

    cout << "..." << endl;

    sleep_for(seconds(1));
    
    portfolio.add_contents(sector_); 
    cout << "Done! " << endl; 

    cout << "\nPlease select options to view your Portfolio." << endl; 
    cout << "If you would like to move on to the forecast, enter '9'." << endl; 
    cout << "Here are your options: " << endl; 

    portfolio.print_options(); 
    cin >> option; 
    if(option != 9) {
        portfolio.portfolio_controller(option);
    } else {
        cout << "\nYou've selected to move on to the forecast. Let's see how your money might grow!" << endl; 
    }
    
    /** 
     * Creating Forecast object 
    */ 

    Client *f_client = nullptr;
    Forecast * f_select = nullptr;

    cout << "Forecasting can be done through a variety of methods. To learn more about each method, select its number. " << endl; 
    f_select->print_options(); 
    cin >> option; 
    if(option != 4) {
        f_select->print_info(option);
    } else {
        cout << "\nYou've selected to move on" << endl; 
    }

    cout << "Which forecast method would you like to use? " << endl; 
    f_select->print_options(); 
    cin>> option; 
    if(option == 1) {
        f_client = new Client(industry); 
        f_select = f_client->get_forecast(); 
        f_select->print_forecast();
    }
    else if(option == 2) {
        f_client = new Client(solo);
        f_select = f_client->get_forecast();
        f_select->print_forecast(); 
    }
    else if(option == 3) {
        f_client = new Client(solo);
        f_select = f_client->get_forecast();
        f_select->print_forecast(); 
    }
    

    portfolio.delete_contents(); 
    return 0;
}
