matrix: matrix.o matrix_main.o
	g++ -std=c++11 -o matrix matrix_main.o matrix.o
matrix_main.o: matrix.hpp matrix_main.cpp
	g++ -c matrix_main.cpp
matrix.o: matrix.hpp matrix.cpp
	g++ -c matrix.cpp
