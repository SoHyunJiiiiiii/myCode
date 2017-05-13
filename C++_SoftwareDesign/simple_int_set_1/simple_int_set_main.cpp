-//
//  simple_int_set_main.cpp
//  simple_int_set
//
//  Created by 지소현 on 2016. 10. 13..
//  Copyright © 2016년 지소현. All rights reserved.
//
#include "simple_int_set.hpp"

#include <iostream>
#include <sstream>
#include <string>
#define MAX 1024
using namespace std;

int main(int argc, const char * argv[]) {
    
    string input;
    
    /* Take an standard input of characters ended with line break (cin)
     and store them to target characters (input) */
    
    
    getline(cin, input);
    int *elements = new int[input.length()]; // Always more than number of elements.
    int elements_cnt=0;
    int exit=0;
    int menu=0;
    int stop=0;
    
    /* Parse input string into elements in a set and
     convert those token to integer numbers. */
    while (true) {
        
        /* Find first index of ' ' character from the input string. */
        size_t pos = input.find(' ');
        
        /* Get substring from input, with pos length from index 0
         and store this to token string. */
        string token = input.substr(0, pos);
        
        
        
        if (token == "{") {
            // Skip at "{" case.
        } else if (token == "}"){
            exit ++;
            // Terminate loop at "}" case.
            if(exit==2)
                break;
        } else if (token == "+"){
            elements[elements_cnt++] = 0;
            menu=1;
        } else if(token == "-"){
            elements[elements_cnt++] = 0;
            menu=2;
        } else if(token == "*"){
            elements[elements_cnt++] = 0;
            menu=3;
        } else {
            elements[elements_cnt++] = stoi(token);
        }
        
        
        /* Erase input string from index 0 to pos (length : pos)
         and input string */
        input.erase(0, pos + 1);
    }
    
    //두개의 배열로 분리시킴
    int *arr1 = new int[30];
    int *arr2 = new int[30];
    
    int i=0;
    int j=0;
    while(elements[i]!=0)
    {
        arr1[i] = elements[i];
        i++;
    }
    int arr1_cnt = i; i++;
    
    while(i<elements_cnt)
    {
        arr2[j] = elements[i];
        i++; j++;
    }
    int arr2_cnt = j;
    
    
    
    //집합 계산
    simple_int_set *intSet = NULL;
    intSet = new simple_int_set(arr1_cnt,arr2_cnt);
    intSet->InsertKey(arr1, arr2);
    
    
    if(menu==1){
        intSet->GetUnion(arr1,arr2);
    }
    else if(menu==2){
        intSet->GetDifference(arr1, arr2);
    }
    else if(menu==3){
        intSet->GetIntersaction(arr1,arr2);
    }
    
    
    
}
