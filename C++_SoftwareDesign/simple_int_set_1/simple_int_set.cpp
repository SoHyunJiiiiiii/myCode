//
//  simple_int_set.cpp
//  simple_int_set
//
//  Created by 지소현 on 2016. 10. 8..
//  Copyright © 2016년 지소현. All rights reserved.
//


#include <iostream>
#include <sstream>
#include <string>
#include "simple_int_set.hpp"
#define MAX 1024
using namespace std;

simple_int_set::simple_int_set(int cnt1,int cnt2){
    arr1 = new int[cnt1];
    arr1_cnt = cnt1;
    arr2 = new int[cnt2];
    arr2_cnt = cnt2;
}

void simple_int_set::InsertKey(int *_arr1,int *_arr2){
    for(int i=0; i<arr1_cnt; i++)
    {
        arr1[i] = _arr1[i];
        // cout<<"arr1 "<<arr1[i]<<endl;
    }
    for(int i=0; i<arr2_cnt; i++)
    {
        arr2[i] = _arr2[i];
        // cout<<"arr2 "<<arr2[i]<<endl;
    }
    
}


void simple_int_set::SortArray(int *array,int size){
    
    int i, j, target;
    
    int* result;
    result = new int[size];
    
    for (i =0; i<size; i++)
        result[i] = array[i];
    
    for (i = 1; i < size; i++){
        target = result[i];
        
        for (j = i - 1; j >= 0; j--){
            if (result[j] > target)
                result[j + 1] = result[j];
            
            else
                break;
        }
        result[j + 1] = target;
    }
    
    
    // 중복된 원소가 아니라면 배열 출력
    cout << " { " ;
    for(int i=0; i<size; i++)
        if(result[i]!=result[i+1])
            cout << result[i] << " " ;
    
    cout << " } " << endl;
    
    
}

void simple_int_set::GetUnion(int *A, int *B){
    
    int i, j, check; //j, check 추가
    
    int *temp = new int[MAX];
    int *C = new int[MAX];   //교집합
    int *D = new int[MAX];   //합집합
    
    
    int nC=0;   //교집합 갯수
    //A와 B의 교집합을 구해서 C배열에 저장
    for(i=0; i<arr1_cnt; i++)
        for(j=0; j<arr2_cnt; j++)
            if(A[i] == B[j])
            {
                C[nC++] = A[i];
                break;
            }
    
    //A와 B의 원소를 모두 temp에 저장
    for(i=0; i<arr1_cnt; i++)
        temp[i] = A[i];
    for(j=0; j<arr2_cnt; j++)
        temp[i+j] = B[j];
    
    int nD = 0;
    //루프를 돌면서 교집합과 원소가 같으면 check 1로 되어 저장을 안하고
    //나머지 원소만 저장함
    for(i=0; i<(arr1_cnt+arr2_cnt); i++)
    {
        check = 0;
        for(j=0; j<nC; j++)
            if(temp[i] == C[j])
                check = 1;
        if(check == 0)
            D[nD++] = temp[i];
    }
    
    //나머지 교집합 원소 저장
    for(i=0; i<nC; i++)
        D[nD++] = C[i];
    
    SortArray(D, nD);
    
    
}

void simple_int_set::GetDifference(int *arr1, int *arr2){
    
    int same;
    int *result = new int[MAX];
    int res_cnt = 0;
    
    for(int i=0; i<arr1_cnt; i++)
    {   same=0;
        for(int j=0; j<arr2_cnt; j++)
        {
            if(arr1[i]==arr2[j])
                same=1;
        }
        if(same==0)
            result[res_cnt++]=arr1[i];
    }
    SortArray(result, res_cnt);
}

void simple_int_set::GetIntersaction(int *arr1, int *arr2){
    
    int *result = new int[MAX];
    int res_cnt = 0;
    
    for(int i=0; i<arr1_cnt; i++)
    {
        for(int j=0; j<arr2_cnt; j++)
        {
            if(arr1[i]==arr2[j])
                result[res_cnt++] = arr1[i];
        }
    }
    SortArray(result, res_cnt);
}


