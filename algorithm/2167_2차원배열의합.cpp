//
//  main.cpp
//  2167_2차원배열의합
//
//  Created by 지소현 on 2017. 8. 26..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int N,M,k;
    int arr[301][301];
    //int dp[301][301];
    scanf("%d%d",&N,&M);
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    
    
    
    int x1,x2,y1,y2;
    scanf("%d",&k);
    while(k--) {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int minX = min (x1,x2);
        int maxX = max (x1,x2);
        int minY = min (y1,y2);
        int maxY = max (y1,y2);
        int sum =0;
        //printf("%d %d %d %d\n",minY,minX ,maxY,maxX);
        for(int i=minX; i<=maxX; i++) {
            for(int j=minY; j<=maxY; j++) {
                sum += arr[i][j];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
