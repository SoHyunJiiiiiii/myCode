//
//  omok.hpp
//  6_1
//
//  Created by 지소현 on 2016. 11. 5..
//  Copyright © 2016년 지소현. All rights reserved.
//

#ifndef omok_hpp
#define omok_hpp
#include <iostream>
#define BLANK 0
#define BLACK 1
#define WHITE 2

using namespace std;
class Omok{
public:
    //Omok 초기화 //2차원포인터 배열 생성
    Omok() : width_(19),height_(19){
        TwoArray = new int*[width_];
        for (int i=0; i<height_; i++)
            TwoArray[i] = new int[height_];
        
        //0으로 값 다 초기화
        for(int i=0; i<19;i++){
            for (int j=0; j<19; j++) {
                TwoArray[i][j]=0;
                //cout<<TwoArray[i][j];
            }
            // cout<<endl;
        }
    }
    
    ~Omok(){
        for(int i=0; i<19; i++)
            delete [] TwoArray[i];
        delete [] TwoArray;
    }
    
    // 번갈아 (x,y)에 돌을 놓음  (x,y = 0~18) . 첫 수는 항상 흑돌로 가정.
    // 판 바깥쪽에 놓거나 이미 놓인 자리에 놓을 경우 false를 리턴.
    // 정상적인 경우 돌을 놓고 blacks_turn_을 턴에 맞게 세팅.
    bool Put(int x, int y,int idx);
    
    // 현재 오목이 나왔는지 판단하여 오목인 경우 true를 리턴하고,
    // is_winner_black 은 흑돌이 이긴 경우 1로, 백돌이 이긴 경우 0로 // 결판이 안나면 -1로
    int IsOmok()const;
    void PrintOmok();
    
private:
    int width_, height_;
    int **TwoArray;
};

#endif /* omok_hpp */
