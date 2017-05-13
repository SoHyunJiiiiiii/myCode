//
//  main.cpp
//  blackjack
//
//  Created by 지소현 on 2016. 11. 2..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
class blackJack{
    
public:
    blackJack(int num);
    ~blackJack();
    int Min(int a,int b);
    int CharSum(int sum,int a_count);
    
private:
    int *array;
    
};
blackJack::blackJack(int num){
    array = new int[num];
}
blackJack::~blackJack(){
    delete [] array;
}
int blackJack::Min(int a,int b)
{
    a = abs(a-21);
    b = abs(b-21);
    
    if(a<=b)
        return 1;
    else
        return 11;
}

int blackJack::CharSum(int sum,int a_count)
{
    int tmp1,tmp2,result;

    
//    for(int i=0; i<ch_count; i++){
//        if(input[i] == 'J' || input[i] =='Q' || input[i] =='K'){
//            result = 10;
//        }
//    
//    
//        else if(input[i] == 'A'){
//        a_count++;
//        }
//    }
//
    if(sum<=10){
        if(sum + (11*1) + (1*(a_count-1))<=21)
            result = sum + (11*1) + (1*(a_count-1));
        else
            result = sum + (1*a_count);
    }
    
    else{
        tmp1 = sum + (1*a_count);
        tmp2 = sum + (11*a_count);
        // cout << "tmp1 " <<tmp1 << "tmp2 "<<tmp2 <<endl;
        
        if(tmp1 > 21 && tmp2 > 21){
            return 0;   //exceed
        }
        else if(tmp1<=21 && tmp2 > 21){
            result = tmp1;
        }
        else if(tmp1>21 && tmp2 <=21){
            result = tmp2;
        }
        
        else if(tmp1 <= 21 && tmp2 <= 21){
            result = sum + Min(tmp1,tmp2)*a_count;  //21에 가까운값 찾기
        }
        
        else{
            result = -1;    //error
        }
    }
    
    return result;
}


int main(int argc, const char * argv[])
{
    
    int input,cnt=0,interger_value,res;
    
    blackJack *bj = new blackJack(50);
    
    while(1){
        
        string inputs;
        getline(cin,inputs);
        
        if(inputs=="q")
            break;
        
        char * cstr = new char [inputs.length()+1];
        strcpy(cstr,inputs.c_str());
        
        char tmp[10];
        char ch_arr[10];
        int *array = new int[10];
        int count=0;
        int q=0,k=0;
        int sum=0;
        int a_count =0;
        int num = cstr[0]-'0';
        
        
        for(int i=1; i<= inputs.length(); i++){
            
            
            if(cstr[i]>= 'A' && cstr[i]<= 'Z'){
                ch_arr[q] = cstr[i];
                q++;
            }
            
            //숫자 두자리수일때 합쳐주기위해 임시 배열 저장=>atoi쓰기위해서
            else if(cstr[i]>= '0' && cstr[i]<= '9'){
                
                if(cstr[i]!=' '){
                    tmp[cnt++]=cstr[i];
                }
                
                if(cstr[i]==' ' && cnt==2){
                    interger_value = atoi(tmp);
                    count++;
                    // cout << "정수 "<< interger_value << "count " << count << endl;
                    //array[k] = interger_value;
                    sum += interger_value;
                  //  cout << "정수 "<< interger_value << "sum " << sum << endl;
                    //   cout << cstr[i-2] << cstr[i-1] <<endl ;
                    cstr[i-1] = '0';
                    cstr[i-2] = '0';
                }
                
                if(cstr[i]==' ')
                    cnt=0;
            }
        }
        
        
        
        //숫자만 먼저 처리
        for(int i=1; i<= inputs.length()+1; i++){
            
            if(cstr[i]>= '1' && cstr[i]<= '9'){
                array[k] = cstr[i]-'0';
                sum += array[k];
                k++;
                // cout << "array " <<array[k] << " sum " << sum <<endl;
                count++;
                //  cout << "1~9  :" << count << "array " << array[k-1] <<endl;
            }
            else if(cstr[i]>= 'a' && cstr[i]<= 'z'){
                sum = -1;
                // cout << "sum" << sum <<endl;
            }
            else if(cstr[i] >= 'A' && cstr[i] <='Z'){
                if(cstr[i] == 'J' || cstr[i] =='Q' || cstr[i] =='K'){
                    sum += 10;
                }
                else if(cstr[i]=='A')
                    a_count++;
            }
        }
        
        
      // cout << "sum " <<sum <<endl;

            res = bj->CharSum(sum,a_count);
                //cout << "ch " << ch_arr[i] << " count "<< count << endl;
                
                if(sum > 0){
                    sum = res;
                    // cout << "SUM " << sum <<"res " << res << endl;
                }
                else if(res==0){
                    sum = 0;
                }
                else if(res==-1)
                    sum = -1;
        
    
        
        
        if(sum==21)
            cout<<"BlackJack"<<endl;
        
        else if(sum==0 || sum>21)
            cout << "Exceed" << endl;
        
        //잘못된 입력일때
        else if(sum==-1)
            continue;
        else
            cout << sum << endl;
           // cout << "END SUM  "<< sum << endl;
        
        sum = 0;
    }
    return 0;
}

