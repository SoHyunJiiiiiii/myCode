//
//  main.cpp
//  분해합
//
//  Created by 지소현 on 2017. 7. 27..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int FindGenerator(int N,int N_jarisu) {
    int temp,adder=0;
    
    for(int i=N-N_jarisu*9; i<N; i++) {

        //cout << endl << "i" << i << endl;
        for(int divider=pow(10,N_jarisu-1),temp=i; temp!=0 ; divider/=10) {
            
            adder += (temp /divider); //temp=i의 각자릿수 더하기
            temp = temp - divider *( temp / divider);
            
        }
        
        adder+=i;
        
        if(adder==N) {
            cout << i << '\n';
            return 1;
        } else {
            adder=0;
        }
    }
    return -1;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N, N_jarisu=0 ,temp;
    
    cin >> N;
    for(int i=1; ; i*=10) {
        temp =N;
        temp = temp / i; //10씩 나누기..몫이 0이 아닐때까지(자릿수 구하기)
        
        if(temp==0) {
            break;
        }
        N_jarisu++;
    }
    
    if(FindGenerator(N, N_jarisu)==-1) {
        cout << "0\n";
    }
    
    
    return 0;
}
