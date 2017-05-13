//
//  simple_int_set.hpp
//  simple_int_set
//
//  Created by 지소현 on 2016. 10. 10..
//  Copyright © 2016년 지소현. All rights reserved.
//

#ifndef simple_int_set_hpp
#define simple_int_set_hpp
#include <iostream>
#include <sstream>
#include <string>
#define MAX 1024
using namespace std;

class simple_int_set{
    
public:
    simple_int_set(int cnt1,int cnt2);
    ~simple_int_set();
    void PrintArray();
    void InsertKey(int *arr1,int *arr2);
    void SortArray(int *array,int size);
    void DeleteSamaKey(int *array);
    void GetUnion(int *arr1,int *arr2);
    void GetDifference(int *arr1,int *arr2);
    void GetIntersaction(int *arr1,int *arr2);
    
private:
    int* arr1;
    int* arr2;
    int arr1_cnt;
    int arr2_cnt;
    
};


#endif /* simple_int_set_hpp */
