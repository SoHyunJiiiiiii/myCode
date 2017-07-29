//
//  main.cpp
//  붕어빵판매하기
//
//  Created by 지소현 on 2017. 7. 29..
//  Copyright © 2017년 지소현. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    scanf("%d",&N);
    
    vector<int> price;
    vector<int> maxPrice;

    price.resize(N+1);
    maxPrice.resize(N+1);
    for(int i=1; i<=N; i++) {
        scanf("%d",&price[i]);
    }
    
    if(N==0) {
        return 0;
    }
    
    
    maxPrice[0]=0;
    maxPrice[1]=1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            maxPrice[i] = max(maxPrice[i],maxPrice[i-j] + price[j]);
        }
    }
    
    printf("%d\n", maxPrice[N]);
    return 0;
}
