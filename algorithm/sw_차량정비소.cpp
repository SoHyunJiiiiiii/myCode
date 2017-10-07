//
//  main.cpp
//  차량정비소
//
//  Created by 지소현 on 2017. 10. 1..
//  Copyright © 2017년 지소현. All rights reserved.
//  46개 맞았음..
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct receipt_info {
    
    int num;        //창구 번호
    int prior_num;  //이전 창구번호(접수창구만 기억)
    int finishTime;  //처리중인 고객이 있다면 시작시간+처리시간 = 도착시간 기억해놓기
    int customer;
    receipt_info(int num_,int prior_num_,int finishTime_,int customer_) : num(num_),
    prior_num(prior_num_),finishTime(finishTime_), customer(customer_) {}
};
bool sortCustomer(receipt_info st1, receipt_info st2) {
    return st1.customer < st2.customer;
}
bool sortFinish (receipt_info st1, receipt_info st2) {
    return st1.finishTime < st2.finishTime;
}
bool sortPriorNum (receipt_info st1, receipt_info st2) {
    if(st1.finishTime==st2.finishTime)
        return st1.prior_num < st2.prior_num;
    return st1.finishTime < st2.finishTime;
}

int main() {
    //접수 창구의 개수 N, 정비 창구의 개수 M, 차량 정비소를 방문한 고객의 수 K,
    //지갑을 두고 간 고객이 이용한 접수 창구번호 A와 정비 창구번호 B
    int T,N,M,K,A,B;
    int a[12],b[12];  //a는 접수창구, b는 정비창구
    int c[1002];     //c는 고객 도착시간
    
    cin >> T;
    for(int z=1; z<=T; z++) {
        
        cin >> N >> M >> K >> A >> B;
        
        vector<int> a_,b_;  //비어있는 창구 표시
        for(int i=1; i<=N; i++) {
            cin >> a[i];
            a_.push_back(i);
        }
        sort(a_.begin(),a_.end());
        for(int i=1; i<=M; i++) {
            cin >> b[i];
            b_.push_back(i);
        }
        sort(b_.begin(),b_.end());
        for(int i=1; i<=K; i++) {
            cin >> c[i];
        }
        
        int sum=0;
        int i=1;    //현재 처리중인 고객번호
        bool exitflag = false;
        vector<receipt_info> finishA,finishB;    //a창구,b창구에 접수한 고객들과 끝나는 시간들
        vector<receipt_info> waita,waitb;   //a,b창구 기다리는 사람들
        
        for(int currentTime=0; ; currentTime++) {
            
            //a창구에 기다리는 사람들을 queue에 넣어줌
            for(int j=i; j<=K ;j++) {
                if(c[j]>currentTime)    break;
                waita.push_back(receipt_info(0,0,0,j));
                i++;    //고객한명 처리함
            }
            
            //finishA에 끝나는 시간과 현재시간(currentTime)이 같으면
            //1) finishA로부터 pop 해준 후에 비어있는창구a_에 추가함 2)b창구 대기자로 보냄
            while(finishA.size()!=0) {
                
                if(finishA[0].finishTime > currentTime) break;
                
                //비어있는 a창구의 번호 : goA
                int goA = finishA[0].num;
                a_.push_back(goA);
                
                int finish = finishA[0].finishTime;
                int cus = finishA[0].customer;
                
                waitb.push_back(receipt_info(0,goA,finish,cus));
                finishA.erase(finishA.begin());
                //cout << currentTime << "분 일 때 "<<finishA[0].customer<< "나가서 " << goA << " 비워둠 \n" ;
            }
            
            //finishB에 끝나는 시간과 현재시간(currentTime)이 같으면
            //1) finishB로부터 pop해준 후에 비어있는창구 b_에 추가함 2)A,B창구가 같은지 확인후,같다면 결과값에 더해줌
            while(finishB.size()!=0) {
                
                if(finishB[0].finishTime > currentTime) break;
                
                if( finishB[0].prior_num==A && finishB[0].num==B ) {
                    sum += finishB[0].customer;
                }
                
                int goB = finishB[0].num;
                if(finishB[0].customer == K)    exitflag=true;
                b_.push_back(goB);
                finishB.erase(finishB.begin());
                //cout << currentTime <<"분 일때 ***** ("<< finishB[0].prior_num << "=>" << finishB[0].num << ") : "  << finishB[0].customer << "번 고객이 끝나는 시간은 "<< finishB[0].finishTime << "pop" << endl;
            }
            
            
            //비어있는 접수창구(goA)가 있다면 그자리에 고객을 보냄
            while( !a_.empty() && !waita.empty()) {
                sort(a_.begin(), a_.end());
                int goA = a_[0];   a_.erase(a_.begin());
                
                sort(waita.begin(),waita.end(),sortCustomer); //고객번호 낮은순서대로 우선접수
                int waitedCus = waita[0].customer;   waita.erase(waita.begin());
                finishA.push_back(receipt_info( goA,0,a[goA]+currentTime,waitedCus));
                sort(finishA.begin(),finishA.end(),sortFinish);
                //cout << currentTime << "분 일 때 " << waitedCus << "고객 "<< goA << "번 창구 " << a[goA]+currentTime<< " push \n" ;
            }
            
            //비어있는 정비창구(goB)가 있다면 .. waitb에 있는 대기자를 비어있는 정비창구(b_)로부터 goB를 꺼내와서 보냄
            while(!b_.empty() && !waitb.empty()) {
                sort(b_.begin(), b_.end());
                int goB = b_[0];   b_.erase(b_.begin());
                
                // 접수 창구에서 동시에 접수를 완료하고 정비 창구로 이동한 경우, 이전 접수 창구번호가 낮은 순서대로
                // 동시 완료 아닐 시에는 finishTime 기준으로 오름차순 정렬
                sort(waitb.begin(),waitb.end(),sortFinish);
                sort(waitb.begin(),waitb.end(),sortPriorNum);
                
                int waitedCus = waitb[0].customer;
                int goA = waitb[0].prior_num;
                waitb.erase(waitb.begin());
                finishB.push_back(receipt_info(goB, goA, b[goB]+currentTime, waitedCus));
                sort(finishB.begin(),finishB.end(),sortFinish);
                //cout << waitedCus << " 고객을 " << goB << "b로 보냄.." <<b[goB]+currentTime <<"에ㄱ ㄱ끝남" <<endl;
            }
            if(exitflag)    break;
        }
        if(sum==0)  cout << "#" << z <<" -1\n";
        else    cout << "#" << z << " " << sum << "\n";
        
    }
    return 0;
}


