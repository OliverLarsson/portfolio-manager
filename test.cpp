/**
 * FIRST TEST CASES 
 * This file will be built on throughout the project.
 * It is intended to test the C++ method and field functionality of various classes. 
*/ 

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream> 

#include "Investor.h" 
#include "Assets.h"
#include "Portfolio.h"
#include "Forecast.h" 

using namespace std; 

TEST_CASE("Investor class methods", "[Investor]") {

  // Create an object to test on 
  Investor investor("Oliver", 21, 500000, 2, Sector::tech); 

  // Tests that constructor is dealing with parameters
  SECTION("Constructor check") {
    REQUIRE( investor.get_name() == "Oliver" );  
  }

  // Tests that the simple risk capacity function returns correctly 
  SECTION("Risk capacity") {
    REQUIRE( investor.get_risk_capacity() == 100000.0); 
  }
}