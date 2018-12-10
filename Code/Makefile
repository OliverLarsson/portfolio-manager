XX = g++ # the compiler
CXXFLAGS = -std=c++11 -Wall -l sqlite3 -w # flags for the compiler (use c++11 standards, turn on all optional warnings) & sqlite3 needed to connect to SQLite. -w to disable the false warnings. 
GDBINFO = -ggdb # include this to generate info needed to run gdb

all: portfolio test 

clean:
	rm Investor.o Market.o Portfolio.o Forecast.o portfolio test

portfolio: Investor.o Market.o Portfolio.o Forecast.o
	$(CXX) $(CXXFLAGS) main.cpp Investor.o Market.o Portfolio.o Forecast.o -o portfolio

test: Investor.o Market.o Portfolio.o Forecast.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp Investor.o Market.o Portfolio.o Forecast.o -o test

cov: Investor.o Market.o Portfolio.o Forecast.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp Investor.o Market.o Portfolio.o Forecast.o -o test

Investor.o: Investor.cpp
	$(CXX) $(CXXFLAGS) -c Investor.cpp

Market.o: Market.cpp
	$(CXX) $(CXXFLAGS) -c Market.cpp

Portfolio.o: Portfolio.cpp
	$(CXX) $(CXXFLAGS) -c Portfolio.cpp

Forecast.o: Forecast.cpp
	$(CXX) $(CXXFLAGS) -c Forecast.cpp