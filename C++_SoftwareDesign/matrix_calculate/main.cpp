//
//  main.cpp
//  final
//
//  Created by 지소현 on 2016. 12. 14..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include "matrix.hpp"
#include <iostream>
#include <map>
#include <ctype.h>
int main() {
    
    map<char,Matrix> matrices;
    int temp,col,row;
    string cmd;
    
    while (cmd != "quit") {
        char name,name1,name2,operators;
        int name1_,name2_;
        int state1=0,state2=0,cnt=0;
        Matrix A,B,C;
        
        
        cin >> cmd;
        
        if (cmd == "matrix") {
            cin >> name ;
            cin >> row >> col ;
            Matrix mt(row,col);
            
            for(int i = 0; i < row; i++ ){
                for(int j=0; j<col; j++){
                    cin >> temp;
                    mt.setValue(i,j,temp);
                }
            }
            matrices.insert(pair<char, Matrix> (name,mt));
            
            //print
            cout << name << ":" << endl;
            mt.Print();
            
        } else if (cmd == "list") {
            for(map<char,Matrix>::iterator it=matrices.begin(); it!=matrices.end(); it++){
                cout << it->first << " " << it->second.rows() << " " << it->second.cols() << endl;
            }
        } else if (cmd == "eval") {
            cin >> name1 >> operators >> name2 ;
            
            if(name1 >= 'a' && name1 <= 'z'){
                for(map<char,Matrix>::iterator it=matrices.begin(); it!=matrices.end(); it++){
                    if(it->first==name1){
                        A = (it->second);
                    }
                }
            }
            else if(name1 >= '0' && name1 <= '9'){
                //name1_ = name1 - '0';
                state1=1;
                cnt++;
                if(operators=='*'){
                    state1=2;
                }
            }
            
            if(name2 >= 'a' && name2 <= 'z'){
                for(map<char,Matrix>::iterator it=matrices.begin(); it!=matrices.end(); it++){
                    if(it->first==name2){
                        B = (it->second);
                    }
                }
            }
            else if(name2 >= '0' && name2 <= '9'){
                // name2_ = name2 - '0';
                state2=1;
                cnt++;
                if(operators=='*'){
                    state2=2;
                }
            }
            
            //하나만 숫자면 행렬로 바꿔줌
            if(state1==1 && state2==0){
                A = Matrix(B.rows(),B.cols());
                name1_ = name1 -'0';
                for (int i=0; i<B.rows(); i++){
                    for (int j=0; j<B.cols(); j++){
                        A.setAllElement(i,j,name1_);
                    }
                }
            }
            else if(state2==1 && state1==0){
                B = Matrix(A.rows(),A.cols());
                name2_ = name2 -'0';
                for (int i=0; i<A.rows(); i++){
                    for (int j=0; j<A.cols(); j++){
                        B.setAllElement(i,j,name2_);
                    }
                }
            }
            
            //둘다 숫자면 출력
            if(cnt==2){
                name1_ = name1 -'0';
                name2_ = name2 -'0';
                switch(operators){
                        
                    case '+':
                        cout << name1_+name2_ << endl;
                        break;
                        
                    case '-':
                        cout << name1_-name2_ << endl;
                        break;
                        
                    case '*':
                        cout << name1_*name2_ << endl;
                        break;
                }
            }
            //둘 중 하나라도 숫자가 아니라면 행렬 계산
            else{
                switch(operators){
                        
                    case '+':
                        C = A+B;
                        break;
                        
                    case '-':
                        C = A-B;
                        break;
                        
                    case '*':
                        if(cnt==1){
                            
                            if(state1==2){
                                name1_ = name1 -'0';
                                Matrix C(B.rows(),B.cols());
                                for (int i=0; i<B.rows(); i++){
                                    for (int j=0; j<B.cols(); j++){
                                        cout << B.getValue(i, j)*name1_ << " ";
                                    }
                                    cout << endl;
                                }
                            }
                            else if(state2==2){
                                name2_ = name2 -'0';
                                Matrix C(A.rows(),A.cols());
                                for (int i=0; i<A.rows(); i++){
                                    for (int j=0; j<A.cols(); j++){
                                        cout << A.getValue(i, j)*name2_ << " ";
                                        //C.setValue(i, j, A.getValue(i, j) * name2_);
                                    }
                                    cout << endl;
                                }
                            }
                        }
                        else if(cnt==0){
                            C = A*B;
                        }
                        break;
                }
                C.Print();
            }
        }
    }
    
    
    return 0;
}

