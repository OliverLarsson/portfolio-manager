/**
 * Market.cpp 
 * Deals with all information related to the financial assets 
*/ 

// Header file
#include "Market.h" 

// Libraries 
#include <iostream> 
//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include <sqlite3.h> // header file for the SQLite database

using namespace std; 

// Methods 

/**
 * callback
 * sqlite3 provided function for printing out sql queries 
*/
int Market::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++)
	{
		cout<<azColName[i]<<" = " << (argv[i] ? argv[i] : "NULL")<<"\n";
	}
	cout<<"\n";
	return 0;
}

/**
 * Constructor
 * Takes parameters for Market industry 
*/
Market::Market(string sector) {
    sector_ = sector; 
} 

/**
 * access_database
 * Needed each time market_controller is called to open the database connection 
*/ 
void Market::access_database(int option) {
    int option_tmp = option; 
    sqlite3 *db;
	char *zErrMsg = 0;
	const char *sql;
	int rc;
    
	rc = sqlite3_open("Investor.db", &db);

	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", zErrMsg);
	} 
	else
	{
		fprintf(stdout, "Open database successfully\n\n");
	}

    database_controller(option_tmp, db, zErrMsg, sql, rc); 
}

/**
 * database_controller
 * Function called for each market controller option aside from quit
 */ 
void Market::database_controller(int option, sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    if(option == 1) {
        print_market(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 2) {
        print_by_name(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 3) {
        print_by_ticker(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 4) {
        print_by_price(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 5) {
        print_by_variance(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
}

/**
 * print_options
 * Prints options for viewing the market  
*/
void Market::print_options() {
    cout << "View entire market info (1)." << endl;
    cout << "View market by asset name (2)." << endl;
    cout << "View market by asset ticker (3)." << endl;
    cout << "View market by asset price (4)." << endl;
    cout << "View market by asset variance (5)." << endl;
    cout << "Move on to your portfolio (6)." << endl;
} 

/**
 * market_controller
 * Controller for viewing market db 
 * Mainly to declutter main.cpp 
*/

void Market::market_controller(int option) {

    int option_;
    if(option == 1) {
        cout << "\nYou chose to view the entire market information." <<endl; 
        access_database(option); 
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 2) {
        cout << "\nYou chose to view the market by asset name." <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 3) {
        cout << "\nYou chose to view the market by asset ticker." <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 4) {
        cout << "\nYou chose to view the market by asset price." <<endl; 
        access_database(option); 
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 5) {
        cout << "\nYou chose to view the market by asset variance." <<endl; 
        access_database(option); 
        print_options();
        cin>> option_; 
        market_controller(option_); 
    }
    else if(option == 6) {
        cout << "\nYou chose to move on." <<endl; 
    }
    else {
        cout << "\nThat is not an option. Please choose one of the following" << endl;  
        print_options(); 
        cin>> option_; 
        market_controller(option_); 
    }

} 

/**
 * print_market
 * Queries entire db market  
*/
void Market::print_market(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "select * from market";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
} 

/**
 * print_by_name
 * Queries db market table by name  
*/
void Market::print_by_name(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "select * from market";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
} 

/**
 * print_by_ticker
 * Queries db market table by ticker  
*/
void Market::print_by_ticker(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "select * from market";
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
 * Queries db market table by price  
*/
void Market::print_by_price(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "select * from market";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
} 

/**
 * print_by_variance
 * Queries db market table by variance 
*/
void Market::print_by_variance(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "select * from market";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
} 