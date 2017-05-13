//
//  message_book.hpp
//  message_book
//
//  Created by 지소현 on 2016. 10. 28..
//  Copyright © 2016년 지소현. All rights reserved.
//

#ifndef message_book_hpp
#define message_book_hpp

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <stdlib.h>
using namespace std;

class MessageBook {
public:
    MessageBook();
    ~MessageBook();
    void AddMessage(int number, const string& message);
    int DeleteMessage(int number);
    const string& GetMessage(int number) const;
    bool FindMessage(int number);
    void ListBook()const;
    void PrintMessage(int number);
private:
    map<int, string> messages_;
};

#endif /* message_book_hpp */
