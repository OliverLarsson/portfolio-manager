XX = g++  # the compiler
CXXFLAGS = -std=c++11 -Wall  # flags for the compiler (use c++11 standards, turn on all optional warnings)
GDBINFO = -ggdb # include this to generate info needed to run gdb

all: portfolio

clean:
	rm Investor.o Assets.o Portfolio.o Forecast.o portfolio

portfolio: Investor.o Assets.o Portfolio.o Forecast.o
	$(CXX) $(CXXFLAGS) main.cpp Investor.o Assets.o Portfolio.o Forecast.o -o portfolio

Investor.o: Investor.cpp
	$(CXX) $(CXXFLAGS) -c Investor.cpp

Assets.o: Assets.cpp
	$(CXX) $(CXXFLAGS) -c Assets.cpp

Portfolio.o: Portfolio.cpp
	$(CXX) $(CXXFLAGS) -c Portfolio.cpp

Forecast.o: Forecast.cpp
	$(CXX) $(CXXFLAGS) -c Forecast.cpp