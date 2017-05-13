//
//  matrix.hpp
//  final
//
//  Created by 지소현 on 2016. 12. 15..
//  Copyright © 2016년 지소현. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    Matrix() : rows_(0),cols_(0){}
    Matrix(int row, int col);
    Matrix(const Matrix& m);
    Matrix(int row, int col,int myarray[]);
    ~Matrix();
    
    int rows() const { return rows_; }
    int cols() const { return cols_; }
    void setValue(int r, int c, int e);
    int getValue (int row, int col) const{
        return array[row][col];
    }
    void setColumn (int r);
    int* getColumn (int c);
    void setRow (int r);
    int* getRow (int r);
    void setAllElement(int r, int c, int e);
    
    Matrix& operator=(const Matrix& M);
    Matrix operator+(const Matrix& M);
    Matrix operator*(const Matrix& M);
    Matrix operator-(const Matrix & M);
    
    void Print();
    void List();
    
private:
    int **array; // rows_ * cols_ 만큼의 정수를 가진 배열. int rows_, cols_;
    int rows_,cols_;
    
};

//ostream& operator<<(ostream& os, const Matrix& m);
//Matrix operator+(const Matrix& lm, const Matrix& rm);
//Matrix operator-(const Matrix& lm, const Matrix& rm);
//Matrix operator*(const Matrix& lm, const Matrix& rm);
//
//Matrix operator+(const int& a, const Matrix& rm);
//Matrix operator-(const int& a, const Matrix& rm);
//Matrix operator*(const int& a, const Matrix& rm);
//Matrix operator+(const Matrix& lm, const int& a);
//Matrix operator-(const Matrix& lm, const int& a);
Matrix operator*(const Matrix& lm, const int& a);

#endif /* matrix_hpp */
