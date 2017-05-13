//
//  Longest_common_sequence.cpp
//
//  Created by JISOHYUN on 2016. 10. 21..
//  Copyright © 2016년 JISOHYUN. All rights reserved.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
#define MAXSIZE 500
void LCSLength(char *x, char *y, int len_x, int len_y,char** LCS)
{
    int i = 0, j = 0;
    
    for (i = 0; i <= len_x; i++)
    {
        LCS[i][0] = 0;
    }
    for (j = 0; j <= len_y; j++)
    {
        LCS[0][j] = 0;
    }
    
    for (i = 1; i <=len_x; i++)
    {
        for (j = 1; j <= len_y; j++)
        {
            if (x[i-1] == y[j-1]){
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else
                LCS[i][j] = LCS[i][j - 1] >= LCS[i - 1][j] ? LCS[i][j - 1] : LCS[i - 1][j]  ;
        }
    }
}
void backTrack(char *x, char *y, int len_x, int len_y,char** LCS)
{
    int i = len_x;
    int j = len_y;
    
    std::stack<char> Stack;
    int cnt=0;
    
    if (len_x == 0 || len_y == 0)
        return;
    if (LCS[i][j] > LCS[i - 1][j] && LCS[i][j] > LCS[i][j - 1] && LCS[i][j] > LCS[i - 1][j - 1])
    {
        Stack.push(x[i-1]);
        cnt++;
        backTrack(x, y, i - 1, j - 1,LCS);
    }
    else if (LCS[i][j] > LCS[i - 1][j] && LCS[i][j] == LCS[i][j - 1])
    {
        backTrack(x, y, i, j - 1,LCS);
    }
    else //if (LCS[i][j] == LCS[i - 1][j] && LCS[i][j] > LCS[i][j - 1])
    {
        backTrack(x, y, i - 1, j,LCS);
    }
    
    for(int i=0; i<cnt; i++){
        printf("%c",Stack.top());
        Stack.pop();
    }
    
}
int main(void)
{
    int i = 0, j = 0;
    int len_x = 0, len_y = 0;
    char buff1[MAXSIZE];
    char buff2[MAXSIZE];
    
    gets(buff1);
    gets(buff2);
    
    len_y = strlen(buff1);
    len_x = strlen(buff2);
    
    if(len_x>500 || len_y>500)
        return 0;
    
    int max = len_x>len_y? len_x : len_y;
    int min = len_x<len_y? len_x : len_y;
    
    char *max_arr = (char*) calloc(sizeof(char),max+1);
    char *min_arr = (char*) calloc(sizeof(char),min+1);
    
    if(max==len_y){
        strcpy(max_arr,buff1);
        strcpy(min_arr,buff2);
    }
    else{
        strcpy(max_arr,buff2);
        strcpy(min_arr,buff1);
    }
    

    char** LCS = (char**)calloc(sizeof(char*),(min+1));
    for (i=0; i<=min; i++) {
        LCS[i] = (char*)calloc(sizeof(char),(max+1));
        for (j=0; j<=max; j++) {
            LCS[i][j]=0;
        }
    }
    
    
    LCSLength(min_arr, max_arr, min, max,LCS);

    backTrack(min_arr, max_arr, min, max,LCS);
    printf("\n");
    
    
    for (i=0; i<=min; i++) {
        free( LCS[i] );
    }
    free(LCS);
    free(max_arr);
    free(min_arr);
    return 0;
}

