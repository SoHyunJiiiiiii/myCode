//
//  main.cpp
//  다트게임
//
//  Created by 지소현 on 2017. 9. 16..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    char buffer[3];
    int k=0;
    for(int i=0; i<dartResult.length(); i++) {
        if(dartResult[i]=='*') {    //아차상 해당점수 *(-1)
            int cnt=0;
            for(int i=score.size()-1; i>=0; i--) {
                if(cnt==2)  break;
                score[i] *= 2;
                cnt++;
            }
        } else if(dartResult[i]=='#') { //스타상 (이전점수+해당점수)*2
            score[score.size()-1] *= (-1);
            
        } else {    //숫자랑 알파벳일때
            
            if(dartResult[i]>='0' && dartResult[i]<='9') {
                buffer[k++] = dartResult[i];
            } else {
                int num = atoi(buffer);
                if(dartResult[i]=='T') {
                   // printf("%d^3\n",num);
                    score.push_back(pow(num,3));
                } else if(dartResult[i]=='D') {
                   // printf("%d^2\n",num);
                    score.push_back(pow(num,2));
                } else {
                   // printf("%d^1\n",num);
                    score.push_back(num);
                }
                //buffer 비우기
                for(int i=0; i<3; i++) {
                    buffer[i] = '\0';
                } k=0;
            }
            
        }
        
    }
    
    for(int i=0; i<score.size(); i++) {
        answer += score[i];
    }
    //printf("%d",answer);
        return answer;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string str;
    cin >> str;
    solution(str);
    return 0;
}
