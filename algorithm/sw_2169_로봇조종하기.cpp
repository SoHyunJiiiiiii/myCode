//
//  main.cpp
//  2169_로봇조종하기
//
//  Created by 지소현 on 2017. 10. 6..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
using namespace std;
int n,m;
int map[1001][1001];
int dp[1001][1001];
const int dy[3] = {0,0,1}; //왼,오,아래
const int dx[3] = {-1,1,0};
void go (int y, int x) {

    if(y==n && x==m)    return;
    if(dp[y][x])    return;
    if(dp[y][x] > dp[y][x] + map[y][x]) return;
    dp[y][x] += map[y][x];
    cout <<"go"<< y << " " << x << endl;
    for(int i=0; i<3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<=0 || nx<=0 || ny>n || nx>m)  continue;
        go(ny,nx);
    }
}

int main() {
    

    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> map[i][j];
        }
    }
    go(1,1);
    cout << dp[n][m] << endl;
    return 0;
}
