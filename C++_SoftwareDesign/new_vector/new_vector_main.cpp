//
//  main.cpp
//  8_2
//
//  Created by 지소현 on 2016. 11. 20..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include <iostream>
#include "new_vector.hpp"
using namespace std;
int main(){
    
    vector<Node> myVector;
    char *typeArr = new char[20];
    int count =0;
    while(true)
    {
        string type;
        cin >> type;
        if(type == "i")
        {
            int value;
            cin >> value;
            myVector.push_back(value);  // replace to nv.add<int>(value) when error occurs
            typeArr[count++] = 'i';
        }
        else if(type == "d")
        {
            double value;
            cin >> value;
            myVector.push_back(value); // replace to nv.add<double>(value) when error occurs
            typeArr[count++] = 'd';
        }
        else if(type == "c")
        {
            char value;
            cin >> value;
            myVector.push_back(value); // replace to nv.add<char>(value) when error occurs
            typeArr[count++] = 'c';
        }
        else if(type == "print"){
            for(int i=0; i<count; i++){
                if(typeArr[i]=='i'){
                    cout << *cast<int>(&myVector[i]) << " " ;
                }
                else if(typeArr[i]=='d'){
                    cout << *cast<double>(&myVector[i]) << " " ;
                }
                else{ //if(typeArr[i]=='c'){
                    cout << *cast<char>(&myVector[i]) << " " ;
                }
            }
            cout << endl;
        }
        else if(type == "q") break;
    }
    return 0;
}
    



//using namespace std;
//
//
//int main(void)
//{
//    int current = 0;
//    
//    while(true)
//    {
//        string type;
//        cin >> type;
//        if(type == "i")
//        {
//            NewVector<int,current> nv(10);
//            int value;
//            cin >> value;
//            nv.add(value); // replace to nv.add<int>(value) when error occurs
//        }
//        else if(type == "d")
//        {
//            double value;
//            cin >> value;
//            nv.add(value); // replace to nv.add<double>(value) when error occurs
//        }
//        else if(type == "c")
//        {
//            char value;
//            cin >> value;
//            nv.add(value); // replace to nv.add<char>(value) when error occurs
//        }
//        else if(type == "print") cout << nv;
//        else if(type == "q") break;
//    }
//    return 0;
//}
