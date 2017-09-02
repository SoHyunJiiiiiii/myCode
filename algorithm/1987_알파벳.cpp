//
//  main.cpp
//  1987_알파벳
//
//  Created by 지소현 on 2017. 8. 27..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

int R,C;
char matrix[22][22];
int visited[26]; //A~Z 방문여부;
int ans=-999;

void DFS(int y,int x,int cnt) {

    if(ans<cnt)
        ans = cnt;
    
    for(int i=0; i<4; i++) {
        int yPos = y + dy[i];
        int xPos = x + dx[i];
        char ch=matrix[yPos][xPos];

        if(xPos<=0 || yPos<=0 || yPos>R || xPos>C)  continue;
        
        //아스키코드 이용 'A'=65 ~~ 'Z'=90;
        if(visited[ch-'A']==1) continue;

            visited[ch-'A']=1;
            DFS(yPos, xPos,cnt+1);
            visited[ch-'A']=0;

        
    }

}

int main(int argc, const char * argv[]) {

    memset(visited, 0, sizeof(visited));
    
    scanf("%d%d",&R,&C);
    for(int i=1; i<=R; i++) {//세로
        for(int j=1; j<=C; j++) {//가로
            cin >>matrix[i][j];
            
        }
    }


    visited[matrix[1][1]-'A']=1;
    DFS(1,1,1);
    
    printf("%d\n",ans);
    
    return 0;
}

