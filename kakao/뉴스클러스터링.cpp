//
//  main.cpp
//  뉴스클러스터링
//
//  Created by 지소현 on 2017. 9. 17..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>//중복 허용x
using namespace std;
//교집합
int Intersection(vector<string> st1,vector<string> st2) {
    int cnt=0;
    int st1_overlap_cnt=0,st2_overlap_cnt=0;
    set<string> overlap1,overlap2;
    for(int i=0; i<st1.size(); i++) {
        for(int j=i; j<st1.size(); j++) {
            if(st1[i].compare(st1[j])==0) {
                st1_overlap_cnt++;
                overlap1.insert(st1[i]);
                if(j<st1.size()-1){
                    st1[j].erase();
                } else {
                    st1[i].erase();
                }
                
            }
        }
    }
    if(st1_overlap_cnt!=0) {
        st1_overlap_cnt++;
    }

    for(int i=0; i<st2.size(); i++) {
        for(int j=i; j<st2.size(); j++) {
            if(st2[i].compare(st2[j])==0) {
                st2_overlap_cnt++;
                overlap2.insert(st2[i]);
                if(j<st2.size()-1){
                    st2[j].erase();
                } else {
                    st2[i].erase();
                }
            }
        }
    }
    if(st2_overlap_cnt!=0) {
        st2_overlap_cnt++;
    }
    
    int inter_overlap_cnt = min(st1_overlap_cnt,st2_overlap_cnt);
    int union_overlap_cnt = max(st1_overlap_cnt,st2_overlap_cnt);
    

//    for(int i=0; i<st1.size(); i++) {
//        cout << "v1" << st1[i] << endl;
//    }
//    for(int i=0; i<st2.size(); i++) {
//        cout << "v2" << st2[i] << endl;
//    }
//    
    for(int i=0; i<st1.size(); i++) {
        for(int j=0; j<st2.size(); j++) {
            if(st1[i].compare(st2[j])==0) {
                cnt++;
            }
        }
    }
    printf("cnt %d\n",cnt);
    return cnt;
}

int solution(string str1,string str2) {
    int answer = 0;


    //문자열 2글자씩 잘라서 보관
    vector<string> st1,st2;

    for(int i=0; i<str1.length(); i++) {
        //알파벳인지 체크
        if(((str1[i]>='A' && str1[i]<='Z') || (str1[i]>='a' && str1[i]<='z')) &&
           ((str1[i+1]>='A' && str1[i+1]<='Z') || (str1[i+1]>='a' && str1[i+1]<='z'))){
            string tmp;
            str1[i] = toupper(str1[i]);
            str1[i+1] = toupper(str1[i+1]);
            tmp += str1[i];
            tmp += str1[i+1];
            st1.push_back(tmp);
        }

    }
    

    for(int i=0; i<str2.length(); i++) {

        if(((str2[i]>='A' && str2[i]<='Z') || (str2[i]>='a' && str2[i]<='z')) &&
           ((str2[i+1]>='A' && str2[i+1]<='Z') || (str2[i+1]>='a' && str2[i+1]<='z'))){
            string tmp;
            str2[i] = toupper(str2[i]);
            str2[i+1] = toupper(str2[i+1]);
            tmp += str2[i];
            tmp += str2[i+1];
            st2.push_back(tmp);
        }
    }
    
    int intersection_cnt = Intersection(st1, st2);
    int union_cnt = (int)st1.size()+(int)st2.size()-intersection_cnt;
    
    float jaccard = (double)intersection_cnt/(double)union_cnt ;
    answer = (int)(jaccard*65536);
    
    return answer;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string str1,str2;
    cin >> str1 >> str2;
    cout << solution(str1, str2)<<endl;
    return 0;
}
