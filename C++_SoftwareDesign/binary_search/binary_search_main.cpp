//
//  main.cpp
//  test3_1
//
//  Created by 지소현 on 2016. 10. 8..
//  Copyright © 2016년 지소현. All rights reserved.

#include <iostream>
#include <sstream>
#include <string>
#include "binary_search.hpp"
using namespace std;
int main(void) {
    
    string input;
    BinarySearch *binary_search = NULL;
    
    /* Take an standard input of characters ended with line break (cin)
     and store them to target characters (input) */
    getline(cin, input);
    int *elements = new int[input.length()]; // Always more than number of elements.
    int elements_cnt = 0;
    
    /* Parse input string into elements in a set and
     convert those token to integer numbers. */
    while (true) {
        
        /* Find first index of ' ' character from the input string. */
        size_t pos = input.find(' ');
        
        /* Get substring from input, with pos length from index 0
         and store this to token string. */
        string token = input.substr(0, pos);
        
        if (token == "{") {
            /* Skip at "{" case. */
        } else if (token == "}") {
            /* Terminate loop at "}" case.*/
            break;
        } else {
            elements[elements_cnt++] = stoi(token);
        }
        
        /* Erase input string from index 0 to pos (length : pos)
         and input string */
        input.erase(0, pos + 1);
    }
    
    /* Generate BinarySearch class instance. */
    binary_search = new BinarySearch(elements_cnt,elements);

    
    /* Find input number */
    while (true) {
        int num;
        cin >> num;
        
        if (num == -999) {
            break; // Termination.
        }
        
        /* Print out index of number we want to find
         using GetIndex member function. */
        cout << (binary_search->GetIndex(num)) << endl;
    }
    
    delete binary_search;
    
    return 0;
}
