//
//  main.cpp
//  난장이
//  Created by 지소현 on 2017. 7. 5..
//  Copyright © 2017년 지소현. All rights reserved.

#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 9
#define MAX 100

int main(int argc, const char * argv[]) {
    // insert code here...
    int height[9] , sum = 0 ,num;
    for(int i=0; i<SIZE; i++) {
        cin >> num ;
        
        if(num <=100){
            height[i] = num;
            sum += height[i];
        }
    }
    sort(height,height+SIZE);
    
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE && j!=i ; j++) {
            
                int temp = sum - height[i] - height[j];
                if(temp==100) {
                    for(int k=0; k<SIZE; k++) {
                        if(k!=i && k!=j)
                            cout << height[k] <<endl;
                    }
                }
        }
    }
    
    return 0;
}
