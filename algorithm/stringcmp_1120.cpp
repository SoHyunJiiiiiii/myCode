//
//  main.cpp
//  문자열
//
//  Created by 지소현 on 2017. 7. 29..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string str1,str2;

//앞부터 비교(뒤에 문자열추가)
int CountDiffBackChar() {
    int DiffCount=0,min=100000;
    int lengthDifferent = int(str2.length()-str1.length());
    
    for(int i=0; i<int(str1.length()); i++) {
        if(str1[i] != str2[i]) {
            DiffCount++;
        }
    }

    return lengthDifferent+DiffCount;
}

//뒤부터 비교(앞에 문자열추가)
int CountDiffFrontChar() {
    int DiffCount=0,min=100000;
    int lengthDifferent = int(str2.length()-str1.length());
    
    
    for(int i=0; i<=lengthDifferent; i++) {
        DiffCount=0;
        
        for(int j=0; j<str1.length(); j++) {
            if( str1[j] != str2[i+j]) {
                DiffCount++;
            }
        }
        
        if(min>DiffCount) {
            min=DiffCount;
        }

    }
    

    return min;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    cin >> str1 >> str2;
    

    int count = 0;
    //a와 b의 길이가 같다면
    if(str1.length()==str2.length()) {
        for(int i=0; i<str1.length(); i++) {
            if(str1[i]!=str2[i]) {
                count++;
            }
            
        }
        cout <<   count << '\n' ;
    } else {    //다르다면
        
        if(CountDiffBackChar()>CountDiffFrontChar()) {
            cout << CountDiffFrontChar() << '\n';
        } else {
            cout << CountDiffFrontChar() << '\n';
        }
    }
    
    return 0;
}
