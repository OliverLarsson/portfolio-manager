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
Investor::Investor(string name, int age, int wealth, int risk_tolerance, int risk_required, Sector sector) {
    name_ = name; 
    age_ = age; 
    wealth_ = wealth; 
    risk_tolerance_ = risk_tolerance; 
    risk_required_ = risk_required; 
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
 * Creates a risk profile based on _____
 * Returns a double from 0-1, 0 being the lowest risk tolerance 
*/ 
double Investor::risk_profile() {
    return get_risk_capacity() + risk_required_ + risk_tolerance_; 
}