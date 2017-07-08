//
//  main.cpp
//  숫자삼각형
//
//  Created by 지소현 on 2017. 7. 6..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int stairs ;
    cin >> stairs;
    int max[501][501] = {0,};
    int num[501][501] = {0,};
    

    for(int i=0; i<stairs; i++) {
        for(int j=0; j<i+1; j++) {
            cin >> num[i][j];
        }
    }
    
    max[0][0] = num[0][0]; //제일 처음(1층)값
    
    for(int i=0; i<stairs-1; i++) {
        for(int j=0; j<i+1; j++) {
            //최대값 저장
            if(max[i][j] + num[i+1][j] > max[i+1][j]) {     // 왼쪽 대각선 이동
                max[i+1][j] = max[i][j]+num[i+1][j];
            }
            if(max[i][j] + num[i+1][j+1] > max[i+1][j+1]) {     // 오른쪽 대각선 이동
                max[i+1][j+1] = max[i][j] +num[i+1][j+1];
            }
        }
    }
    
    
    //cout << "max값" <<endl;
    int result=0;
    for(int i=0; i<stairs; i++) {
       // cout << max[stairs-1][i] << endl;
        if(max[stairs-1][i] > result) {
            result = max[stairs-1][i];
        }
    }
    
    cout << result << endl;
    
    return 0;
}
