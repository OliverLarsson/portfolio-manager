/**
 * Investor.cpp 
 * Deals with all information related to the investor 
*/ 

// Header file
#include "Investor.h" 

// Libraries 
#include <iostream> 

using namespace std; 

// Methods 

/** 
 * Constructor
 * Takes four parameters from user input: age, wealth, risk tolerance, and sector preference
*/ 
Investor::Investor(string name, int age, int wealth, int risk, Sector sector) {
    name_ = name; 
    age_ = age; 
    wealth_ = wealth; 
    risk_ = risk; 
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