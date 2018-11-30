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
 * Constructor 
*/ 
Portfolio::Portfolio() {
}

/** 
 * add_contents
 * Adds assets from the market table to the portfolio table 
*/ 
void Portfolio::add_contents(string sector) {
    sqlite3 *db;
	char *zErrMsg = 0;
	const char *sql;
	int rc;
    
	rc = sqlite3_open("Investor.db", &db);

	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", zErrMsg);
	} 
    /**
     * To-do: Where clause to keep profile below investor's worth
     *         ASAP: implement risk_profile_ % of stocks first 
     * 
     * DEPENDENT ON: 
     * subtract 5% from worth_ to account for 5% requirement
     * risk_profile_ * worth_ amount of 't' or 'i' that follow the volume / change track 
     * (100 - risk_profile_) * worth_ amount of 'e' that follow the volume / change track
     * LIMIT = 25 so all portfolios are equally diversified
     * OFFSET = x to reflect increasing risk as trade volume and price change increase 
    */ 
    if(sector == "t") { // markets 't' & 'e' have 159 rows, 159/9 = ~18, so each bracket has 18 assets 
        if(path_ == 1) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' or sector = 'e' ORDER BY volume, change ASC LIMIT 18 OFFSET 0"; 
        }
        else if(path_ == 2) {  
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' or sector = 'e' ORDER BY volume, change ASC LIMIT 18 OFFSET 18";
        }
        else if(path_ == 3) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' or sector = 'e' ORDER BY volume, change ASC LIMIT 18 OFFSET 36";
        }
        else if(path_ == 4) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' or sector = 'e' ORDER BY volume, change ASC LIMIT 18 OFFSET 54";
        }
        else if(path_ == 5) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' or sector = 'e' ORDER BY volume, change ASC LIMIT 18 OFFSET 72";
        }
        else if(path_ == 6) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' or sector = 'e' ORDER BY volume, change ASC LIMIT 18 OFFSET 90";
        }
        else if(path_ == 7) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' or sector = 'e' ORDER BY volume, change ASC LIMIT 18 OFFSET 108";
        }
        else if(path_ == 8) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' or sector = 'e' ORDER BY volume, change ASC LIMIT 18 OFFSET 126";
        }
        else {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 't' or sector = 'e' ORDER BY volume, change ASC LIMIT 18 OFFSET 141";  
        }
        
    } else {
        if(path_ == 1) { // markets 'i' & 'e' have 122 rows, 122/9 = ~14, so each bracket has 14 assets 
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' or sector = 'e' ORDER BY volume, change ASC LIMIT 14 OFFSET 0";
        }
        else if(path_ == 2) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' or sector = 'e' ORDER BY volume, change ASC LIMIT 14 OFFSET 14";
        }
        else if(path_ == 3) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' or sector = 'e' ORDER BY volume, change ASC LIMIT 14 OFFSET 28";
        }
        else if(path_ == 4) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' or sector = 'e' ORDER BY volume, change ASC LIMIT 14 OFFSET 42";
        }
        else if(path_ == 5) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' or sector = 'e' ORDER BY volume, change ASC LIMIT 14 OFFSET 56";
        }
        else if(path_ == 6) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' or sector = 'e' ORDER BY volume, change ASC LIMIT 14 OFFSET 70";
        }
        else if(path_ == 7) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' or sector = 'e' ORDER BY volume, change ASC LIMIT 14 OFFSET 84";
        }
        else if(path_ == 8) {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' or sector = 'e' ORDER BY volume, change ASC LIMIT 14 OFFSET 98";
        }
        else {
            sql = "INSERT INTO portfolio (ticker, units) SELECT ticker, 1 FROM market WHERE sector = 'i' or sector = 'e' ORDER BY volume, change ASC LIMIT 14 OFFSET 108";
        }

    }
   
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
    sqlite3_close(db);
}
/** 
 * delete_contents
 * Need to delete the Portfolio table contents each time
*/ 
void Portfolio::delete_contents() {
    sqlite3 *db;
	char *zErrMsg = 0;
	const char *sql;
	int rc;
    
	rc = sqlite3_open("Investor.db", &db);

	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", zErrMsg);
	} 
    sql = "DELETE FROM portfolio"; 
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
    sqlite3_close(db);
}

/**
 * callback
 * sqlite3 provided function for printing out sql queries 
*/
int Portfolio::callback(void *NotUsed, int argc, char **argv, char **azColName)
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
 * access_database
 * Called by market_controller 
 * Needed each time market_controller is called to open the database connection 
