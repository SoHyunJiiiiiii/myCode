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
using namespace std;
vector<int> price;
int FindMax(int n) {
    if(n==0) {
        return 0;
    }
    int q = -9999;
    for(int i=1; i<=n; i++) {
        q = max(q,price[i]+FindMax(n-i));

    }
    return q;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;

    scanf("%d",&N);
    
    price.resize(N);
    for(int i=1; i<=N; i++) {
        scanf("%d",&price[i]);
    }
    
    printf("%d\n", FindMax(N));
    return 0;
}
