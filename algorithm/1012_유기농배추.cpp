//
//  main.cpp
//  1012_유기농배추
//
//  Created by 지소현 on 2017. 8. 27..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
struct point {
    int x;
    int y;
};

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

int main(int argc, const char * argv[]) {
    // insert code here...
    int T,K,x,y;    //M은 가로길이 N은 세로길이 K는 배추개수
    int farm[51][51];
    int visited[51][51];
    int M,N;

    queue<point> q;
    point pt;
    
   
    scanf("%d&",&T);
    
    while(T--){
        scanf("%d%d%d",&M,&N,&K);
         //초기화
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                farm[i][j]=0;
                visited[i][j]=0;
            }
        }
    
        for(int i=0; i<K; i++) {
            scanf("%d%d",&x,&y);
            farm[x][y]=1;
            pt.x = x; pt.y = y;
            q.push(pt);
        }
    
        int cnt=0;
        while(!q.empty()) {
            //printf("que\n");
            point temp = q.front();
            q.pop();
            if(visited[temp.x][temp.y]==1) continue;
        
            visited[temp.x][temp.y]=1;
            queue<point> bfs;
            bfs.push(temp);
        
            while(!bfs.empty()) {
                point bfs_temp = bfs.front();
                bfs.pop();
                for(int i=0; i<4; i++) {
                    int xPos = bfs_temp.x + dx[i];
                    int yPos = bfs_temp.y + dy[i];
                
                    if(xPos<0 || yPos<0 || xPos>M || yPos>N)    continue;
                    if(visited[xPos][yPos]==1 || farm[xPos][yPos]==0) continue;
                
                    visited[xPos][yPos] = 1;
                    temp.x = xPos; temp.y = yPos;
                //printf("%d %d 이동\n",xPos,yPos);
                bfs.push(temp);
                }
            } cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
