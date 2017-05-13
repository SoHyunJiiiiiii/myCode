//
//  simple_int_set.cpp
//  set_int_set2
//
//  Created by 지소현 on 2016. 11. 3..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include "simple_int_set.hpp"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

SimpleIntSet::SimpleIntSet() {
    /* TODO: Implement here. */
}

SimpleIntSet::~SimpleIntSet() {
    /* TODO: Implement here. */
}

void SimpleIntSet::Initialize(string input) {
    /* TODO: Implement here. */
    int len = input.length();
    int start_idx=0;
    int cnt= 0;
    
    elements_.clear();
    
    for(int i = 0; i < len; i++)
    {
        if(input.at(i) == ' ')
        {
            if(i != 1)
            {
                elements_.insert(stoi(input.substr(start_idx + 1, cnt)));
                cnt = 0;
            }
            start_idx = i;
        }
        else if(i != 0)
        {
            cnt++;
        }
    }
}

void SimpleIntSet::Print() {
    /* TODO: Modify here. */
    set<int>::iterator it;
    cout << "{";
    for (it = elements_.begin(); it != elements_.end(); ++it)
    {
        cout << " " << (*it);
    }
    cout << " }" << endl;

    /*
     for (int i = 0; i < element_count_; i++) {
     cout << " " << elements_[i];
     }
     */
}

void SimpleIntSet::Sort() {
    /* TODO: Implement here. */
    vector<int> vec(elements_.begin(),elements_.end());
    sort(vec.begin() , vec.end());
}

set<int> SimpleIntSet::Elements() const {
    return elements_;
}

SimpleIntSet SimpleIntSet::operator+(const SimpleIntSet& p)
{
    SimpleIntSet tmp;
    set<int>::iterator it;
    
    for (it = p.elements_.begin(); it != p.elements_.end(); ++it)
    {
        tmp.elements_.insert(*it);
    }
    
    for (it = elements_.begin(); it != elements_.end(); ++it)
    {
        tmp.elements_.insert(*it);
    }
    
    return tmp;
}

SimpleIntSet SimpleIntSet::operator-(const SimpleIntSet& p)
{
    SimpleIntSet tmp;
    set<int>::iterator it;
    
    for (it = p.elements_.begin(); it != p.elements_.end(); ++it)
    {
        if (elements_.upper_bound(*it) != elements_.lower_bound(*it))
        {
            elements_.erase(elements_.find(*it));
        }
    }
    
    for (it = elements_.begin(); it != elements_.end(); ++it)
    {
        tmp.elements_.insert(*it);
    }
    
    return tmp;
}

SimpleIntSet SimpleIntSet::operator*(const SimpleIntSet& p)
{
    SimpleIntSet tmp;
    set<int>::iterator it;
    
    for (it = p.elements_.begin(); it != p.elements_.end(); ++it)
    {
        if (elements_.upper_bound(*it) != elements_.lower_bound(*it))
        {
            tmp.elements_.insert(*it);
        }
    }
    return tmp;
}

SimpleIntSet SimpleIntSet::operator=(const SimpleIntSet& p)
{
    set<int>::iterator it;
    
    elements_.clear();
    
    for (it = p.elements_.begin(); it != p.elements_.end(); ++it)
    {
        elements_.insert(*it);
    }
    
    return p;
}
