//
//  reply_admin.cpp
//  reply_admin2
//
//  Created by 지소현 on 2016. 10. 27..
//  Copyright © 2016년 지소현. All rights reserved.
//
#include <iostream>
#include <string>
#include <stdlib.h>
#include "reply_admin.hpp"
ReplyAdmin::ReplyAdmin()
{
    chats = new string[NUM_OF_CHAT];
}

ReplyAdmin::~ReplyAdmin()
{
    delete[] chats;
}

int ReplyAdmin::getChatCount()
{
    int i;
    for (i = 0; i < NUM_OF_CHAT; i++)
    {
        string s = chats[i];
        if (s.empty() == true)
        {
            break;
        }
    }
    return i;
}

bool ReplyAdmin::addChat(string _chat)
{
    int chatCount = getChatCount();
    
    if (chatCount > NUM_OF_CHAT)
    {
        return false;
    }
    chats[chatCount] = _chat;
    return true;
}

bool ReplyAdmin::removeChat(int _index)
{
    int chatCount = getChatCount();
    
    if (chatCount <= _index)
    {
        return false;
    }
    for (int i = _index; i < chatCount - 1; i++)
    {
        chats[i] = chats[i + 1];
    }
    chats[chatCount - 1] = "";
    return true;
}

bool ReplyAdmin::removeChat(int *_indices, int _count)
{
    int delete_count = 0;
    for (int i = 0; i < _count; i++)
    {
        removeChat(_indices[i] - delete_count);
        delete_count++;
    }
    return true;
}


bool ReplyAdmin::removeChat(int _start, int _end)
{
    int chatCount = getChatCount();
    if (chatCount < _start)
    {
        return false;
    }
    
    int delete_count = 0;
    for (int i = _start; i <= _end; i++)
    {
        removeChat(i - delete_count);
        delete_count++;
    }
    
    return true;
}

void ReplyAdmin::printChat()
{
    int count = getChatCount();
    for(int i=0; i<count; ++i)
    {
        cout << i << " " << chats[i] << endl;
    }
}

