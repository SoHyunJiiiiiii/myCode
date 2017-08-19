//
//  main.cpp
//  동전
//
//  Created by 지소현 on 2017. 8. 19..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int T,N,M;
    int coin[21];

    
    scanf("%d",&T);
    
    for(int i=0; i<T; i++) {
        int DP[10001]={0,};
        scanf("%d", &N);
        for(int j=0; j<N; j++) {
            scanf("%d",&coin[j]);
        }
        scanf("%d",&M);
        
        DP[0] = 1;
        for(int i=0; i<N; i++) {
            for(int j=coin[i]; j<=M; j++) {
                DP[j] = DP[j] + DP[j-coin[i]];
            }
        }
        printf("%d\n",DP[M]);
        
    }
    return 0;
}
