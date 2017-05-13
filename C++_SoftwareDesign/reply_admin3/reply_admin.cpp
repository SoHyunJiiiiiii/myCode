//
//  reply_admin.cpp
//  reply_admin3
//
//  Created by 지소현 on 2016. 10. 28..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include "reply_admin.hpp"

ReplyAdmin::ReplyAdmin()
{
    // chats = new string[NUM_OF_CHAT];
}

ReplyAdmin::~ReplyAdmin()
{
    chats.clear();
    //delete[] chats;
}

bool ReplyAdmin::addChat(string _chat)
{
    chats.push_back(_chat);
    return true;
}

bool ReplyAdmin::removeChat(int _index)
{
    list<string>::iterator it;
    it = chats.begin();
    for(int i=0; i<_index;i++){
        it++;
    }
    chats.erase(it);
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
    

    if(_end >chats.size()){
        list<string>::iterator it;
        it = chats.begin();
        for(int i=0; i<_start;i++){
            it++;
        }
        chats.erase(it,chats.end());
    }
    else{
        list<string>::iterator it1,it2;
        it1 = chats.begin();
        it2 = chats.begin();
        for(int i=0; i<_start;i++){
            it1++;
        }
        for(int i=0; i<=_end;i++){
            it2++;
        }
        
        chats.erase(it1,it2);
    }
    return true;
}

void ReplyAdmin::printChat()
{
    int i=0;
    list<string>::iterator it;
    for(it=chats.begin() ; it!=chats.end(); it++)
    {
        cout << i << " " << *it << endl;
        i++;
    }
}
