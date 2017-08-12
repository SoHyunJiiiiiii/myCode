//
//  main.cpp
//  분수찾기
//
//  Created by 지소현 on 2017. 8. 12..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <stdio.h>
int main() {
    // insert code here...
    int N,finish=0,current;
    scanf("%d",&N);
    
    if(N==1) {
        printf("1/1\n");
        return 0;
    }
    
    int sum = 0;
    for(int i=1; ; i++) {
        if(sum+i >= N) {
            finish=i;
            break;
        }
        sum += i;
    }
    
    current = sum+1;
    if(finish%2==0) {   //짝수일 때
        printf("%d/%d\n",1+ (N-(sum+1)), finish- (N-(sum+1)));
    } else {    // 홀수일 때 if(finish%2==1)
        printf("%d/%d\n",finish-(N-(sum+1)), 1+ (N-(sum+1)));
    }
    return 0;
}
