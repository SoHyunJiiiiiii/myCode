//
//  main.cpp
//  헤일스톤 수열
//
//  Created by 지소현 on 2017. 8. 20..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
using namespace std;
//2의 제곱승인지 체크하는 함수
bool CheckTwoJeGop(int nNum) {
    
    int nResult = nNum & (nNum-1);
    if(nResult==0) {
        return true;
    } else {
        return false;
    }
    
}
//헤일스톤 수열
void HeilStone(int start) {
    
    int max =1;
    
    while (start!= 1) {
        
        if(max<start) {
            max = start;
        }
        
        if(CheckTwoJeGop(start)==true) {
            //printf("%d twojegop\n",start);
            break;
        }
        //printf("start %d\n",start);
        
        if(start%2==1) {
            start = start * 3 + 1;
        } else {
            start = start / 2;
        }
        
        
    }
    printf("%d\n",max);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T,start;
    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        
        scanf("%d",&start);
        HeilStone(start);
    }
    return 0;
}

