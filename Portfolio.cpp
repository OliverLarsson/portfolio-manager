/**
 * Portfolio.cpp 
 * Deals with all information related to the the portfolio of financial assets 
*/ 

// Header file
#include "Portfolio.h" 

// Libraries 
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include <sqlite3.h> // header file for the SQLite database

using namespace std;

// Methods 

/** 
 * Constructor ? 
*/ 

/**
 * callback
 * sqlite3 provided function for printing out sql queries 
*/
int Portfolio::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++)
	{
		cout<<azColName[i]<<" = " << (argv[i] ? argv[i] : "NULL");
	}
	cout<<"\n";
	return 0;
}

/**
 * access_database
 * Called by market_controller 
 * Needed each time market_controller is called to open the database connection 
*/ 
void Portfolio::access_database(int option) {
    int option_tmp = option; 
    sqlite3 *db;
	char *zErrMsg = 0;
	const char *sql;
	int rc;
    
	rc = sqlite3_open("Investor.db", &db);

	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", zErrMsg);
	} else {
		fprintf(stdout, "Open database successfully\n\n");
	}

    database_controller(option, db, zErrMsg, sql, rc); 
}

/**
 * database_controller
 * Called by access_database, which opens the database connection 
 * Function called for each market controller option aside from quit
 * Directs the user input option to the function needed for that query 
 * Closes database connection each time 
 */ 
void Portfolio::database_controller(int option, sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    if(option == 1) {
        print_portfolio(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 2) {
        print_by_units(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 3) {
        print_by_price(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
}

/**
 * portfolio_controller
 * Called in main.cpp and directs all other functions in class 
 * Controller for viewing portfolio table 
*/
void Portfolio::portfolio_controller(int option) {

    int option_;
    if(option == 1) {
        cout << "\nYou chose to view the entire market information." <<endl; 
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 2) {
        cout << "\nYou chose to view the market by asset name." <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 3) {
        cout << "\nYou chose to view the market by asset ticker." <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 6) {
        cout << "\nYou chose to move on." <<endl; 
    }
    else {
        cout << "\nThat is not an option. Please choose one of the following" << endl;  
        print_options(); 
        cin>> option_; 
        portfolio_controller(option_); 
    }

} 

/**
 * print_options
 * Prints options for viewing the portfolio  
*/
void Portfolio::print_options() {
    cout << "View entire portfolio info (1)." << endl;
    cout << "View portfolio in order of units (2)." << endl;
    cout << "View portfolio in order of price (3)." << endl;
    cout << "Move on to your forecast (4)." << endl;
} 

/**
 * print_portfolio
 * Prints entire contents of portfolio table
*/
void Portfolio::print_portfolio(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT * FROM portfolio";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
}

/**
 * print_by_units
 * Prints contents of portfolio table in unit order 
*/ 
void Portfolio::print_by_units(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT * FROM portfolio ORDER BY units";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
}

/**
 * print_by_price
 * Prints contents of portfolio table in price order 
*/ 
void Portfolio::print_by_price(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT * FROM portfolio ORDER BY price";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
}