*/ 
void Portfolio::access_database(int option) {
    sqlite3 *db;
	char *zErrMsg = 0;
	const char *sql;
	int rc;
    
	rc = sqlite3_open("Investor.db", &db);

	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", zErrMsg);
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
        print_by_ticker(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 3) {
        print_by_units(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 4) {
        print_by_price(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 5) {
        print_value(db, zErrMsg, sql, rc); 
        sqlite3_close(db);
    }
    else if(option == 6) {
        print_avg_val(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 7) {
        print_avg_unit(db, zErrMsg, sql, rc);
        sqlite3_close(db);
    }
    else if(option == 8) {
        print_avg_change(db, zErrMsg, sql, rc);
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
        cout << "\nYou chose to view your entire portfolio information.\n" <<endl; 
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 2) {
        cout << "\nYou chose to view your portfolio in order of ticker.\n" <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 3) {
        cout << "\nYou chose to view your portfolio in order of units.\n" <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 4) {
        cout << "\nYou chose to view your portfolio in order of price.\n" <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 5) {
        cout << "\nYou chose to view your portfolio's value.\n" <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 6) {
        cout << "\nYou chose to view the average asset price in your portfolio.\n" <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 7) {
        cout << "\nYou chose to view the average units held of assets in your portfolio.\n" <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 8) {
        cout << "\nYou chose to view the average change of assets in your portfolio.\n" <<endl;
        access_database(option); 
        print_options();
        cin>> option_; 
        portfolio_controller(option_); 
    }
    else if(option == 9) {
        cout << "\nYou chose to move on to the forecast.\n" <<endl; 
    }
    else {
        cout << "\nThat is not an option. Please choose one of the following:" << endl;  
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
    cout << "   1. View entire portfolio info" << endl;
    cout << "   2. View portfolio in order of ticker" << endl;
    cout << "   3. View portfolio in order of units" << endl;
    cout << "   4. View portfolio in order of price" << endl;
    cout << "   5. View your portfolio value" << endl;
    cout << "   6. View the average asset price" << endl;
    cout << "   7. View the average units of assets held" << endl;
    cout << "   8. View the average change of assets held" << endl;
    cout << "   9. Move on to your forecast" << endl;
} 

/**
 * print_portfolio
 * Prints entire contents of portfolio table
*/
void Portfolio::print_portfolio(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT m.name, p.ticker, p.units FROM portfolio p, market m WHERE p.ticker = m.ticker";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

/**
 * print_by_ticker
 * Queries db portfolio table by ticker  
*/
void Portfolio::print_by_ticker(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT m.name, p.ticker, p.units FROM portfolio p, market m WHERE p.ticker = m.ticker ORDER BY p.ticker ASC";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
} 

/**
 * print_by_units
 * Prints contents of portfolio table in unit order 
*/ 
void Portfolio::print_by_units(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT m.name, p.ticker, p.units FROM portfolio p, market m WHERE p.ticker = m.ticker ORDER BY p.units DESC";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

/**
 * print_by_price
 * Prints contents of market table in price order of ticker in portfolio table
*/ 
void Portfolio::print_by_price(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT m.name, p.ticker, p.units, m.price FROM portfolio p, market m WHERE p.ticker = m.ticker ORDER BY m.price DESC";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

/**
 * print_value
 * Value of entire portfolio
*/ 
void Portfolio::print_value(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT SUM(p.units * m.price) AS Value FROM portfolio p, market m WHERE p.ticker = m.ticker";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

/**
 * print_avg_val
 * Average value of all assets in portfolio
*/ 
void Portfolio::print_avg_val(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT AVG(m.price) AS AvgPrice FROM market m, portfolio p WHERE p.ticker = m.ticker";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

/**
 * print_avg_change
 * Average value of all assets in portfolio
*/ 
void Portfolio::print_avg_change(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT AVG(m.change) AS AvgChange FROM market m, portfolio p WHERE p.ticker = m.ticker";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

/** 
 * print_avg_units
 * Avg units held
*/ 
void Portfolio::print_avg_unit(sqlite3 *db, char *zErrMsg, const char *sql, int rc) {
    sql = "SELECT AVG(units) AS AvgUnits FROM portfolio";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
}

/**
 * risk_path
 * Sets a path to a sql query based on the risk profile the user provided
*/ 
void Portfolio::risk_path() {
    if(risk_tolerance_ >= 0 && risk_tolerance_ <= 3) {
        if((risk_capacity_/worth_) >= 0 && (risk_capacity_/worth_) <= .33) {
            path_ = 1;
        }
        else if((risk_capacity_/worth_) >= .33 && (risk_capacity_/worth_) <= .66) {
            path_ = 4; 
        }
        else {
            path_ = 7; 
        }
    }
    else if(risk_tolerance_ > 3 && risk_tolerance_ <= 6) {
        if((risk_capacity_/worth_) > 0 && (risk_capacity_/worth_) <= .33) {
            path_ = 2; 
        }
        else if((risk_capacity_/worth_) >= .33 && (risk_capacity_/worth_) <= .66) {
            path_ = 5; 
        }
        else {
            path_ = 8; 
        }
    }
    else if(risk_tolerance_ > 6 && risk_tolerance_ <= 10) {
        if((risk_capacity_/worth_) > 0 && (risk_capacity_/worth_) <= .33) {
            path_ = 3; 
        }
        else if((risk_capacity_/worth_) >= .33 && (risk_capacity_/worth_) <= .66) {
            path_ = 6; 
        }
        else {
            path_ = 9; 
        }
    } 
}
