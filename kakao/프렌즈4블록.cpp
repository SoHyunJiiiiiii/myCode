//
//  main.cpp
//  프렌즈4블록
//
//  Created by 지소현 on 2017. 9. 16..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
int visited[30][30]={0,};
int cnt=0;
using namespace std;
void bfs(int m, int n, vector<string> map) {
    //printf("bfs\n");
    queue<pair<int,int> > zero;
    for(int i=0; i+1<m; i++) {
        for(int j=0; j+1<n; j++) {
            char ch = map[i][j];
            if(ch=='Z') continue;
            //printf("map %d %d %c\n",i,j,ch);
            if(ch==map[i][j+1] && ch==map[i+1][j] && ch==map[i+1][j+1]) {
                
                for(int y=i; y<i+2; y++) {
                    for(int x=j; x<j+2; x++) {
                        if(visited[y][x]) continue;
                        visited[y][x]=1;    //블록이 지워짐을 표시
                        cnt++;
                        //printf("delete %d %d %d\n",y,x,cnt);
                        zero.push(make_pair(y,x));
                    }
                }
            }
        }
    }
    if(zero.size()==0){
        printf("%d",cnt);
        return;
    }
    //아래로 내려오니까..
    while (!zero.empty()) {
        int y=zero.front().first;
        int x=zero.front().second;
        zero.pop();
        //printf("zero %d %d\n",y,x);
        if(visited[y][x]==0)    continue;
        visited[y][x]=0; map[y][x]='Z';
        if(y-1<0)   continue;
        char replace = map[y-1][x];
        for(int i=y+1;i<n ; i++) {
            if(visited[i][x]==0) {  //이자리에 블록이 있다면..(그위에 블록쌓음)
                map[i-1][x]= replace; visited[i-1][x]=0;
                //printf("%d %d자리에 map[%d][%d] 블록 %c올려놓음\n",i-1,x,y-1,x,map[i-1][x]);
                break;
            }
        }
    }
    bfs(m,n,map);

}

int solution(int m, int n, vector<string> board) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            //cout << board[i][j];
            visited[i][j]=0;
        }//cout <<endl;
    }
    bfs(m,n,board);
    return cnt;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int m,n;
    vector<string> board;
    cin >> m >> n;

    char ch;
    for(int i=0; i<m; i++) {
        string str;
        for(int j=0; j<n; j++) {
            cin >> ch;
            str+=ch;
            visited[i][j]=0;
        } board.push_back(str);
    }
    solution(m, n, board);
    return 0;
}
