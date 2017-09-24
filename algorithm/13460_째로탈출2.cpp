//
//  main.cpp
//  13460_째로탈출2
//
//  Created by 지소현 on 2017. 9. 24..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define FAILED 9999
using namespace std;
int n,m;
char map[11][11];
bool visited[11][11];
int res = FAILED;
//아래,위,오른쪽,왼쪽 순서
const int dy[4] = {1,0,-1,0};
const int dx[4] = {0,1,0,-1};
void dfs(int ry, int rx, int by,int bx, int cnt);
void InitVisit(){
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j]=false;
        }
    }
    
}

//갈수있는 방향(i) 구한뒤 -> 최대한 벽까지 이동
void goDirect(int ry, int rx, int by,int bx,int dir,int cnt) {
    bool rsuccess=false, bsuccess=false;
    
    int nextRY = ry, nextRX = rx , nextBY = by , nextBX =bx , go = 1;
    //빨간공 움직임
    for(int j=1; ; j++){
        int cy = ry + dy[dir]*j;
        int cx = rx + dx[dir]*j;
        
        if(visited[cy][cx]) break;
        visited[cy][cx]=true;
        
        //벽을 만나거나 범위 벗어나면 stop
        if(cy<0 || cy>=n || cx<0 || cx>=m || map[cy][cx]=='#' || map[cy][cx]=='B')  break;
        //출구찾음
        if(map[cy][cx]=='O') {
            rsuccess=true;
            break;
        }
        nextRY = cy; nextRX = cx;
    }
    
    //파란공 움직임
    for(int j=1; ; j++){
        int ay = by + dy[dir]*j;
        int ax = bx + dx[dir]*j;
        
        //벽을 만나거나 범위 벗어나면 stop
        if(ay<0 || ay>=n || ax<0 || ax>=m || map[ay][ax]=='#' || map[ay][ax]=='R')  break;
        //출구찾음
        if(map[ay][ax]=='O') {
            bsuccess=true;
            break;
        }
        nextBY = ay; nextBX = ax , go = j;
    }
    //printf("\n**next(%d %d) , (%d %d) %d\n",nextRY,nextRX,nextBY,nextBX,cnt);
    
    //파란공 성공시 무조건 실패
    if(bsuccess) {    res = min(res,FAILED); return;    }
    //파란공 실패시 .. 1) 빨강공 성공하면 count 출력하고 끝 2) 빨강공도 실패시 다시 dfs
    else {
        if(rsuccess) {
            for(int z=go+1; ;z++) {
                int nby = nextBY + dy[dir]*z;
                int nbx = nextBX + dx[dir]*z;
                //printf("%d %d +z %d\n",nby,nbx,z);
                if(map[nby][nbx]=='#')    break;
                if(nby<0 || nby>=n || nbx<0 || nbx>=m)  break;
                if(map[nby][nbx]=='O')    bsuccess=true;
            }
            if(!bsuccess) {
                res = min(res,cnt);
            } else {
                res = min(res,FAILED);
            }
            return;
        }
        else    dfs(nextRY,nextRX,nextBY,nextBX,cnt+1);
    }
}
void dfs(int ry, int rx, int by,int bx, int cnt) {
    
   // printf("\n**DFS (%d %d)  (%d %d) %d\n",ry,rx,by,bx,cnt);
    if(cnt>10){
        res = min(res,FAILED);
        return;
    }

    for(int i=0; i<4; i++) {
        int y = ry + dy[i];
        int x = rx + dx[i];
       // printf("i %d (%d %d)=>(%d %d)가능? map %c \n",i,ry,rx,y,x,map[y][x]);
        if(y<0 || y>=n || x<0 || x>=m)  continue;
        if(map[y][x]=='B' || map[y][x]=='#' || visited[y][x])   continue;
        goDirect(ry, rx,by,bx,i,cnt); InitVisit();
    }
}



int main(int argc, const char * argv[]) {
    
    int ry=0,rx=0,by=0,bx=0;
    
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) {
        getchar();
        for(int j=0; j<m; j++) {
            map[i][j] = getchar();
            if(map[i][j]=='R'){  ry = i, rx = j; }
            if(map[i][j]=='B'){  by = i, bx = j; }
        }
    }
    dfs(ry,rx,by,bx,1);
    if(res==FAILED) printf("-1\n");
    else    printf("%d\n",res);
    return 0;
}
