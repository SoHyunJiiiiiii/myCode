reply_admin: reply_admin.o reply_admin_main.o
	g++ -std=c++11 -o reply_admin reply_admin_main.o reply_admin.o
reply_admin_main.o: reply_admin.hpp reply_admin_main.cpp
	g++ -c reply_admin_main.cpp
reply_admin.o: reply_admin.hpp reply_admin.cpp
	g++ -c reply_admin.cpp
