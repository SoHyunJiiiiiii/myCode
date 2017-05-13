//
//  message_book.cpp
//  message_book
//
//  Created by 지소현 on 2016. 10. 28..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include "message_book.hpp"
#include <cstring>
MessageBook::MessageBook(){
}
MessageBook::~MessageBook(){
    messages_.clear();
}
void MessageBook::AddMessage(int number, const string& message){
    if(FindMessage(number)==true)
        DeleteMessage(number);
    messages_.insert(make_pair(number, message));
}
int MessageBook::DeleteMessage(int number){
    if(FindMessage(number)){
        map<int,string>::iterator it;
        it = messages_.find(number);
        if(it != messages_.end()){
            messages_.erase(it);
            return 0;
        }
    }
    return 0;
    
}
const string& MessageBook::GetMessage(int number) const{
    map<int,string>::const_iterator it;
    it = messages_.begin();
    for(int i=0; i<number; i++){
        it++;
    }
 
    return it->second;
}
bool MessageBook::FindMessage(int number){
    map<int,string>::iterator it;
    //it = messages_.find(number);
    for(it=messages_.begin(); it!=messages_.end(); it++){
        if((*it).first==number){
            return true;
        }
    }
    return false;
}
void MessageBook::PrintMessage(int number){
    
    if(FindMessage(number)==1){
        map<int,string>::iterator it;
        it = messages_.find(number);
        cout << (*it).second << endl;
//        string str = (*it).second;
//        char * cstr = new char [str.length()+1];
//        strcpy(cstr,str.c_str());
//        for(int i=1; i< str.length()+1; i++)
//            cout<< cstr[i] ;
    }
        cout<<endl;

}

void MessageBook::ListBook()const{

    vector<pair<int,string> > vec(messages_.begin(),messages_.end());
    sort(vec.begin() , vec.end());
    map<int, string>::const_iterator iter;
    for (iter = messages_.begin(); iter != messages_.end(); ++iter)
        cout << (*iter).first << ":" << (*iter).second << endl;

}
