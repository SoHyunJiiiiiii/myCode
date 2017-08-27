//
//  main.cpp
//  연속합
//
//  Created by 지소현 on 2017. 8. 25..
//  Copyright © 2017년 지소현. All rights reserved.
//
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,arr[100001];
    int dp[100001]; // d[n] : arr[1]~arr[n]까지의 최대연속합
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&arr[i]);
    }
    
    
    for(int i=0; i<N; i++) {
        dp[i] = arr[i];
        if(arr[i] <dp[i-1]+arr[i])
            dp[i] = dp[i-1]+arr[i];
    }
    
    int result = dp[0];
    for(int i=1; i<N; i++) {
        //printf("%d %d\n",i,dp[i]);
        result= max(dp[i-1] , dp[i]);
    }
    
    printf("%d",result);
    return 0;
}



int ans = dp[0];
for (int i=1; i<N; i++) {
    if (ans < dp[i]) {
        ans = dp[i];
    }
}
cout << ans << '\n';
return 0;
}
