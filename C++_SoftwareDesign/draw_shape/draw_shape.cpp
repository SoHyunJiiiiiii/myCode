//
//  draw_shape.cpp
//  6_2
//
//  Created by 지소현 on 2016. 11. 9..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include "draw_shape.hpp"
int Canvas::AddShape(Shape &s){
    int result=1;
    
    
    if(s.type==RECTANGLE){
        for(int i=s.x; i<(s.x)+(s.width);i++){
            for(int j=s.y; j<(s.y)+(s.height); j++){
                if(i>width_ || j>height_)
                    return ERROR_OUT_OF_CANVAS;
            }
        }
    }
    
    else if(s.type==TRIANGLE_UP){
        
        for(int i=s.height-1; i>=0; i--){
            //s.x-i ~ s.x+i
            //s.y+i
            for(int j=s.x-i; j<=s.x+i; j++){
                if(s.y+i+1>width_ || j+1>height_)
                    return ERROR_OUT_OF_CANVAS;
            }
        }
    }
    
    
    else if(s.type==TRIANGLE_DOWN){
        for(int i=0; i<s.height; i++){
            //s.x-i ~ s.x+i
            //s.y+i
            for(int j=s.x-i; j<=s.x+i; j++){
                if(s.y+i+1>width_ || j+1>height_)
                    return ERROR_OUT_OF_CANVAS;
            }
        }
    }
    
    
    if(result==1){
        shapes_.push_back(s);
        //  cout << "push" << endl;
    }
    
    return 1;
}
int Canvas::VectorSize(){
    return (int)shapes_.size();
}
void Canvas::Draw()
{
    for(int k=0; k<shapes_.size(); k++)
    {
        switch(shapes_[k].type){
            case RECTANGLE:
                for(int i=shapes_[k].x; i<(shapes_[k].x)+(shapes_[k].width);i++){
                    for(int j=shapes_[k].y; j<(shapes_[k].y)+(shapes_[k].height); j++){
                        canvas_[i][j] = shapes_[k].brush;
                    }
                }
                break;
                
            case TRIANGLE_UP:
                
                for(int i=shapes_[k].height-1; i>=0; i--){
                    //s.x-i ~ s.x+i
                    //s.y+i
                    for(int j=shapes_[k].x-i; j<=shapes_[k].x+i; j++){
                        canvas_[shapes_[k].y+i+1][j+1] = shapes_[k].brush;
                    }
                }
                break;
                
                
            case TRIANGLE_DOWN:
                for(int i=0; i<shapes_[k].height; i++){
                    //s.x-i ~ s.x+i
                    //s.y+i
                    for(int j=shapes_[k].x-i; j<=shapes_[k].x+i; j++){
                        
                        if(shapes_[k].y+i+1<=width_ && j+1<=height_)
                            canvas_[shapes_[k].y-i+1][j+1] = shapes_[k].brush;
                    }
                }
                break;
        }
        
    }
}
void Canvas::DeleteShape(int index)
{
    char deleted = shapes_[index].brush;
    
    vector<Shape>::iterator it;
    it=shapes_.begin();
    
    for(int i=1;i<=width_;i++){
        for(int j=1; j<=height_;j++){
            if(deleted==canvas_[i][j])
                canvas_[i][j]='.';
        }
    }
    
    for(int i=0; i<index; i++){
        it++;
    }
    shapes_.erase(it);
}
void Canvas::Dump(){
    for(int i=0; i<shapes_.size(); i++)
    {
        if(shapes_[i].type==RECTANGLE){
            cout << i << " rect " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
        }
        else if(shapes_[i].type==TRIANGLE_DOWN){
            cout << i << " tri_down " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
        }
        else{  //shapes_[i].type==TRIANGLE_UP
            cout << i << " tri_up " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
        }
    }
    
}

void Canvas::Print()const
{
    
    for(int i=0;i<=width_;i++){
        for(int j=0; j<=height_;j++){
            
            cout << canvas_[i][j];
        }
        cout << endl;
    }
}
