//
//  omok.cpp
//  6_1
//
//  Created by 지소현 on 2016. 11. 5..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include "omok.hpp"
int Omok::IsOmok()const
{
    for(int i=0; i<19; i++){
        for(int j=0; j<15; j++){
            
            if(TwoArray[i][j] == BLACK && TwoArray[i][j+1] == BLACK && TwoArray[i][j+2] == BLACK && TwoArray[i][j+3] == BLACK && TwoArray[i][j+4] == BLACK){
                return 1;
            }
            
            else if(TwoArray[j][i] == BLACK && TwoArray[j+1][i] == BLACK && TwoArray[j+2][i] == BLACK && TwoArray[j+3][i] == BLACK && TwoArray[j+4][i] == BLACK){
                return 1;
            }
            if(TwoArray[i][j] == WHITE && TwoArray[i][j+1] == WHITE && TwoArray[i][j+2] == WHITE && TwoArray[i][j+3] == WHITE && TwoArray[i][j+4] == WHITE){
                return 0;
            }
            
            else if(TwoArray[j][i] == WHITE && TwoArray[j+1][i] == WHITE && TwoArray[j+2][i] == WHITE && TwoArray[j+3][i] == WHITE && TwoArray[j+4][i] == WHITE){
                return 0;
            }
        }
    }
    
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            
            if(TwoArray[i][j] == BLACK && TwoArray[i+1][j+1] == BLACK && TwoArray[i+2][j+2] == BLACK && TwoArray[i+3][j+3] == BLACK && TwoArray[i+4][j+4] == BLACK){
                return 1;
            }
            else if(TwoArray[i][j] == WHITE && TwoArray[i+1][j+1] == WHITE && TwoArray[i+2][j+2] == WHITE && TwoArray[i+3][j+3] == WHITE && TwoArray[i+4][j+4] == WHITE){
                return 0;
            }
            
        }
    }
    for(int i=4; i<19; i++){
        for(int j=0; j<19; j++){
            
            if(TwoArray[i][j] == BLACK && TwoArray[i-1][j+1] == BLACK && TwoArray[i-2][j+2] == BLACK && TwoArray[i-3][j+3] == BLACK && TwoArray[i-4][j+4] == BLACK){
                return 1;
            }
            else if(TwoArray[i][j] == WHITE && TwoArray[i-1][j+1] == WHITE && TwoArray[i-2][j+2] == WHITE && TwoArray[i-3][j+3] == WHITE && TwoArray[i-4][j+4] == WHITE){
                return 0;
            }
        }
    }
    
    return -1;
}



bool Omok::Put(int x,int y,int idx)
{
    
    if(x>18 || y>18){
        cout << "Can not be placed there."<<endl;
        return false;
    }
    if(TwoArray[x][y]==0){
        
        if(idx%2==1){
            TwoArray[x][y] = BLACK;  //black
        }
        else{
            TwoArray[x][y] = WHITE;  //white
        }
        return true;
    }
    
    // 이미 놓인자리
    else{
        cout << "Can not be placed there."<<endl;
        return false;
    }
}
void Omok::PrintOmok()
{
    for(int i=0; i<19;i++){
        for (int j=0; j<19; j++) {
            if(TwoArray[i][j]==0)
                cout << ". ";
            else if(TwoArray[i][j]==1)
                cout << "o ";
            else if(TwoArray[i][j]==2)
                cout << "x ";
        }
        cout << endl;
    }
}
