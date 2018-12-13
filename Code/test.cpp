//get capacity 

/**
 * FIRST TEST CASES 
 * This file will be built on throughout the project.
 * It is intended to test the C++ method and field functionality of various classes. 
*/ 

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 

#include "Investor.h" 
#include "Market.h"
#include "Portfolio.h"
#include "Forecast.h" 

using namespace std; 

TEST_CASE("Investor class methods", "[Investor]") {

  // Create an object to test on 
  Investor investor("Oliver", 21, 500000, 2, 45, Sector::tech); 

  // Tests that constructor is dealing with parameters
  SECTION("Constructor check") {
    REQUIRE( investor.get_name() == "Oliver" );
    REQUIRE( investor.get_age() == 21 );  
    REQUIRE( investor.get_wealth() == 500000 );  
    REQUIRE( investor.get_risk_tolerance() == 2 ); 
    REQUIRE( investor.get_risk_capacity() == 235000.0); 
    REQUIRE( investor.get_sector() == "Technology" );  
  }

  // Tests that the simple risk capacity function returns correctly 
  //SECTION("Risk capacity") {
    //REQUIRE( investor.get_risk_capacity() == 100000.0); 
  //}

  // Tests that the risk profile returns correctly based on age and risk tolerance 
  SECTION("Risk Profile") {
    REQUIRE( investor.risk_profile() == 70.0);
  }
}

TEST_CASE("Market class methods", "[Market]") {
  
  // Create object 
  Market market("t"); 

  SECTION("Constructor check") {
    REQUIRE( market.get_sector() == "t"); 
  }
}

TEST_CASE("Portfolio class methods", "[Portfolio]") {
  // Object 
  Portfolio& portfolio = Portfolio::GetPortfolio();

  portfolio.get_worth(100000); 
  portfolio.set_risk_capacity(20); 
  portfolio.set_risk_tolerance(2); 

  portfolio.risk_path(); 

  SECTION("Path") {
    REQUIRE(portfolio.get_risk_path() == 1); 
  }
}

/**
 * Forecasting testing
 * 
 * Not a whole lot I felt I could test because of the design pattern
 *  and that most of the functionality is in SQLite, which can't be 
 *  tested here. 
 */ 

