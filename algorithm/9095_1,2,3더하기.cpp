//
//  main.cpp
//  1,2,3더하기
//
//  Created by 지소현 on 2017. 8. 20..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int T,num;
    scanf("%d",&T);
    
    int DP[11]={0,1,2,4,0,};
    for(int j=4; j<11; j++) {
        for(int i=1; i<=3; i++) {
            DP[j] += DP[j-i];
        }
    }

    
    while (T--) {
        scanf("%d",&num);
        printf("%d\n",DP[num]);
    }
    
    return 0;
}
