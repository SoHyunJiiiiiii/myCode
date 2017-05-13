//
//  reply_admin.h
//  reply_admin3
//
//  Created by 지소현 on 2016. 10. 28..
//  Copyright © 2016년 지소현. All rights reserved.
//

#ifndef reply_admin_hpp
#define reply_admin_hpp

#define NUM_OF_CHAT 200

#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
static const int npos = -1;
using namespace std;

class ReplyAdmin
{
private:
    //string* chats;
    list<string> chats;
    
public:
    ReplyAdmin();
    ~ReplyAdmin();
    
    bool addChat(string _chat);
    bool removeChat(int _index);                // #remove #
    bool removeChat(int *_indices, int _count); // #remove #,#,#,#
    bool removeChat(int _start, int _end);      // #remove #-#
    void printChat();
};

#endif /* reply_admin_hpp */
