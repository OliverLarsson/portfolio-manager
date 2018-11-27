/**
 * Forecast.cpp 
 * Deals with all information related to the the portfolio of financial assets 
*/ 

// Header file
#include "Forecast.h" 

//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include <sqlite3.h> // header file for the SQLite database


// Libraries 
#include <iostream> 

using namespace std; 

// Methods 

/**
 * callback
 * sqlite3 provided function for printing out sql queries 
*/
int Forecast::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++)
	{
		cout<<azColName[i]<<" = " << (argv[i] ? argv[i] : "NULL") << "\n";
	}
	cout<<"\n";
	return 0;
}

/**
 * Factory method to create object
*/ 
Forecast * Forecast::Create(forecast_method type) {
    if(type == industry) {
        return new Industry(); 
    }
    else if(type == solo) {
        return new Solo(); 
    }
    else if(type == econometric) {
        return new Econometric(); 
    }
    else {
        return NULL; 
    }
}

/**
 * print_options
 * Prints options for viewing the portfolio  
*/
void Forecast::print_options() {
    cout << "   1. Forecasting by market" << endl; 
    cout << "   2. Forecasting by portfolio" << endl; 
    cout << "   3. Forecasting by entire economy" << endl; 
    cout << "   4. Move on " << endl; 
} 

/**
 * print_info
 * Prints info on user request 
*/ 
void Forecast::print_info(int option) {
    int option_; 
    if(option == 1) {
        cout << "Info on Market forecast" << endl;
        print_options(); 
        cin>>option_; 
        print_info(option_); 
    }
    else if(option == 2) { 
        cout << "Info on Solo forecast" << endl;
        print_options(); 
        cin>>option_; 
        print_info(option_); 
    }
    else if(option == 3) {
        cout << "Info on Econometric forecast" << endl; 
        print_options(); 
        cin>>option_; 
        print_info(option_); 
    }
    else if(option == 4) {
        cout << "Moving on" << endl; 
    }
    else {
        cout << "That is not an option. Please enter again." << endl; 
        print_options(); 
        cin >> option_; 
        print_info(option_); 
    }
}