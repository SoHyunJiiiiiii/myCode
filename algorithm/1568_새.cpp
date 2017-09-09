//
//  main.cpp
//  1568_새
//
//  Created by 지소현 on 2017. 9. 9..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <cstdio>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int bird;
    scanf("%d",&bird);
    
    int k=1;
    int time=0;
    while(bird!=0) {
        
        if(k>bird){
            k=1;
            continue;
        }
        
        bird -= k;
        k++;
        time++;
    }
    printf("%d",time);
    return 0;
}
