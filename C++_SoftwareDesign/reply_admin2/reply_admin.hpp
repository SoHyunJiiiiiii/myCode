//
//  reply_admin.hpp
//  reply_admin2
//
//  Created by 지소현 on 2016. 10. 27..
//  Copyright © 2016년 지소현. All rights reserved.
//

#ifndef reply_admin_hpp
#define reply_admin_hpp

#define NUM_OF_CHAT 200
#define npos -1
#include <iostream>
#include <string>

using namespace std;

class ReplyAdmin
{
private:
    string* chats;
    
    
public:
    ReplyAdmin();
    ~ReplyAdmin();
    
    int getChatCount();
    bool addChat(string _chat);
    bool removeChat(int _index);                // #remove #
    bool removeChat(int *_indices, int _count); // #remove #,#,#,#
    bool removeChat(int _start, int _end);      // #remove #-#
    void printChat();
};

#endif /* reply_admin_hpp */
