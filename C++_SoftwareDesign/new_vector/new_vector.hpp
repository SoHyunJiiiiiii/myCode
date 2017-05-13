//
//  new_vector.hpp
//  8_2
//
//  Created by 지소현 on 2016. 11. 20..
//  Copyright © 2016년 지소현. All rights reserved.
//

#ifndef new_vector_hpp
#define new_vector_hpp
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <string>

struct _DataHolder{
    virtual _DataHolder * clone() =0;
    virtual const std::type_info & type() const =0;
};


template <typename T>
struct DataHolder
: public _DataHolder{
public:
    DataHolder(const T & data):data(data){}
    _DataHolder * clone(){  return new DataHolder(data); }
    const std::type_info & type() const {  return typeid(T); }
    
    T data;
};

class Node{
public:
    void swap(Node & node){ std::swap(holder, node.holder); }
    
    const std::type_info & type() const{
        return (holder != 0) ? holder->type() : typeid(void);
    }
    
    
public:
    template <typename T>
    Node & operator=(const T & other){
        Node(other).swap(*this);
        return *this;
    }
    
    Node & operator=(Node & other){
        other.swap(*this);
        return *this;
    }
    
    
public:
    Node():holder(0){}
    
    template <typename T>
    Node(const T & data) : holder(new DataHolder<T>(data)){}
    
    Node(const Node & other) : holder((other.holder != 0) ? other.holder->clone() : 0){}
    
    ~Node(){
        if(holder != 0)
            delete holder;
        return ;
    }
    
public:
    _DataHolder * holder;
};


template <typename VALUE_T>
VALUE_T * cast(Node * node){
    return (node->type() == typeid(VALUE_T))
    ? &static_cast<DataHolder<VALUE_T> *>(node->holder)->data : 0;
}

#endif /* new_vector_hpp */
