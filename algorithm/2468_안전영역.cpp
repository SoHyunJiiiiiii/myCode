//
//  main.cpp
//  2468_안전영역
//
//  Created by 지소현 on 2017. 9. 9..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> qii;
int n;
int map[101][101];
int visited[101][101];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

void DFS(int i,int j,int h) {
    
    if(visited[i][j])   return;
    //printf("dfs %d %d %d\n",i,j,h);
    
    queue<qii> q;
    q.push(make_pair(i, j));
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(visited[x][y])   continue;
        visited[x][y]=1;
        //printf("pop %d %d \n",x,y);
        for(int i=0; i<4; i++) {
            int xpos = x+ dx[i];
            int ypos = y+ dy[i];
        
            if(xpos<0 || ypos<0 || xpos>=n || ypos>=n)  continue;
            if(map[xpos][ypos]>h) {
                q.push(make_pair(xpos,ypos));
            }
        }
    }
    
    
}
void visitedInit() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j]=0;
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    int maxHeight=-9999; //,minHeight=9999;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&map[i][j]);
            if(maxHeight<map[i][j]) maxHeight=map[i][j];
            //if(minHeight>map[i][j]) minHeight=map[i][j];
            visited[i][j]=0;
        }
    }
    
    int h=maxHeight;
    int res=-1;
    while(h>=0) {
        
        int cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && map[i][j]>h){
                    DFS(i, j, h);
                    cnt++;
                }
            }
        }
        
        if(res<cnt) res = cnt;
        h--; visitedInit();
    }
    
    printf("%d\n",res);
    return 0;
}
