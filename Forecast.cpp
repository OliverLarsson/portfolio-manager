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

/**
 * Industry::print_forecast()
 * 
 * Industry class' forecast
*/ 
void Industry::print_forecast() {
    sqlite3 *db;
    char *zErrMsg = 0;
    const char *sql;
    int rc;
    rc = sqlite3_open("Investor.db", &db);
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", zErrMsg);
    } 
    int option; 
    cout << "Please enter an option for confidence level. \nThe higher the confidence, the wider the range of portfolio value." << endl; 
    cout << "   1. 99%" << endl; 
    cout << "   2. 95%" << endl; 
    cout << "   3. 90%" << endl; 
    cin >> option; 

    if(option == 1) { 
        sql = "SELECT AVG(change/price) + 2.576*( (SELECT MAX(change/price))-(SELECT MIN(change/price))/(SELECT count(*) FROM portfolio)) AS Change FROM market WHERE sector = 't' or sector = 'e'"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 2) {
        sql = "SELECT AVG(change/price) + 1.96*( (SELECT MAX(change/price))-(SELECT MIN(change/price))/(SELECT count(*) FROM portfolio)) AS Change FROM market WHERE sector = 't' or sector = 'e' ORDER BY "; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 3) {
        sql = "SELECT AVG(change/price) + 1.645*( (SELECT MAX(change/price))-(SELECT MIN(change/price))/(SELECT count(*) FROM portfolio)) AS Change FROM market WHERE sector = 't' or sector = 'e'"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
}

/**
 * Solo::print_forecast()
 * 
 * Solo class' forecast
*/ 
void Solo::print_forecast() {
    sqlite3 *db;
    char *zErrMsg = 0;
    const char *sql;
    int rc;
    rc = sqlite3_open("Investor.db", &db);
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", zErrMsg);
    } 
    int option; 
    cout << "Please enter an option for confidence level. \nThe higher the confidence, the wider the range of portfolio value." << endl; 
    cout << "   1. 99%" << endl; 
    cout << "   2. 95%" << endl; 
    cout << "   3. 90%" << endl; 
    cin >> option; 

    if(option == 1) { 
        sql = "SELECT AVG(m.change/m.price) + 2.576*( (SELECT MAX(m.change/m.price))-(SELECT MIN(m.change/m.price))/(SELECT count(*) FROM portfolio)) AS Change FROM market m, portfolio p WHERE m.ticker = p.ticker"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 2) {
        sql = "SELECT AVG(m.change/m.price) + 1.96*( (SELECT MAX(m.change/m.price))-(SELECT MIN(m.change/m.price))/(SELECT count(*) FROM portfolio)) AS Change FROM market m, portfolio p WHERE m.ticker = p.ticker"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 3) {
        sql = "SELECT AVG(m.change/m.price) + 1.645*( (SELECT MAX(m.change/m.price))-(SELECT MIN(m.change/m.price))/(SELECT count(*) FROM portfolio)) AS Change FROM market m, portfolio p WHERE m.ticker = p.ticker"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
}

/**
 * Econometric::print_forecast()
 * 
 * Econometric class' forecast
*/ 
void Econometric::print_forecast() {
    sqlite3 *db;
    char *zErrMsg = 0;
    const char *sql;
    int rc;
    rc = sqlite3_open("Investor.db", &db);
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", zErrMsg);
    } 
    int option; 
    cout << "Please enter an option for confidence level. \nThe higher the confidence, the wider the range of portfolio value." << endl; 
    cout << "   1. 99%" << endl; 
    cout << "   2. 95%" << endl; 
    cout << "   3. 90%" << endl; 
    cin >> option; 

    if(option == 1) { 
        sql = "SELECT AVG(change/price) + 2.576*( (SELECT MAX(change/price))-(SELECT MIN(change/price))/(SELECT count(*) FROM portfolio)) AS Change FROM market"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 2) {
        sql = "SELECT AVG(change/price) + 1.96*( (SELECT MAX(change/price))-(SELECT MIN(change/price))/(SELECT count(*) FROM portfolio)) AS Change FROM market"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 3) {
        sql = "SELECT AVG(change/price) + 1.645*( (SELECT MAX(change/price))-(SELECT MIN(change/price))/(SELECT count(*) FROM portfolio)) AS Change FROM market"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
}