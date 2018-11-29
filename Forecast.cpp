/**
 * Forecast.cpp 
 * Deals with all information related to the the portfolio of financial assets 
*/ 

// Header file
#include "Forecast.h" 

//#include <Ultralight/Ultralight.h> // include for Ultralight API 
#include <sqlite3.h> // header file for the SQLite database
#include <cmath> 


// Libraries 
#include <iostream> 

using namespace std; 

// Methods 

/**
 * sqlite_power
 * 
 * Creates a SQL POWER() aggregate function 
 * 
 * Some aggregate functions need to be implemented manually since SQLite only comes standard with a few.
 * This particular function is NOT my own implementation!
 * It is from here: https://stackoverflow.com/questions/13190064/how-to-find-power-of-a-number-in-sqlite
 * 
 * NOTE:  I point this out in the README.md and Checkpoint 5 doc, but the implementation 
 *        comes with a warning for an unused "int res = …". This variable is needed to call the 
 *        aggregate function but the compiler doesn't understand. Ignore the warning same as the linker warnings. :)  
*/ 
void sqlite_power(sqlite3_context *context, int argc, sqlite3_value **argv) {
    double num = sqlite3_value_double(argv[0]); // get the first arg to the function
    double exp = sqlite3_value_double(argv[1]); // get the second arg
    double res = pow(num, exp);                 // calculate the result
    sqlite3_result_double(context, res);        // save the result
}

/**
 * callback
 * sqlite3 provided function for printing out sql queries 
*/
int Forecast::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++)
	{
		cout<< (argv[i] ? argv[i] : "NULL");
	}
	
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
    cout << "   1. Learn about forecasting by market." << endl; 
    cout << "   2. Learn about forecasting by portfolio." << endl; 
    cout << "   3. Learn about forecasting by entire economy." << endl; 
    cout << "   4. Move on to your forecasting choice." << endl; 
} 

/**
 * print_info
 * Prints info on user request 
*/ 
void Forecast::print_info(int option) {
    int option_; 
    if(option == 1) {
        cout << "The market forecast takes all the financial assets within the sector that you chose to invest into account." << endl;
        cout << "This style of forecasting offers insight into how the rest of the industry is acting and the possible growth in your portfolio. " << endl; 
        print_options(); 
        cin>>option_; 
        print_info(option_); 
    }
    else if(option == 2) { 
        cout << "The solo forecast takes only the financial assets within your portfolio into account. " << endl;
        cout << "This style of forecasting offers insight into how your portfolio has acted in the past and how it could grow in the future." << endl; 
        print_options(); 
        cin>>option_; 
        print_info(option_); 
    }
    else if(option == 3) {
        cout << "The econometric forecast takes the entire economy into account. This includes all financial assets within all sectors." << endl; 
        cout << "This style of forecasting offers insight into how your portfolio might grow based on how the entire economy has acted. " << endl; 
        cout << "Since big shifts in the economy (recessions, depressions, booms, etc.) affect all industries, this is an important forecast ";
        cout << "to conduct from a broad view. " << endl; 
        print_options(); 
        cin>>option_; 
        print_info(option_); 
    }
    else if(option == 4) {
        cout << "Moving on to your forecasting choice." << endl; 
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
    cout << "Please enter an option (without '%') for confidence level. \nThe higher the confidence, the wider the range of portfolio value." << endl; 
    cout << "   - 99%" << endl; 
    cout << "   - 95%" << endl; 
    cout << "   - 90%" << endl; 
    cin >> option; 
    int res = sqlite3_create_function(db, "POWER", 2, SQLITE_UTF8, NULL, &sqlite_power, NULL, NULL);
    if(option == 99) { 
        sql = "SELECT (SELECT (SELECT AVG(market.change) + 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(change) AS a FROM market) AS sub) / POWER(COUNT(*),.5) FROM market) AS ChangeTop"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 95) {
        sql = "SELECT (SELECT (SELECT AVG(market.change) + 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(change) AS a FROM market) AS sub) / POWER(COUNT(*),.5) FROM market) AS ChangeTop"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 90) {
        sql = "SELECT (AVG(change/price) + 1.645*((MAX(change) - MIN(change))/count(*))) AS Change FROM market WHERE sector = 't' or sector = 'e'"; 
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
    cout << "Please enter an option (without '%') for confidence level. \nThe higher the confidence, the wider the range of portfolio value." << endl; 
    cout << "   - 99%" << endl; 
    cout << "   - 95%" << endl; 
    cout << "   - 90%" << endl; 
    cin >> option; 

    if(option == 99) { 
        sql = "SELECT (AVG(m.change/m.price) + 2.576*((MAX(m.change) - MIN(m.change))/(SELECT count(*) FROM portfolio))) AS Change FROM market m, portfolio p WHERE p.ticker = m.ticker"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 95) {
        sql = "SELECT (AVG(m.change/m.price) + 1.96*((MAX(m.change) - MIN(m.change))/(SELECT count(*) FROM portfolio))) AS Change FROM market m, portfolio p WHERE p.ticker = m.ticker"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 90) {
        sql = "SELECT (AVG(m.change/m.price) + 1.645*((MAX(m.change) - MIN(m.change))/(SELECT count(*) FROM portfolio))) AS Change FROM market m, portfolio p WHERE p.ticker = m.ticker"; 
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
    int res = sqlite3_create_function(db, "POWER", 2, SQLITE_UTF8, NULL, &sqlite_power, NULL, NULL);
    int option; 
    cout << "\nPlease enter an option (without '%') for confidence level. \nThe higher the confidence, the wider the range of portfolio value." << endl; 
    cout << "   - 99%" << endl; 
    cout << "   - 95%" << endl; 
    cout << "   - 90%" << endl; 
    cin >> option; 
    cout << "\nGiven the current economic standing, we are " << option << "% confident that your portfolio's value" << endl;
    cout << "will change between the following percentages in the next year:\n[";

    if(option == 99) { 
        sql = "SELECT (SELECT ROUND(SELECT (SELECT AVG(market.change) - 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(change) AS a FROM market) AS sub) / ROUND(POWER(COUNT(*),.5) FROM market))"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        cout << ",";
        sql = "SELECT (SELECT (SELECT AVG(market.change) + 2.576 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(change) AS a FROM market) AS sub) / POWER(COUNT(*),.5) FROM market)"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 95) {
        sql = "SELECT (SELECT ROUND(SELECT (SELECT AVG(market.change) - 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(change) AS a FROM market) AS sub) / ROUND(POWER(COUNT(*),.5) FROM market))"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        cout << ",";
        sql = "SELECT (SELECT (SELECT AVG(market.change) + 1.96 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(change) AS a FROM market) AS sub) / POWER(COUNT(*),.5) FROM market)"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    else if(option == 90) {
        sql = "SELECT (SELECT ROUND(SELECT (SELECT AVG(market.change) - 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(change) AS a FROM market) AS sub) / ROUND(POWER(COUNT(*),.5) FROM market))"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        cout << ",";
        sql = "SELECT (SELECT (SELECT AVG(market.change) + 1.645 * AVG((market.change-sub.a) * (market.change-sub.a)) AS var FROM market, (SELECT AVG(change) AS a FROM market) AS sub) / POWER(COUNT(*),.5) FROM market)"; 
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
    }
    cout << "]." << endl; 
}