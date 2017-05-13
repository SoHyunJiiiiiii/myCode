//
//  matrix.cpp
//  final
//
//  Created by 지소현 on 2016. 12. 15..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include "matrix.hpp"
#include <algorithm>
Matrix::Matrix(int row, int col){ //defines the constructor to create a new matrix
    rows_ = row;
    cols_ = col;
    array = new int*[rows_];
    for (int i=0; i<rows_; i++){
        array[i] = new int[cols_];
    }
    for (int i=0; i<rows_; i++){
        for (int j=0; j<cols_; j++){
            array[i][j] = 0;
        }
    }
}
Matrix::Matrix(const Matrix& m){ //defines the copying constructor
    rows_ = m.rows_;
    cols_ = m.cols_;
    array = new int*[rows_];
    for (int i=0; i<rows_; i++){
        array[i] = new int[cols_];
    }
    for (int i=0; i<rows_; i++){
        for (int j=0; j<cols_; j++){
            array[i][j] = m.array[i][j];
        }
    }
}
Matrix::Matrix(int row, int col,int myarray[]){
    Matrix new_mt(row,col);
    
    int k=0;
    for (int i=0; i<rows_; i++){
        for (int j=0; j<cols_; j++,k++){
            array[i][j] = myarray[k];
            cout << array[i][j] << " " ;
        }cout << endl;
    }
}


Matrix::~Matrix(){ //defines the destructor
        for (int i=0; i<rows_; i++){
            delete[] array[i];
        }
    delete[] array;
}

void Matrix::setValue(int row, int col, int element){
    array[row][col] = element;
}


void Matrix::setColumn(int col){
    cols_=col;
}

int* Matrix::getColumn(int col){
    int *output = new int[rows_];
    for (int i=0; i<rows_; i++){
        output[i] = array[i][col];
    }
    return output;
}

void Matrix::setRow(int row){
    rows_ = row;
}

int* Matrix::getRow (int row){
    int *output = new int[cols_];
    for (int i=0; i<cols_; i++){
        output[i] = array[row][i];
    }
    return output;
}
void Matrix::setAllElement(int r, int c, int e){
    array[r][c] = e;
};
// overload + operator
Matrix Matrix::operator+(const Matrix& M){
    //  if matrices do not have the same size, return original matrix
    Matrix x(*this);
    if (this->cols_ != M.cols() || this->rows_ != M.rows()){
        cerr << "Invalid operation";
        return (*this);
    }
    //Matrix new_mat(rows_,cols_);
    for (int i=0; i<rows_; i++){
        for (int j=0; j<cols_; j++){
            x.array[i][j] = x.array[i][j] + M.array[i][j];
        }
    }
    return (x);
}

// overload - operator
Matrix Matrix::operator-(const Matrix& M){
    //  if matrices do not have the same size, return original matrix
    Matrix x(*this);
    if (this->cols_ != M.cols() || this->rows_ != M.rows()){
        cerr << "Invalid operation";
        return (*this);
    }
    //Matrix new_mat(rows_,cols_);
    for (int i=0; i<rows_; i++){
        for (int j=0; j<cols_; j++){
            x.array[i][j] = x.array[i][j] - M.array[i][j];
        }
    }
    return (x);
}
// overload * operator
Matrix Matrix::operator*(const Matrix& M){
    
    //  if matrices do not have the same size, return original matrix
    
    if (this->cols_ != M.rows_){
        cerr << "Invalid operation";
        return (*this);
    }
    
    Matrix Result(this->rows_,M.cols());
    
    for(int i=0; i < this->rows_; i++){
        for (int j=0; j < M.cols(); j++){
            for(int inner=0; inner < this->cols_; inner++){
                Result.array[i][j] += (this->array[i][inner] * M.array[inner][j]);
            }
        }
    }
    
    return Result;
}
Matrix operator*(const Matrix& lm, const int& a) {

    Matrix Result(lm.rows(),lm.cols());
    for(int i = 0 ; i < lm.cols(); i++){
        for(int j=0; j< lm.rows(); j++){
            Result.setValue(i, j,(lm.getValue(i, j)*a) );
        }
    }
    return Result;
}


Matrix& Matrix::operator=(const Matrix& M)
{
    
    if(this==&M)
        return(*this);
    
    this->rows_=M.rows_;
    this->cols_=M.cols_;
    
    this->array = new int*[rows_];
    for (int i=0; i<rows_; i++){
        this->array[i] = new int[cols_];
        for(int j=0;j<cols_;j++){
            this->setValue(i, j, M.array[i][j]);
        }
    }
    return(*this);
    
}

void Matrix::Print(){
    
    for (int i=0; i<rows_; i++){
        for (int j=0; j<cols_; j++){
            cout << getValue(i,j) << " ";
        }
        cout << endl;
    }
}

 Matrix operator-(const Matrix& lm, const Matrix& rm) {
     Matrix Result(lm.rows(),lm.cols());
     for(int i = 0 ; i < lm.cols(); i++){
         for(int j=0; j< lm.rows(); j++){
             Result.setValue(i, j,(lm.getValue(i, j))-(rm.getValue(i, j)) );
         }
     }
     return Result;
 }

 Matrix operator+(const int& a, const Matrix& rm) {
     Matrix Result(rm.rows(),rm.cols());
     for(int i = 0 ; i < rm.cols(); i++){
         for(int j=0; j< rm.rows(); j++){
             Result.setValue(i, j,(rm.getValue(i, j))+a);
         }
     }
     return Result;
 }

 Matrix operator-(const int& a, const Matrix& rm){
     Matrix Result(rm.rows(),rm.cols());
     for(int i = 0 ; i < rm.cols(); i++){
         for(int j=0; j< rm.rows(); j++){
             Result.setValue(i, j,(rm.getValue(i, j))-a);
         }
     }
     return Result;
 }
 
 Matrix operator*(const int& a, const Matrix& rm) {
     Matrix Result(rm.rows(),rm.cols());
     for(int i = 0 ; i < rm.cols(); i++){
         for(int j=0; j< rm.rows(); j++){
             Result.setValue(i, j,(rm.getValue(i, j)*a) );
         }
     }
     return Result;
     
 }
 
 Matrix operator+(const Matrix& lm, const int& a) {
     Matrix Result(lm.rows(),lm.cols());
     for(int i = 0 ; i < lm.cols(); i++){
         for(int j=0; j< lm.rows(); j++){
             Result.setValue(i, j,(lm.getValue(i, j))+a);
         }
     }
     return Result;
 }

 Matrix operator-(const Matrix& lm, const int& a) {
     Matrix Result(lm.rows(),lm.cols());
     for(int i = 0 ; i < lm.cols(); i++){
         for(int j=0; j< lm.rows(); j++){
             Result.setValue(i, j,(lm.getValue(i, j))-a);
         }
     }
     return Result;
 }
 

