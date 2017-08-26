//
//  main.cpp
//  기숙사바닥
//
//  Created by 지소현 on 2017. 8. 20..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <utility>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int R,B;
    
    scanf("%d %d",&R,&B);
    int sum = R+B;
    
    for(int i=3;i<=sum;i++) {
        int L=0,W=0;
        if(sum%i == 0){
            
            L = i;
            W = sum/i;
           //printf("=0 %d %d\n",L,W);
            
            if((L-1)*(W-2)==B) {
                if(L<W) {
                    swap(L,W);
                }
                printf("%d %d",L,W);
                return 0;
            }
            
            if((L-2)*(W-2)==B) {
                if(L<W) {
                    swap(L,W);
                }
                printf("%d %d",L,W);
                return 0;
            }
            
        }

    }
    
    return 0;
}
