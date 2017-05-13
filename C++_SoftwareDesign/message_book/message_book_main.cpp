//
//  main.cpp
//  message_book
//
//  Created by 지소현 on 2016. 10. 28..
//  Copyright © 2016년 지소현. All rights reserved.
//
#include "message_book.hpp"


int main(int argc, const char * argv[]) {

    MessageBook *messagesBook = new MessageBook();
    
    while(1){
        string inputs;
        cin >> inputs;
        
        if (inputs == "quit")
        {
            break;
        }
        
        else if(inputs =="add"){
            int number;
            string message;
            cin >> number;
            getline(cin, message);
            messagesBook->AddMessage(number, message);
        }
        else if (inputs == "list")
        {
            messagesBook->ListBook();
        }
        else if(inputs == "print")
        {
            int num;
            cin >> num;
            messagesBook->PrintMessage(num);
        }
        else if(inputs == "delete"){
            int num;
            cin >> num;
            messagesBook->DeleteMessage(num);
            
        }
    }
    
    delete messagesBook;
    return 0;
}

