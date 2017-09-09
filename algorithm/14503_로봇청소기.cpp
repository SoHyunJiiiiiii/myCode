//
//  main.cpp
//  14503_로봇청소기
//
//  Created by 지소현 on 2017. 9. 9..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
using namespace std;
int turn(int dir, int choose) {
    if(choose == 0)//next == 0은 왼쪽회전
    {
        if(dir == 0) return 3;
        else if(dir == 1) return 0;
        else if(dir == 2) return 1;
        else return 2;
    }
    else{   //후진
        if(dir == 0) return 2;
        else if(dir == 1) return 3;
        else if(dir == 2) return 0;
        else return 1;
    }

}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int N,M; //세로 N,가로M -> 편의상 [x][y]를 위해 x<N, y<M.. -> 가로N,세로M
    int map[51][51];
    int rx,ry,d;
    scanf("%d %d", &M, &N);
    scanf("%d %d %d", &rx, &ry, &d);
    
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d", map[i][j]);
        }
    }
    //왼쪽 회전이니까 서->남->동->북
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    
    int x=rx, y=ry, dir = d;
    int xpos,ypos;
    map[x][y] = 2;
    //dir=turn(dir, 0);
    //printf("d2 %d\n",d);
    int cnt=0,clean=0;
    // map상태 ?
    // NOTCLEANED 0;
    // WALL 1;
    // CLEANED 2;
    while (1) {
        //네방향 모두 청소했다면?
        if(cnt==4) {
            dir=turn(dir, 1);   //뒤쪽방향 검사
            xpos = x + dx[dir];
            ypos = y + dy[dir];
            if(xpos<0 || ypos<0 || xpos>=N || ypos>=M || map[xpos][ypos]==1)  break;
            
            dir= turn(dir, 1); //방향 유지(원상태 복구)
            x = xpos, y = ypos;
            map[x][y] = 2;
            cnt=0;
        }
        
        
        dir = turn(dir, 0); //왼쪽으로 회전
        xpos = x + dx[dir];
        ypos = y + dy[dir];
        if(xpos<0 || ypos<0 || xpos>=N || ypos>=M)  continue;
        if(map[xpos][ypos] != 0) continue;
        x=xpos,y=ypos;  //전진하고
        map[x][y]=2;    //현위치 청소
        clean++;    cnt=0;
    }
    printf("%d\n",clean);
    return 0;
}
