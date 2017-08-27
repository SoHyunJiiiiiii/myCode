//
//  main.cpp
//  7576_토마토
//
//  Created by 지소현 on 2017. 8. 26..
//  Copyright © 2017년 지소현. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int M,N,tomato_cnt=0;
    int x,y;
    int tomato[1001][1001];
    
    queue<pair<int,int> > q;
    scanf("%d%d",&M,&N);
    for(int i=1; i<=N; i++) {       //세로N
        for(int j=1; j<=M; j++) {   //가로M
            scanf("%d",&tomato[i][j]);

            if(tomato[i][j]==1) {
                q.push(make_pair(i,j));
                tomato_cnt++;
            } else if(tomato[i][j]==0) {
                tomato_cnt++;
            }
        }
    }

    
    if(q.size()==0) {   //토마토가없을때
        printf("-1\n");
        return 0;
    }
    
    if(q.size()==M*N) { //다익었을때
        printf("0\n");
        return 0;
    }
    int maxCnt = 0;
    while(!q.empty()) {

            x = q.front().first;
            y = q.front().second;
            q.pop(); tomato_cnt--;
    /*
            const int dx[] = { 0,0,-1,1 };
            const int dy[] = { -1,1,0,0 };
            
            for(int i=0; i<4; i++) {
                int xPos = x+dx[i];
                int yPos = y+dy[i];
                if(xPos<1 || xPos>N || yPos<1 || yPos>M)
                    continue;
                if(tomato[xPos][yPos]==0){
                    tomato[xPos][yPos] = tomato[x][y] + 1;
                    if(maxCnt <tomato[xPos][yPos])
                        maxCnt = tomato[xPos][yPos];
                    q.push(make_pair(xPos,yPos));
                }
            }
    }
    */
            
             if(x-1>0 && tomato[x-1][y]==0){   //위
                 tomato[x-1][y] = tomato[x][y] + 1;
                 if(maxCnt <tomato[x-1][y])
                     maxCnt = tomato[x-1][y];
                 q.push(make_pair(x-1,y));
             }
             if(y-1>0 && tomato[x][y-1]==0){   //좌
                 tomato[x][y-1] = tomato[x][y] + 1;
                 if(maxCnt <tomato[x][y-1])
                     maxCnt = tomato[x][y-1];
                 q.push(make_pair(x,y-1));
             }
             if(x+1<=N && tomato[x+1][y]==0){   //아래
                 tomato[x+1][y] = tomato[x][y] + 1;
                 if(maxCnt <tomato[x+1][y])
                     maxCnt = tomato[x+1][y];
                 q.push(make_pair(x+1,y));
             }
             if(y+1<=M && tomato[x][y+1]==0){   //우
                 tomato[x][y+1] = tomato[x][y] + 1;
                 if(maxCnt <tomato[x][y+1])
                     maxCnt = tomato[x][y+1];
                 q.push(make_pair(x,y+1));
             }
        }


    if(tomato_cnt==0)
        printf("%d\n",maxCnt-1);
    else
        printf("-1\n");
    return 0;
}

