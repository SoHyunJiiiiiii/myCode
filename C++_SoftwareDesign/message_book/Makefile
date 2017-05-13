message_book: message_book.o message_book_main.o
	g++ -std=c++11 -o message_book message_book_main.o message_book.o
message_book_main.o: message_book.hpp message_book_main.cpp
	g++ -c message_book_main.cpp
message_book.o: message_book.hpp message_book.cpp
	g++ -c message_book.cpp
