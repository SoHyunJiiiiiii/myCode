//
//  main.cpp
//  NHN엔터의모험
//
//  Created by 지소현 on 2017. 9. 23..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int main() {
  
    vector<int> total;
    vector<int> trash;
    vector<int> q;
    char str[128];
    gets(str);
    for(int i=0; str[i]!='\0'; i++) {
        if(str[i]!=' ') {
            
            int item = str[i]-'0';
            total.push_back(item);
            //printf("%d",item);
        }
    }
    
    for(int i=0; i<total.size(); i++) {
        if(q.size()==3) {
            bool flag = false;
            for(int j=0; j<3; j++) {
                if(q[j]==total[i]) {    //같은게 이미  있다면? 동료에게 선물(버리는거 없음)
                    q.erase(q.begin()+j);
                    q.push_back(total[i]);
                    flag = true;
                }
            }
            if(!flag) { //같은게 없다면 ? 가장오래된거 버리고 새거 넣음
                trash.push_back(q[0]);
                q.erase(q.begin());
                q.push_back(total[i]);
            }
        } else {
            q.push_back(total[i]);
        }
    }
    
    for(int i=0; i<trash.size(); i++) {
        printf("%d\n",trash[i]);
    }
    return 0;
}
