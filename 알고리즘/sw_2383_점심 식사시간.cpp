//
//  main.cpp
//  2115_벌꿀채취
//
//  Created by 지소현 on 2017. 10. 8..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M,C; // 벌통들의 크기 N, 선택할 수 있는 벌통의 개수 M, 꿀을 채취할 수 있는 최대 양 C
int map[11][11];
int visited[11][11];
int flag[11] ;
int ans=0;
void powerset(vector<int>& data,int n,int depth)
{
 
    if(n==depth){
        int sum=0, profit=0;
       // printf("{");
        for(int i=0;i<n;i++){
            if(flag[i]==1) {
           // printf("%d ",data[i]);
                sum += data[i];
                profit += data[i]*data[i];
            }
        } //printf("}\n");
            if(sum<=C) {
                //cout << sum << " 이므로 " << profit;
                ans = max(ans,profit);
                //cout <<" " << ans << endl;
            }

        return;
    }
    flag[depth]=1;
    powerset(data,n,depth+1);
    flag[depth]=0;
    powerset(data,n,depth+1);
}

int calculateMaxProfit(vector<int>& honey) {
    
    
    ans = 0;
    memset(flag, 0, sizeof(flag));
    powerset(honey,(int)honey.size(),0);
    
    return ans;
}

int go() {
    //가로가 연속되도록 M개의 벌통 선택해서 채취함
  
    int cnt=0;
    int res = 0;
    
    for(int i=0; i<N; i++) {
        cnt=0;   vector<int> honeyB;
        for(int j=0; j+M-1<N; j++) {
            honeyB.clear(); cnt=0;
            
            if(visited[i][j]) {
                continue;
            }
            
            for(int k=j; k<j+M; k++) {
                if(visited[i][k]) {
                    continue;
                }
                honeyB.push_back(map[i][k]); cnt++;
            }
            
            if(cnt==M) {

                int maxProfit = calculateMaxProfit(honeyB);
                res = max(res,maxProfit);
                cnt=0;
                honeyB.clear();
            }
        }
    }
    return res;
}


int main() {
    
    int T;
    cin >> T;
    
    for(int tc=1; tc<=T; tc++) {
        
        int resA=0,resB=0;
        int RESULT=0;

        memset(visited, 0, sizeof(visited));
        memset(map, 0, sizeof(map));
        
        cin >> N >> M >> C ;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> map[i][j];
            }
        }
        
        //가로가 연속되도록 M개의 벌통 선택해서 채취함
        for(int i=0; i<N; i++) {
            for(int j=0; j+M-1<N; j++) {
                vector<int> honeyA;
                memset(visited, 0, sizeof(visited));
                
                for(int k=j; k<j+M; k++) {
                    visited[i][k] = true;
                    honeyA.push_back(map[i][k]);
                }
                
                resA = calculateMaxProfit(honeyA);
                resB = go();
                RESULT = max(RESULT,resA+resB);
            }
        }
        
        cout << "#" << tc << " "  << RESULT << endl;
        
    }
    return 0;
}
