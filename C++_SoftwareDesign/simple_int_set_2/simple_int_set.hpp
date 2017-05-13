//
//  simple_int_set.hpp
//  set_int_set2
//
//  Created by 지소현 on 2016. 11. 3..
//  Copyright © 2016년 지소현. All rights reserved.
//

#ifndef simple_int_set_hpp
#define simple_int_set_hpp

#include <string>
#include <set>
using namespace std;
class SimpleIntSet {
public:
    SimpleIntSet();
    ~SimpleIntSet();
    void Initialize(std::string text);
    void Print();
    void Sort(); // you can reuse your previous sort assignment
    set<int> Elements() const;
    
    /* Implement operator overloading here */
    SimpleIntSet operator+(const SimpleIntSet& set);
    SimpleIntSet operator-(const SimpleIntSet& set);
    SimpleIntSet operator*(const SimpleIntSet& set);
    SimpleIntSet operator=(const SimpleIntSet& set);

    
private:
    std::set<int> elements_;
    
};

#endif
