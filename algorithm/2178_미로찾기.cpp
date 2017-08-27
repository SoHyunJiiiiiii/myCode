//
//  main.cpp
//  2178_미로찾기
//
//  Created by 지소현 on 2017. 8. 26..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int maze[101][101];
    int visited[101][101];
    int N,M;
    const int dx[] = {-1,+1,0,0};
    const int dy[] = {0,0,-1,+1};
    
    char c;
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >>c;
            if(c=='1')  maze[i][j] = 1;
            else    maze[i][j] = 0;
            visited[i][j] = 0;
        }

    }
    
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));
 
    int cnt=9999;
    while(!q.empty()) {
        
        int i= q.front().first;
        int j= q.front().second;
        q.pop();
        
        if(visited[i][j]==1)
            return 0;
        
        visited[i][j]=1;

        if(i==N && j==M) {
            if(cnt > maze[i][j]+1)
                cnt = maze[i][j]+1;
        }
        for(int k=0; k<4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x<=0 || y<=0 || x>N || y>M)
                continue;
            if(visited[x][y]==0 && maze[x][y]==1) {
                maze[x][y] = maze[i][j]+1;
                q.push(make_pair(x, y));
            }
        }
    }
    printf("%d",cnt-1);
    return 0;
}
