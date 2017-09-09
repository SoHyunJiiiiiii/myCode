#include <cstdio>

using namespace std;

int turn(int dir, int choose) {
    if(choose == 0) //next == 0은 왼쪽회전
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

int main()
{

    int N,M; //세로 N,가로M -> 편의상 [x][y]를 위해 x<N, y<M.. -> 가로N,세로M
    int map[51][51];
    int rx,ry,rd;
    //direction열거형 기준 ( 북, 동, 남, 서)
    const int dx[4] = { -1, 0, 1, 0};
    const int dy[4] = { 0, 1, 0, -1};

    scanf("%d %d", &M, &N);
    scanf("%d %d %d", &rx, &ry, &rd);
    
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    int x=rx, y=ry, dir = rd;
    int xpos,ypos;
    map[x][y] = 2;
    int cnt=0,clean=1;
    
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
            if(xpos<0 || ypos<0 || xpos>=M || ypos>=N || map[xpos][ypos]==1)  break;
            
            dir= turn(dir, 1); //방향 유지(원상태 복구)
            x = xpos, y = ypos;
            cnt=0;
        }
        
        
        dir = turn(dir, 0); //왼쪽으로 회전
        xpos = x + dx[dir];
        ypos = y + dy[dir];
        cnt ++;
        
        if(xpos<0 || ypos<0 || xpos>=M || ypos>=N)  continue;
        if(map[xpos][ypos] != 0) continue;
        
        x=xpos,y=ypos;  //전진하고
        map[x][y]=2;    //현위치 청소
        clean++;    cnt=0;
    }
    printf("%d\n",clean);
    return 0;
}
