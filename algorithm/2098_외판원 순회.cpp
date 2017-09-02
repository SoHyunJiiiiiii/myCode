//
//  main.cpp
//  외판원 순회2
//
//  Created by 지소현 on 2017. 8. 6..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    // insert code here...
    
    int num,MIN=999;
    scanf("%d",&num);
    
    vector<int> d;
    d.resize(num);
    for(int i=0; i<num; i++) {
        d[i] = i+1;
    }
    
    //비용
    int w[num+1][num+1];
    for(int i=1; i<=num; i++) {
        for(int j=1; j<=num; j++) {
            scanf("%d",&w[i][j]);
        }
    }
    
    int sum=0;
//    for(int i=1; i<=num; i++) {
//        int min = 9999;
//        for(int j=1; j<=num; j++) {
//            if(min > w[i][j] && i!=j) {
//                min = w[i][j];
//            }
//        }
//        sum += min;
//    }
    do{
        if(d[0]!=1) break;
        sum=0;
        bool ok = true;
        for(int i=0; i<num-1; i++) {
            if(w[d[i]][d[i+1]]==0){
                ok=false;
                break;
            } else {
                sum += w[d[i]][d[i+1]];
            }
        }
        
        if(ok && w[d[num-1]][d[0]]!=0){
            sum += w[d[num-1]][d[0]];
            MIN = min(MIN, sum);
        }
    }while(next_permutation(d.begin(),d.end()));
    
    printf("%d\n",MIN);
    return 0;
}
