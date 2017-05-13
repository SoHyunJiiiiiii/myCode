//
//  main.cpp
//  8_1
//
//  Created by 지소현 on 2016. 11. 20..
//  Copyright © 2016년 지소현. All rights reserved.
//
#include <iostream>
#include <string>
#include <map>
#include "sorted_array.h"

using namespace std;

typedef SortedArray<int> IntSortedArray;
typedef SortedArray<double> DoubleSortedArray;
typedef SortedArray<string> StringSortedArray;

int main()
{
	map<string, IntSortedArray> int_arrays;
	map<string, DoubleSortedArray> double_arrays;
	map<string, StringSortedArray> string_arrays;

	string cmd, str,name;
    //T find;
    int size,state=0;
    //T data;
    IntSortedArray IntSortedArray_;
    DoubleSortedArray DoubleSortedArray_;
    StringSortedArray StringSortedArray_;
    
	while(cmd!="quit")
    {
		cin>>cmd;

		if(cmd=="int")
		{
            cin >> name ;
            cin >> size ;
            IntSortedArray IntSortedArray_(size);
            for(int i=0; i<IntSortedArray_.size(); i++){
                int data;
                cin >> data;
                IntSortedArray_.Add(data);
            }
            IntSortedArray_.Sort();
            int_arrays.insert(pair<string, IntSortedArray> (name,IntSortedArray_));
            cout << name << " : ";
            IntSortedArray_.Print();
        }

		else if(cmd=="double")
		{
            cin >> name ;
            cin >> size ;
            DoubleSortedArray DoubleSortedArray_(size);
            for(int i=0; i<DoubleSortedArray_.size(); i++){
                string temp;
                cin >> temp;
                double data = stod(temp);
                cout << data << endl;
                DoubleSortedArray_.Add(data);
            }
            DoubleSortedArray_.Sort();
            double_arrays.insert(pair<string, DoubleSortedArray> (name,DoubleSortedArray_));
            cout << name << " : ";
            DoubleSortedArray_.Print();
		}

		else if(cmd=="string")
		{
            cin >> name ;
            cin >> size ;
            StringSortedArray StringSortedArray_(size);
            for(int i=0; i<StringSortedArray_.size(); i++){
                string data;
                cin >> data;
                StringSortedArray_.Add(data);
            }
            string_arrays.insert(pair<string, StringSortedArray> (name,StringSortedArray_));
            cout << name << " : ";
            StringSortedArray_.Print();
		}

		else if(cmd=="list")
		{
            
            for(map<string,IntSortedArray>::iterator it=int_arrays.begin(); it!=int_arrays.end(); it++){
                cout << "int " << it->first << " : " ;
                it->second.Print();
            }
            
            for(map<string,DoubleSortedArray>::iterator it=double_arrays.begin(); it!=double_arrays.end(); it++){
                cout << "double " << it->first << " : " ;
                it->second.Print();
            }
            for(map<string,StringSortedArray>::iterator it=string_arrays.begin(); it!=string_arrays.end(); it++){
                cout << "string " << it->first << " : " ;
                it->second.Print();
            }
		}

		else if(cmd=="find")
		{
            state=-1;
            cin >> name; // >> data;
            
            map<string,IntSortedArray>::iterator it1;
            for(it1=int_arrays.begin(); it1!=int_arrays.end(); it1++){
                if(it1->first==name){
                    int data;
                    cin >> data;
                    state =it1->second.Find(data);
                    break;
                }
            }
            
            map<string,DoubleSortedArray>::iterator it2;
            if(it1==int_arrays.end()){
                for(it2=double_arrays.begin(); it2!=double_arrays.end(); it2++){
                    if(it2->first==name){
                        double data;
                        cin >> data;
                        state = it2->second.Find(data);
                        break;
                    }
                }
            }
            
            map<string,StringSortedArray>::iterator it3;
            if(it2==double_arrays.end()){
                for(it3=string_arrays.begin(); it3!=string_arrays.end(); it3++){
                    if(it3->first==name){
                        string data;
                        cin >> data;
                        state = it3->second.Find(data);
                        break;
                    }
                }
            }
            cout << state << endl;
        }
    }

	return 0;
}
