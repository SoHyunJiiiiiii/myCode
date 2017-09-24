//
//  main.cpp
//  13460_째로탈출2
//
//  Created by 지소현 on 2017. 9. 24..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>

using namespace std;
int n,m;
char map[11][11];
bool visited[11][11];
int fy,fx;
//아래,위,오른쪽,왼쪽 순서
const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};

void dfs(int ry, int rx, int by,int bx, int cnt) {
    
    
    if(cnt>10){
        printf("-1\n");
        return;
    }
    
    if(map[ry][rx]=='O'){
        printf("%d\n",cnt);
        return;
    }
    if(map[by][bx]=='O'){
        printf("-1\n");
        return;
    }
    
    for(int i=0; i<4; i++) {
        int y = ry + dy[i];
        int x = rx + dx[i];
        printf("i %d (%d %d) map %c \n",i,y,x,map[y][x]);
        if(y<0 || y>=n || x<0 || x>=m)  continue;
        if(map[y][x]!='.' || visited[y][x])   continue;
        
        
        int nry=-1,nrx=-1,nby=by,nbx=bx;
        bool rsuccess = false, bsuccess = false;
        //갈수있는 방향(i) 구한뒤 -> 최대한 벽까지 이동
        for(int j=1,q=1; ; j++){
            int bflag=false;
            int cy = ry + dy[i]*j;
            int cx = rx + dx[i]*j;
            
            int ay = by + dy[i]*q;
            int ax = bx + dx[i]*q;
            
            if(map[ay][ax]=='#'){    bflag=true; q=1; }//벽이면 파란공을 움직이지 않음을 의미
            
            if(visited[cy][cx]) break;
            visited[cy][cx]=true;
            
            if(cy<0 || cy>=n || cx<0 || cx>=m)  break;
            if(ay<0 || ay>=n || ax<0 || ax>=m){  bflag=true; q=1;   }
            
            
            if(map[cy][cx]=='O') {
                printf("*** success 방향 %d로 전진.. red : %d,%d & blue%d,%d + %d => %d\n",i,cy,cx,ay,ax,q,cnt);
                for(int z=q+1; ;z++) {
                    ay = by + dy[i]*z;
                    ax = bx + dx[i]*z;
                    printf("%d %d +z %d\n",ay,ax,z);
                    if(map[ay][ax]=='#')    break;
                    if(ay<0 || ay>=n || ax<0 || ax>=m)  break;
                    if(map[ay][ax]=='O')    bsuccess=true;
                }
                if(!bsuccess) {
                    printf("%d\n",cnt);
                } else {
                    printf("-1\n");
                }
                return;
            }
            
            if(map[ay][ax]=='O') {
                printf("-1\n");
                return;
            }
            if(map[cy][cx]!='.') {
                break;
            }
            nry = cy; nrx = cx;
            if(!bflag) {    //저장하지않음!
                nby = ay; nbx = ax; q++;
            }
            printf("방향 %d로 전진.. red : %d,%d & blue%d,%d  + %d=> %d\n",i,nry,nrx,nby,nbx,cnt,q);
        }
        
        dfs(nry, nrx, nby, nbx, cnt+1);
        
    }
}



int main(int argc, const char * argv[]) {
    
    int ry=0,rx=0,by=0,bx=0;
    
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) {
        getchar();
        for(int j=0; j<m; j++) {
            map[i][j] = getchar();
            if(map[i][j]=='R')  ry = i, rx = j;
            if(map[i][j]=='B')  by = i, bx = j;
            if(map[i][j]=='O')  fy = i, fx = j;
        }
    }
    dfs(ry,rx,by,bx,1);
    
    return 0;
}

