//
//  main.cpp
//  reply_admin2
//
//  Created by 지소현 on 2016. 10. 27..
//  Copyright © 2016년 지소현. All rights reserved.
//
#include <iostream>
#include <string>
#include <stdlib.h>
#include "reply_admin.hpp"

using namespace std;

int main(void)
{
    ReplyAdmin *_replyAdmin = new ReplyAdmin();
    _replyAdmin->addChat("Hello, Reply Administrator!");
    _replyAdmin->addChat("I will be a good programmer.");
    _replyAdmin->addChat("This class is awesome.");
    _replyAdmin->addChat("Professor Lim is wise.");
    _replyAdmin->addChat("Two TAs are kind and helpful.");
    _replyAdmin->addChat("I think male TA looks cool.");
    
    
    
    while(1){
        int idx = 0;
        int command_idx = 0;
        int command_len = 0;
        string inputs;
        getline(cin, inputs);
        
        if (inputs == "#quit")
        {
            return false;
        }
        
        else if(inputs.find("#remove") != npos)
        {
            if (inputs.find_first_of("abcdefghijklmnopqrstuvwxyz") == npos)
            {
                return false;
            }
            else if (inputs.length() == 9)
            {
                _replyAdmin->removeChat(atoi(&inputs[8]));
                _replyAdmin->printChat();
            }
            else if (inputs.find('-') != npos)
            {
                _replyAdmin->removeChat(atoi(&inputs[8]), atoi(&inputs[10]));
                _replyAdmin->printChat();
            }
            else if (inputs.find(',') != npos)
            {
                int arr[100] = { 0 };
                while (inputs[command_idx] != '\0')
                {
                    if (command_idx >= 8 && command_idx % 2 == 0)
                    {
                        arr[idx] = atoi(&inputs[command_idx]);
                        idx++;
                    }
                    command_idx++;
                }
                _replyAdmin->removeChat(arr, idx);
                _replyAdmin->printChat();
            }
        }
        
        else if (_replyAdmin->addChat(inputs))
        {
            _replyAdmin->printChat();
        }
    }
    
    delete _replyAdmin;
    return 0;
}

