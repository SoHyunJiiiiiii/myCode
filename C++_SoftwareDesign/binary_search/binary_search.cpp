//
//  binary_search.cpp
//  binary_search
//
//  Created by 지소현 on 2016. 10. 10..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include "binary_search.hpp"
using namespace std;

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

