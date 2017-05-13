//
//  main.cpp
//  draw_points
//
//  Created by 지소현 on 2017. 1. 3..
//  Copyright © 2017년 지소현. All rights reserved.
//
#include <iostream>
#define      MAX_X  1024
#define      MAX_Y  1024
using namespace std;

class Screen {
private:
    int rows;
    int cols;
    char **screens;
public:
    Screen();
    ~Screen();
    bool DrawPoint(int x,int y);
    
};

Screen::Screen() {
    rows = 0;
    cols = 0;
    screens = new char*[MAX_Y];
    for(int i=0; i<MAX_Y; i++) {
        screens[i] = new char[MAX_X];
        for(int j=0; j<MAX_X; j++) {
            screens[i][j] = '.';
        }
    }
}
Screen::~Screen() {
    for(int i=0; i<MAX_Y; i++) {
        delete [] screens[i];
    }
    delete [] screens;
}
bool Screen::DrawPoint(int x,int y) {
    if(x > rows) {
        rows = x;
    }
    if(y > cols) {
        cols = y;
    }
    
    if ( y < 0 || x < 0 ) {
        return false;
    }
    for(int i=0; i<=cols; i++) {
        for(int j=0; j<=rows; j++) {
            if(i==y && j==x) {
                screens[i][j] = '*';
            }
            cout << screens[i][j] ;
        }
        cout << endl;
    }
    return true;
}
int main() {
    int x;
    int y;
    
    Screen sc;

    while (true) {
        /* input of 2 integers from users to represent a point */
        cin >> x >> y;

        if (!sc.DrawPoint(x, y) ) {
            break;
        }
    }
    sc.~Screen();
    return 0;
}
