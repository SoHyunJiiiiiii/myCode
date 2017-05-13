//
//  main.cpp
//  draw_shape
//
//  Created by 지소현 on 2016. 11. 5..
//  Copyright © 2016년 지소현. All rights reserved.
//


#ifndef draw_shape_hpp
#define draw_shape_hpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum { RECTANGLE=1, TRIANGLE_UP=2, TRIANGLE_DOWN=3 };
enum { ERROR_OUT_OF_CANVAS = -1, ERROR_INVALID_INPUT = -2 };
struct Shape {
    Shape(int _x,int _y,int _height,char ch,int _type) : x(_x),y(_y),height(_height),brush(ch),type(_type) {}
    Shape(int _x,int _y,int _width,int _height,char ch,int _type) : x(_x),y(_y),height(_height),width(_width),brush(ch),type(_type) {}
    int type;
    int x, y;
    int width, height;
    char brush;  // The character to draw the shape.
};


class Canvas {
public:
    Canvas(size_t row, size_t col) : width_(row),height_(col){
        canvas_ = new char*[width_+1];
        
        for (int j=0; j<height_+1; j++)
            canvas_[j] = new char[height_+1];
        
        canvas_[0][0]=' ';
        
        for(int j=0; j<height_; j++){
            canvas_[0][j+1]=j+'0';
        }
        for(int i=0; i<width_; i++){
            canvas_[i+1][0]=i+'0';
        }
        for(int i=1;i<=width_;i++){
            for(int j=1; j<=height_;j++){
                canvas_[i][j]='.';
            }
        }
    };
    
    ~Canvas();
    int AddShape(Shape &s);  // Return the index of the shape.
    void DeleteShape(int index);
    void Draw();
    void Dump();
    void Print()const;
    int VectorSize();
    friend ostream& operator <<(ostream& os,const Shape& s);
    
private:
    size_t width_, height_;
    vector<Shape> shapes_;
    char **canvas_;
};

#endif /* draw_shape_hpp */
