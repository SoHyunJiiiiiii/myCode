//
//  main.cpp
//  2383_점심 식사시간
//
//  Created by 지소현 on 2017. 10. 2..
//  Copyright © 2017년 지소현. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX 9999
using namespace std;
struct ResInfo {

    int personNum;   //사람번호
    int stairNum;   //계단번호
    int moveTime;    //이동시간
    int exitlong;   //계단길이
    int finishTime; //끝나는시간
    ResInfo(int personNum_,int stairNum_,int moveTime_,int exitlong_,int finishTime_) :  personNum(personNum_),stairNum(stairNum_),moveTime(moveTime_),exitlong(exitlong_),finishTime(finishTime_) {};
};
struct info{
    int num;
    int y;
    int x;
    int stairLong;
    info(int num_,int y_,int x_,int stairLong_) : num(num_),y(y_),x(x_),stairLong(stairLong_){ };
};
int n;
int map[11][11];
vector<ResInfo> res;
vector<info> peopleVec;
vector<info> stairsVec;
int ans = MAX;
int FindResult(vector<info>& permutation);

bool sortPerson(ResInfo st1, ResInfo st2) {
    if(st1.personNum==st2.personNum)
        return st1.stairNum < st2.stairNum;
    return st1.personNum < st2.personNum;
}
bool sortMoveTime(ResInfo st1, ResInfo st2) {
    return st1.moveTime < st2.moveTime;
}
bool sortFinishTime(ResInfo st1, ResInfo st2) {
    return st1.finishTime < st2.finishTime;
}
void dfs(vector<ResInfo>& permutation, int k) {
    
    if( permutation.size()==res.size()/2 ){
        
        cout <<endl<< "dfs: ";
        vector<ResInfo> copyVec;
        copy(permutation.begin(),permutation.end(),copyVec.begin());
        sort(copyVec.begin(),copyVec.end(),sortMoveTime);
        
        for(int k=0; k<permutation.size(); k++) {
            cout << permutation[k].personNum << "번 사람이 " << permutation[k].stairNum <<"번 계단을 내려감" << endl;
        }
        
        int pop=0;
        vector<ResInfo> wait,atStair;
        int stairs[11];
        memset(stairs, 0, sizeof(stairs));
        for(int i=0,currentTime=0; ; currentTime++) {
            
            //이동완료..현재 이용중인 계단(stair)과 계단이용중인 사람들(atStair) pop해줌
            while(atStair.size()!=0) {
                
                if(atStair[0].finishTime!=currentTime)  break;
                stairs[atStair[0].exitlong]--;
                pop++;
                atStair.erase(atStair.begin());
            }
            if(pop==res.size()/2)   {
                if( currentTime-1 < ans) ans = currentTime-1;
                break;
            }
            
            for(int j=0; j<wait.size(); j++) {
                ResInfo waited = wait[0];
                //계단은 최대 3명까지 이용가능..3명꽉차있으면 대기
                if(stairs[waited.exitlong]<3) {
                    wait.erase(wait.begin());
                    atStair.push_back(ResInfo(waited.personNum, waited.moveTime, waited.stairNum, waited.exitlong, waited.exitlong+currentTime));
                    sort(atStair.begin(),atStair.end(),sortFinishTime);
                    stairs[waited.exitlong]++;
                    
                    cout << currentTime << "분일 때 " << waited.personNum << "번 사람 " <<  waited.exitlong<<"계단을 내려가기 시작" << waited.exitlong+currentTime <<endl;
                }
            }
            
            //n번째 사람이 s번 계단 입구도착!
            while(currentTime == (permutation[i].moveTime)) {
                wait.push_back(permutation[i]);
                i++; //이동완료 했으면 사람 처리해줌 +1.
            }
        }cout << endl;
        permutation.erase(permutation.begin());
        
        cout << "pop :" ;
        for(int k=0; k<permutation.size(); k++) {
            cout << permutation[k].personNum << "번 사람이 " << permutation[k].stairNum <<"번 계단을 내려감" << endl;
        }
        copyVec.clear();
        return;
    }
    cout << k << "일때 " << res[2*k].personNum << "번 사람의 " <<res[2*k].stairNum<< "push" << endl;
    permutation.push_back(res[2*k]);
    dfs(permutation,k+1);
    
    cout << k << "일때 " << res[2*k+1].personNum<< "번 사람의 " <<res[2*k+1].stairNum << "push" << endl;
    permutation.push_back(res[2*k+1]);
    dfs(permutation,k+1);
    permutation.pop_back();
}

// - 사람이 현재 위치에서 계단의 입구까지 이동하는데 걸리는 시간으로 다음과 같이 계산한다.
// - 이동 시간(초) = | PR - SR | + | PC - SC |
//  (PR, PC : 사람 P의 세로위치, 가로위치, SR, SC : 계단 입구 S의 세로위치, 가로위치)
void calculateToExit() {

    for(int i=0; i<peopleVec.size(); i++) {
        for(int j=0; j<stairsVec.size(); j++) {
            int move = abs(peopleVec[i].y - stairsVec[j].y) + abs(peopleVec[i].x-stairsVec[j].x);
            res.push_back(ResInfo(i,j,move,stairsVec[j].stairLong,0));
        }
    }
    sort(res.begin(), res.end(), sortPerson);
}

int main() {
    
    int t;
    vector<ResInfo> permutation;
    int stairsCnt=0;
    int cnt=0;
    cin >> t;
    //test case : T
    for(int z=1; z<=t; z++) {
        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> map[i][j];
                if(map[i][j]>1) {   // 계단 벡터
                    stairsVec.push_back(info(stairsCnt,i,j,map[i][j]));
                    stairsCnt++;
                } else if(map[i][j]==1) {   // 사람 벡터
                    peopleVec.push_back(info(cnt,i,j,1));
                    cnt++;
                }
            }
        }
        calculateToExit();
        for(int k=0; k<res.size(); k++) {
            cout << k << ":"<<res[k].personNum << "번 사람이 " << res[k].stairNum <<"번 계단" << endl;
        }
        dfs(permutation, 0);
        
        cout << "#"<< z << " " << ans << endl;
        ans = MAX;
        res.clear();    stairsVec.clear();
    }
    return 0;
}
