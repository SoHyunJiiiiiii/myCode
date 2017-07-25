//
//  main.cpp
//  모든수열
//
//  Created by 지소현 on 2017. 7. 25..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin >> N;
    
    vector<int> num(N);
    for(int i=1; i<=N; i++) {
        num[i-1] = i;
    }
    
    do {
        for(int i=0; i<N; i++) {
            cout << num[i] << " ";
        }cout << '\n';
    } while(next_permutation(num.begin(),num.end()));
    return 0;
}
