//
//  main.cpp
//  시험감독
//
//  Created by 지소현 on 2017. 8. 12..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // insert code here...
    int N;
    long long B,C,sum=0;
    long long A[100001];
    
    scanf("%d",&N);
    //A.resize(N);

    for(int i=0; i<N; i++) {
        scanf("%lld",&A[i]);
    }
    
    scanf("%lld %lld",&B,&C);
    
    for(int i=0; i<N; i++) {
        if(A[i]>0) {
            A[i] -= B; sum+=1;
        }
        if(A[i]>0) {
            if(A[i]%C==0) {
                sum += (A[i]/C);
            } else {
                sum += (A[i]/C)+1;
            }
        }
    }
    printf("%lld\n",sum);
    return 0;
}
