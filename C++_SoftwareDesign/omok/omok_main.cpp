//
//  main.cpp
//  6_1
//
//  Created by 지소현 on 2016. 11. 4..
//  Copyright © 2016년 지소현. All rights reserved.
//
#include "omok.hpp"

int main()
{
    int idx=1;
    int x,y;
    int winner_check;
    bool put_check;
    int finish=0;
    
    Omok *om = new Omok();
    while(1){
        
        if(idx%2==1)
            cout<< "Black: " ;
        else
            cout<< "White: " ;
        
        cin >> y >> x;
        
        put_check = om->Put(x, y,idx);
        if(put_check==true)
            idx++;
        else
            continue;
        
        winner_check = om->IsOmok();
        
        switch(winner_check){
                
            case 1:
                om->PrintOmok();
                cout << "Winner: Black player" <<endl;
                finish=1;
                break;
                
            case 0:
                om->PrintOmok();
                cout << "Winner: White player" <<endl;
                finish=1;
                break;
            default:
                break;
        }
        if(finish==1)
            break;
    }
    return 0;
}

