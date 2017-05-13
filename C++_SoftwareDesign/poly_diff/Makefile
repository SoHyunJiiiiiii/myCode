poly_diff: poly_diff.o poly_diff_main.o
	g++ -std=c++11 -o poly_diff poly_diff_main.o poly_diff.o
poly_diff_main.o: poly_diff.hpp poly_diff_main.cpp
	g++ -c poly_diff_main.cpp
poly_diff.o: poly_diff.hpp poly_diff.cpp
	g++ -c poly_diff.cpp
