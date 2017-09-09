//
//  main.cpp
//  11403_경로찾기
//
//  Created by 지소현 on 2017. 9. 9..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n;//정점의 갯수
int matrix[101][101];
int visited[101][101];
int v[101];

void DFS(int start,int finish) {

    //printf("dfs : %d->%d\n",start,finish);
    if(v[finish]==1)    return;
    v[finish] = 1;
    visited[start][finish]=1;
    
    for(int i=1; i<=n; i++) {
        if(matrix[finish][i]==1) {
            DFS(start, i);
        }
    }
    
}
void checkInit() {
    for(int i=1; i<=n; i++) {
        v[i] = 0;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d",&matrix[i][j]);
            visited[i][j]=0;
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(matrix[i][j]==1) {
                checkInit();
                DFS(i,j);
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ",visited[i][j]);
        }printf("\n");
    }
    
    return 0;
}
