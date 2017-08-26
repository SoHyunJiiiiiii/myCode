//
//  main.cpp
//  1966_프린터 큐
//
//  Created by 지소현 on 2017. 8. 26..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int Print(int N,int M) {
    
    int temp;
    queue<int> q; //중요도.. 숫자가 클수록 중요함
    vector<int> order;
    
    for(int i=0; i<N; i++) {
        scanf("%d",&temp);
        q.push(temp);
        order.push_back(temp);
    }
    int question = order[M];
    sort(order.begin(),order.end());
    int cnt=0;
    
    int i =order.size()-1;
    while(1) {
        if(M<0)
            M = q.size()-1;
        
        int check = q.front();
        q.pop();
        
        if(check!=order[i]) {
            q.push(check);
            M--;
            continue;
        } else {
            cnt++;
            i--;
            if(question==check && M==0){
                printf("%d\n",cnt);
                return 0;
            }
            M--;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N,M,T; // N 문서의 총갯수 , M 몇번째 출력인지 궁금한 문서
    queue<int> q; //중요도.. 숫자가 클수록 중요함
    scanf("%d",&T);
    while(T--){
        
        scanf("%d%d",&N,&M);
        Print(N,M);
    }
    
    
    return 0;
}
