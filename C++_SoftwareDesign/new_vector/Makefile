new_vector: new_vector.o new_vector_main.o
	g++ -std=c++11 -o new_vector new_vector_main.o new_vector.o
new_vector_main.o: new_vector.hpp new_vector_main.cpp
	g++ -c new_vector_main.cpp
new_vector.o: new_vector.hpp new_vector.cpp
	g++ -c new_vector.cpp
