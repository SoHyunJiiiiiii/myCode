//
//  main.cpp
//  2382_미생물격리
//
//  Created by 지소현 on 2017. 10. 3..
//  Copyright © 2017년 지소현. All rights reserved.
//  결과 : PASS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// index 기준 (상: 1, 하: 2, 좌: 3, 우: 4)
const int dy[5] = {0,-1,1,0,0};
const int dx[5] = {0,0,0,-1,1};
struct info {
    int y;
    int x;
    int num;
    int pos;
    info(int y_, int x_, int num_, int pos_) : y(y_), x(x_), num(num_), pos(pos_) {};
};
int turnDirect(int pos) {
    if(pos==1) return 2;
    else if(pos==2) return 1;
    else if (pos==3) return 4;
    else return 3;
}
bool sortNum(info st1, info st2) {
    return st1.num > st2.num;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    int N,M,K;  // 한 변에 있는 셀의 개수 N, 격리 시간 M, 미생물 군집의 개수 K
    int y,x,num,pos;
    
    cin >> T;
    for(int z=1; z<=T; z++) {
        vector<info> microbe;
        cin >> N >> M >> K;
        for(int i=0; i<K; i++) {
            cin >> y >> x >> num >> pos;
            microbe.push_back(info(y,x,num,pos));
        }
        
        for(int t=0; t<M; t++) {
            vector<info> next_microbe;
            for(int i=0; i<microbe.size(); i++) {
                bool flag=false;
                int ny = microbe[i].y + dy[microbe[i].pos];
                int nx = microbe[i].x + dx[microbe[i].pos];
                // 약품에 칠해진 셀 도착시 : 미생물 수 절반 , 이동방향 반대
                if(ny==0 || ny==N-1 || nx==0 || nx==N-1) {
                    microbe[i].num = (int)(microbe[i].num/2);
                    if(microbe[i].num==0)   flag = true;
                    microbe[i].pos = turnDirect(microbe[i].pos);
                }
                if(!flag)
                    next_microbe.push_back(info(ny,nx, microbe[i].num, microbe[i].pos));
            }
            
            //두개 이상 군집이 한셀에 모이는 경우 고려 (미생물 숫자 합쳐짐 , 미생물 수 가장 많은 군집의 이동방향)
            //한셀에 모이지 않는다면 그냥 추가해준다.
            vector<info> final_microbe;
            
            for(int i=0; i<next_microbe.size(); i++) {
                if(next_microbe[i].num==0)  continue;
                vector<info> same_microbe;
                same_microbe.push_back(next_microbe[i]);
                bool flag = false;
                for(int j=i+1; j<next_microbe.size(); j++) {
                    if((next_microbe[i].y == next_microbe[j].y) && (next_microbe[i].x==next_microbe[j].x)) {
                        same_microbe.push_back(next_microbe[j]);
                        next_microbe[j].num=0;
                    }
                }
                
                if(same_microbe.size()>1) {
                    sort(same_microbe.begin(), same_microbe.end(), sortNum);
                    int finalNum=0;
                    for(int n=0; n<same_microbe.size(); n++) {
                        finalNum += same_microbe[n].num;
                    }
                    final_microbe.push_back(info(same_microbe[0].y,same_microbe[0].x,finalNum,same_microbe[0].pos));
                    flag = true;
                }
                if(!flag)   final_microbe.push_back(next_microbe[i]);
            }
            
            microbe.clear();
            int sum=0;
            for(int i=0; i<final_microbe.size(); i++) {
                microbe.push_back(final_microbe[i]);
                if(t==M-1){
                    sum += final_microbe[i].num;
                }
            }
            final_microbe.clear(); next_microbe.clear();
            if(t==M-1) {
                cout << "#" << z << " " << sum << endl;
            }
        }
    }
    return 0;
}

