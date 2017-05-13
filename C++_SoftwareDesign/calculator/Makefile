calc: calc.o calc_main.o
	g++ -std=c++11 -o calc calc_main.o calc.o
calc_main.o: calc.hpp calc_main.cpp
	g++ -c calc_main.cpp
calc.o: calc.hpp calc.cpp
	g++ -c calc.cpp
