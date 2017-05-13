//
//  main.cpp
//  6_2
//
//  Created by 지소현 on 2016. 11. 9..
//  Copyright © 2016년 지소현. All rights reserved.
//


#include "draw_shape.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    int x,y;
    string menu,shape_decide;
    
    cin >> x >> y;
    
    Canvas *cv = new Canvas(x,y);
    
    
    int a,b,c,d,idx;
    char ch;
    
    cv->Print();
    
    while(1){
        int res;
        cin >> menu;
        
        if(menu.compare("add")==0){
            cin >> shape_decide;
            if(shape_decide.compare("rect")==0){
                cin >> a >> b >> c >> d;
                cin >> ch;
                if(c%2==0 || d%2==0){
                    cout << "error invalid input" << endl;
                }
                else{
                    Shape sp(a,b,c,d,ch,RECTANGLE);
                    res=cv->AddShape(sp);
                    if(res==-1)
                        cout << "error out of canvas" << endl;
                }
            }
            
            else if(shape_decide.compare("tri_down")==0){
                cin >> a >> b >> c;
                cin >> ch;
                
                Shape sp(a,b,c,ch,TRIANGLE_DOWN);
                res=cv->AddShape(sp);
                if(res==-1)
                    cout << "error out of canvas" << endl;
            }
            
            else if(shape_decide.compare("tri_up")==0){
                cin >> a >> b >> c;
                cin >> ch;
                
                Shape sp(a,b,c,ch,TRIANGLE_UP);
                res=cv->AddShape(sp);
                if(res==-1)
                    cout << "error out of canvas" << endl;
            }
            //            if(res==-1)
            //                cout << "error out of canvas" << endl;
        }
        
        else if(menu.compare("delete")==0){
            cin >> idx;
            int size = cv->VectorSize();
            // cout << "size " << size <<endl;
            if(idx < size){
                cv->DeleteShape(idx);
            }
        }
        else if(menu.compare("draw")==0){
            cv->Draw();
            cv->Print();
        }
        else if(menu.compare("dump")==0){
            cv->Dump();
        }
        else if(menu.compare("quit")==0){
            break;
        }
    }
    return 0;
}

