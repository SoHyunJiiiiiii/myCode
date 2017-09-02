//
//  main.cpp
//  1026_보물
//
//  Created by 지소현 on 2017. 9. 2..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,result=0;
    int a[51]={0,},b[51]={0,};
    
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<N; i++) {
        scanf("%d",&b[i]);
    }
    
    
    sort(a,a+N);
    sort(b,b+N);
    
    
    for(int i=0; i<N; i++) {
        result += a[i]*b[N-i-1];
    }
    
    printf("%d\n",result);
    
    return 0;
}
