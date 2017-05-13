bank_account: bank_account.o bank_account_main.o
	g++ -std=c++11 -o bank_account bank_account_main.o bank_account.o
bank_account_main.o: bank_account.hpp bank_account_main.cpp
	g++ -c bank_account_main.cpp
bank_account.o: bank_account.hpp bank_account.cpp
	g++ -c bank_account.cpp
