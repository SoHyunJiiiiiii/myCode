//
//  main.cpp
//  Binary_Search
//
//  Created by 지소현 on 2016. 10. 7..
//  Copyright © 2016년 지소현. All rights reserved.

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class BinarySearch
{
    
    
public:
    BinarySearch();
    BinarySearch(int array_cnt,int *array);
    ~BinarySearch();
    void PrintArray();
    void SortArray();
    int GetIndex(int key); // return -1 when element doesn't exist
    
    
private:
    int *array_;
    int array_count_;
};

BinarySearch::BinarySearch(){
    array_ = new int [30];
    array_count_ = 30;
}

BinarySearch::BinarySearch(int array_cnt,int *array) {
    array_ = new int[array_cnt] ;
    array_count_ = array_cnt;
    for(int i=0; i<array_count_; i++){
        array_[i] = array[i];
    }
    SortArray();
    
}

BinarySearch::~BinarySearch() {
    delete [] array_;
}

void BinarySearch::SortArray(){
    
    
    int i, j, target;
    for (i = 1; i < array_count_; i++){
        target = array_[i];
        
        for (j = i - 1; j >= 0; j--){
            if (array_[j] > target)
                array_[j + 1] = array_[j];
            else
                break;
        }
        
        array_[j + 1] = target;
    }
    
}

void BinarySearch::PrintArray(){
    for (int i = 0; i < array_count_; i++)
    {
        cout<< array_[i]<< endl;
    }
}

int BinarySearch::GetIndex(int search) {
    
    int first = 0;
    int last = array_count_-1;
    int middle = (first+last)/2;
    
    while (first <= last) {
        if (array_[middle] < search)
            first = middle + 1;
        else if (array_[middle] == search) {
            return middle;
            break;
        }
        else
            last = middle - 1;
        
        middle = (first + last)/2;
    }
    
    if (first > last)
        return -1;
    
    return -1;
}


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
            /* TODO: What if unexpected value comes in ?*/
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
    
    binary_search->~BinarySearch();
    
    return 0;
}
