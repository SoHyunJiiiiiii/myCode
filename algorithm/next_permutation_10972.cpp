//
//  main.cpp
//  다음수열(next_permutation)
//  오름차순...
//  Created by 지소현 on 2017. 7. 25..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
//#include <math.h>
//#include <stdlib.h>
//#include <utility>  //swap쓰기 위한 라이브러리
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N=0;
    
    //int max_i=0,max_j=0;
    
    cin >> N;
    vector<int> number(N);
    for( int i=0; i<N; i++) {
        cin >> number[i];
    }
    
    
    if(next_permutation(number.begin(),number.end())) {
    
        for(int i=0; i<N; i++) {
            cout << number[i] << " ";
        }
        
    } else {
        cout << "-1" ;
    }
    cout << "\n";
    
    
    return 0;
//    //A[i-1] < A[i]를 만족하는 가장 큰 i를 찾는다.
//    for(int i=N-1; i>0; i--) {
//        if(number[i-1] < number[i]) {
//            max_i = i;
//            break;
//        }
//    }
//    
//    //j>=i이면서 A[j]>A[i-1]를 만족하는 가장 큰 j를 찾는다.
//    for(int j=max_i; j<N; j++) {
//        if(number[max_i-1] < number[j] && max_j < number[j]) {
//            max_j = j;
//        }
//    }
//    
//    if(max_i==0 || max_j==0) {
//        cout << -1 << endl;
//        return 0;
//    }
//    
//    
//    //A[i-1]과 A[j]를 swap한다.
//    swap(number[max_i-1], number[max_j]);
//
//    
//    //A[i]부터 순열을 뒤집는다.
//    for(int i=max_i; i<N-1; i++) {
//        swap(number[i], number[i+1]);
//    }
//    
//    

}
