//
//  main.cpp
//  2xN타일링
//
//  Created by 지소현 on 2017. 7. 27..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int N,tile[1001];
    cin >> N;
    if(N<0 || N>1000) {
        return -1;
    }
    
    tile[1]=1;
    tile[2]=2;
    
    for(int i=3; i<=N; i++) {
        tile[i] = (tile[i-1] + tile[i-2])%10007;
        
    }
    cout << tile[N] << '\n';
    return 0;
}
