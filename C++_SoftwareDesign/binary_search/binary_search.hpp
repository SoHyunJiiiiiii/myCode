//
//  binary_search.hpp
//  binary_search
//
//  Created by 지소현 on 2016. 10. 10..
//  Copyright © 2016년 지소현. All rights reserved.
//

#ifndef binary_search_hpp
#define binary_search_hpp


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

#endif /* binary_search_hpp */
