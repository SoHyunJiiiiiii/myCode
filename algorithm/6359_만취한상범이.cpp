//
//  main.cpp
//  만취한상범이
//
//  Created by 지소현 on 2017. 8. 20..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <cstring>  //memset
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int T,room;
    int DP[101];    // i번째 방이 몇번 열고닫는지 카운트
    scanf("%d",&T);
    
    while(T--) {
        scanf("%d",&room);
        
        memset(DP, 0, sizeof(DP));
        //i*j 반복문(1의배수,2의배수,3의배수...)
        for(int i=1; i<=room; i++) {
            for(int j=1; j*i<=room; j++) {
                DP[i*j] = 1-DP[i*j];
            }
        }
        
        int count = 0;
        for(int i=1; i<=room; i++) {
            if(DP[i]==1) {
                count++;
            }
        }
        printf("%d\n",count);
    }
    

    return 0;
}
