//
//  main.cpp
//  10026_적록색약
//
//  Created by 지소현 on 2017. 9. 2..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
//struct point{
//    char ch;
//    int x,y;
//};

int N;
char c[102][102];
int visited[102][102];

int cnt1=0,cnt2=0;

//적록색약이 아닌사람
int bfs1(int i,int j) {
    
    if(visited[i][j])   return -1;
    cnt1++;
  
    queue<pair<int,int> > q;
    q.push(make_pair(i, j));
    char ch = c[i][j];
    const int dx[] = {0,0,-1,1};
    const int dy[] = {-1,1,0,0};

    
    while(!q.empty()) {
        
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        visited[x][y]=1;

        
        for(int i=0; i<4; i++) {
            int xpos = x+dx[i];
            int ypos = y+dy[i];
            
            if(ypos<=0 || xpos<=0 || ypos>N || xpos>N)  continue;
            if(visited[xpos][ypos]==1)  continue;
            

            if(ch == c[xpos][ypos]){
                q.push(make_pair(xpos,ypos));
            }
        }
    }
    
    return 0;
}

//적록색약인 사람
int bfs2(int i,int j) {
    
    if(visited[i][j]==0)   return -1;
    
    cnt2++;
    queue<pair<int,int> > q;
    q.push(make_pair(i, j));
    char ch = c[i][j];
    const int dx[] = {0,0,-1,1};
    const int dy[] = {-1,1,0,0};
    
    while(!q.empty()) {
        
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        visited[x][y]=0;

        for(int i=0; i<4; i++) {
            int xpos = x+dx[i];
            int ypos = y+dy[i];

            if(ypos<=0 || xpos<=0 || ypos>N || xpos>N)  continue;
            if(visited[xpos][ypos]==0)  continue;
            
            
            if(ch == c[xpos][ypos]){
                q.push(make_pair(xpos,ypos));
                //visited[xpos][ypos]=0;
            }
            
            else {
                if(ch=='R' && c[xpos][ypos]=='G'){
                    q.push(make_pair(xpos,ypos));
                    //visited[xpos][ypos]=0;
                } else if(ch=='G' && c[xpos][ypos]=='R'){
                    q.push(make_pair(xpos,ypos));
                    //visited[xpos][ypos]=0;
                }
            }
        }
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...

    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> c[j][i];
            visited[i][j]=0;
        }
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            bfs1(i,j);
        }
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            bfs2(i,j);
            
        }
    }
    
    printf("%d %d\n",cnt1,cnt2);
    
    return 0;
}
