/**
 * Assets.h
 * Header for the Assets class
*/ 

#ifndef _ASSETS_H_
#define _ASSETS_H_

// Libraries
#include <iostream> 

using namespace std; 

class Assets {
    public: 
    Assets(); 
    double calculate_risk(); 

    private: 
    double volatility_; // used as a parameter for calculating the risk of an asset 
                        // the more volatile/variance an asset has, the higher risk 
    

}; // class Assets

#endif //_ASSETS_H_ 