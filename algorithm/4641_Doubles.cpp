//
//  main.cpp
//  Doubles
//
//  Created by 지소현 on 2017. 8. 19..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> number;
void PrintResult() {
    
    int compare[number.size()+1];
    int cnt = 0,result =0;
    for(int i=0; i<number.size(); i++) {
        if(number[i]%2 == 0) {
            compare[cnt++] = number[i]/2 ;
        }
    }
    
    for(int i=0; i<number.size(); i++) {
        for(int j=0; j<cnt; j++) {
            if(number[i] == compare[j]) {
                result++;
                break;
            }
        }
    }
    printf("%d\n",result);
    
}
int main(int argc, const char * argv[]) {

    int num;

    while(1) {
        scanf("%d",&num);
        
        if(num == -1) {
            break;
        } else if(num == 0) {
            PrintResult();
            number.clear();
        } else {
            number.push_back(num);
        }
    }
    
        return 0;
}
