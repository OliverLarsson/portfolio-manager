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
Investor::Investor(int age, int wealth, int risk, Sector sector) {
    age_ = age; 
    wealth_ = wealth; 
    risk_ = risk; 
    sector_ = sector; 
}

/**
 * 
 * 
*/ 
