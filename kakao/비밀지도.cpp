//
//  main.cpp
//  비밀지도
//
//  Created by 지소현 on 2017. 9. 16..
//  Copyright © 2017년 지소현. All rights reserved.
//
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
int map[17][17];
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> binary;
    for(int i=0; i<arr1.size(); i++) {
        arr1[i] = arr1[i] | arr2[i];
    }

     for(int i=0; i<arr1.size(); i++) {
        int compare = arr1[i];
         string str;
         for(int j=n-1; j>=0; j--) {
            int num = pow(2,j);
            if(num<=compare) {
                str += "#";
                compare -= num;
            } else {
                str += " ";
            }
         }   answer.push_back(str);
            //cout << str<<endl;
    }
    return answer;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,num;
    vector<int> arr1,arr2;
    cin >> n;
    
    for(int j=0; j<n; j++) {
        cin >> num;
        arr1.push_back(num);
    }
    for(int j=0; j<n; j++) {
        cin >> num;
        arr2.push_back(num);
    }
    

    
    solution(n, arr1, arr2);
    
    return 0;
}

