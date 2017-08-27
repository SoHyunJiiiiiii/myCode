//
//  main.cpp
//  계단오르기
//
//  Created by 지소현 on 2017. 8. 25..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,stairs[301];
    int dp[301][3]; // d[i][j] : i번째 계단 올라갔을때 최대점수 , i번째 계단은 j개 연속해서 올라온 경우(L=0,1,2)
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        scanf("%d",&stairs[i]);
    }
    
    dp[1][0] = 0 ;
    dp[1][1] = stairs[1] ;

    for(int i=2; i<=N; i++) {
        dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + stairs[i];  //+1칸한경우
        dp[i][2] = dp[i-1][1] + stairs[i];   //+1+1한경우
    }
    
    int result = max(dp[N][1],dp[N][2]);
    printf("%d",result);
    return 0;
}


/*
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,stairs[301];
    int dp[301]; // d[n] : n번째 계단까지 오를때 점수의 최대값
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        scanf("%d",&stairs[i]);
    }
    
    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = max(stairs[1]+stairs[2], stairs[2]);
    for(int i=3; i<=N; i++) {
        dp[i] = max(dp[i-3]+stairs[i-1]+stairs[i], dp[i-2]+stairs[i]); // max(+2+1+1칸이동,+2칸이동)
    }

    printf("%d",dp[N]);
    return 0;
}
*/
