omok: omok.o omok_main.o
	g++ -std=c++11 -o omok omok_main.o omok.o
omok_main.o: omok.hpp omok_main.cpp
	g++ -c omok_main.cpp
omok.o: omok.hpp omok.cpp
	g++ -c omok.cpp
