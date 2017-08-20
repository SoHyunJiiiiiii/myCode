//
//  main.cpp
//  돌다리
//
//  Created by 지소현 on 2017. 8. 12..
//  Copyright © 2017년 지소현. All rights reserved.

#include <cstdio>
#include <queue>
using namespace std;


bool visited[100002];
int main() {
    // insert code here...
    int A, B, N, M, cnt=0;
    queue<int> que;
    
    scanf("%d %d %d %d",&A,&B,&N,&M);
    que.push(N);
    visited[N]=1;
    while(!que.empty()) {
        int size = (int)que.size();

        while(size--) {
            //큐는 선입선출
            int pos = que.front();
            que.pop();
            int next[10]= {+1, -1, +A, -A, +B, -B, pos*A, -pos*A, pos*B, -pos*B};
            
            if(pos==M) {
                printf("%d\n",cnt);
                return 0;
            }
            
            for(int i=0; i<10; i++) {
                int nextPos;
                if(i<6)     nextPos = pos + next[i];
                else    nextPos = next[i];
                
                if(nextPos<0 || nextPos>100000) continue;
                if(visited[nextPos]) continue;
                visited[nextPos] = 1;
                que.push(nextPos);
            }
        }
        cnt++;
    }

    return 0;
}
