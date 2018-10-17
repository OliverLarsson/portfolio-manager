/**
 * Investor.cpp 
 * Deals with all information related to the investor 
*/ 

// Header file
#include "Investor.h" 

// Libraries 
#include <iostream> 
#include <iterator>
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
*/

using namespace std; 

// Methods 

/** 
 * Constructor
 * Takes four parameters from user input: age, wealth, risk tolerance, and sector preference
*/ 
Investor::Investor(string name, double age, double wealth, double risk_tolerance, Sector sector) {
    name_ = name; 
    age_ = age; 
    wealth_ = wealth; 
    risk_tolerance_ = risk_tolerance; 
    sector_ = sector; 
}

/**
 * get_sector
 * Can't cout an enum type 
*/ 
string Investor::get_sector() { // might use a map here if it's necessary / more efficient ... not sure yet 
    string sec; 
    if(sector_ == Sector::tech) {
        sec = "Technology"; 
    }
    else {
        sec = "Industrial"; 
    }
    return sec; 
}

/**
 * risk_profile
 * Takes age, wealth, and three risk attributes from the Investor object
 * Creates a risk profile based on age and risk tolerance
 * Returns a double from 0-1, 0 being the lowest risk tolerance 
*/ 
double Investor::risk_profile() {
    if(age_ > 20 && age_ < 40) { //
        if(risk_tolerance_ >=1 && risk_tolerance_ < 3) {
            return 70.0; 
        }
        else if(risk_tolerance_ >=4 && risk_tolerance_ < 7) {
            return 80.0; 
        }
        else if(risk_tolerance_ >= 7 && risk_tolerance_ < 10) {
            return 90.0; 
        }
        else {
            return 100.0; 
        }
    }
    else if(age_ >= 40 && age_ < 60) {
        if(risk_tolerance_ >=1 && risk_tolerance_ < 3) {
            return 50.0; 
        }
        else if(risk_tolerance_ >=4 && risk_tolerance_ < 7) {
            return 60.0; 
        }
        else if(risk_tolerance_ >= 7 && risk_tolerance_ < 10) {
            return 70.0; 
        }
        else {
            return 80.0; 
        }
    }
    else if(age_ >= 60 && age_ < 70) {
        if(risk_tolerance_ >=1 && risk_tolerance_ < 3) {
            return 30.0; 
        }
        else if(risk_tolerance_ >=4 && risk_tolerance_ < 7) {
            return 40.0; 
        }
        else if(risk_tolerance_ >= 7 && risk_tolerance_ < 10) {
            return 50.0; 
        }
        else {
            return 60.0; 
        }
    }
    else if(age_ >= 70) {
        if(risk_tolerance_ >=1 && risk_tolerance_ < 3) {
            return 10.0;
        }
        else if(risk_tolerance_ >=4 && risk_tolerance_ < 7) {
            return 20.0; 
        }
        else if(risk_tolerance_ >= 7 && risk_tolerance_ < 10) {
            return 30.0; 
        }
        else {
            return 40.0; 
        }
    }
    else {
        cout << "Your are too young to be investing!" << endl; 
        return 0; 
    }
}