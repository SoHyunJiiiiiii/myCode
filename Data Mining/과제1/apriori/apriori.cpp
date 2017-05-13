
//
//  Apriori.cpp
//  Aprioiri
//
//  Created by 지소현 on 2017. 3. 19..
//  Copyright © 2017년 지소현. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#define ROUNDING(x, dig)    ( floor((x) * pow(float(10), dig) + 0.5f) / pow(float(10), dig) )
using namespace std;


int minSupport;
int size_transaction;
char* output_name;

struct Itemset{
    set<int> frequent_itemset;
    int support_count;
    
    Itemset(set<int> itemset_,int suppport_count_) {
        frequent_itemset.insert(itemset_.begin(), itemset_.end());
        support_count = suppport_count_;
        
    }
};
int IsSubset(int num,vector<int> array){
    
    vector<int>::const_iterator it;
    it = find (array.begin(), array.end(),num);
    if (it != array.end()) {
        return 1;
    }
    return 0;
}

int getSupport(vector<vector<int> > transaction,set<int> *tempCset) {
    
    int *temp = new int[tempCset->size()];
    int current=0,support=0;
    for(set<int>::iterator it = tempCset->begin(); it != tempCset->end(); it++) {
        temp[current++] = (*it);
    }

    vector<int> transaction_row;
    for(int i=0; i<transaction.size(); i++) {
        transaction_row = transaction.at(i);
        
            int cnt=0,res=1;
            for(int i=0; i<current; i++) {
                res = IsSubset(temp[i], transaction_row);
                if(res==0) {
                    break;
                } else {
                    cnt++;
                }
            }
            
            if(res==1){
                support++;
            }
            transaction_row.clear();
    }
    return support;
}

//L(k)과 L(K)을 조인해서 L(k+1)만듬 //k=1(C3구함)
int make_Candidate_sets(vector<vector<int> > transaction,vector<vector<Itemset> > *L,int k) {
    
    set<int> cset;
    vector<Itemset> Ck;    // C(k) : candidate itemset of k+1 th
    int count = 0;
    
    
    //중복검사하면서 넣기
    for(int i=0; i<L->at(k).size(); i++) {
        
        for(int j=i+1; j<L->at(k).size(); j++) {
            
            cset.insert( L->at(k).at(i).frequent_itemset.begin(),
                        L->at(k).at(i).frequent_itemset.end()) ;
            cset.insert( L->at(k).at(j).frequent_itemset.begin(),
                        L->at(k).at(j).frequent_itemset.end()) ;
            
            
            if(cset.size()== (k+2)) {
                
                int ISsame = -1;
                //처음껀 무조건 중복안되니까 Ck에 넣는다.
                if ( count==0 ) {
                    //                        cout << "처음이니 넣는다" <<endl;
                    if(getSupport(transaction,&cset)>=minSupport) {
                        Itemset itemset(cset,getSupport(transaction,&cset));
                        Ck.push_back(itemset);
                        count ++;
                    }
                } else {
                    for(int i=0; i<Ck.size(); i++) {
                        if(cset==Ck.at(i).frequent_itemset) {
                            ISsame = 1;
                        }
                    }
                    
                    if(ISsame!=1) {
                        //                                cout << "중복안되니 넣음" << endl;
                        if(getSupport(transaction,&cset)>=minSupport) {
                            Itemset itemset(cset,getSupport(transaction,&cset));
                            Ck.push_back(itemset);
                            count++;
                        }
                    }
                    
                }
            }
            cset.clear();
            
        }
    }
    
    L->push_back(Ck);
    Ck.clear();
    
    return count;
}

// A=>B라고 가정한다면..
void print(vector<vector<int> > transaction,int result[], int length,int *arr,int arr_num) {
    
    ofstream output(output_name,ios::app);
    string s;
    stringstream ss;
    
    set<int> A ,B,AnB;
    int current =0,isSame;
    int totalSupport;
    double Support, Confidence;
    
    if(length>0) {
        
        // {A} 출력
        ss << "{" ;
    
        for (int i = 0; i < length; i++){
            ss << result[i] ;
            A.insert(result[i]);
            
            if(i != length-1) {
                ss << "," ;
            }
        }
        ss << "}" ;
        
        // {B} 출력..A에 포함되지 않은 원소들을 삽입
        for(int j=0; j<arr_num; j++) {
            
            isSame=0;
            for (set<int>::iterator it=A.begin(); it!=A.end(); it++) {
                
                if(arr[j] == (*it)){
                    isSame =1;  //같다면 1로 바꿔줌
                }
            }
            
            if(isSame!=1) {
                B.insert(arr[j]);
            }
        }
        
        ss << "\t" << "{" ;
        for(set<int>::iterator it=B.begin(); it !=B.end(); it++) {
            ss << (*it) ; current++;
            if(current < B.size()) {
                ss << "," ;
            }
        }
        ss << "}" << "\t" ;
        
        AnB.insert( A.begin(),A.end() ) ;
        AnB.insert( B.begin(),B.end() ) ;
        totalSupport = getSupport(transaction,&AnB);
        Support = (totalSupport / (double)size_transaction) *100;
        Confidence = (totalSupport / (double)getSupport(transaction,&A)) *100;
        ss.precision(2);
        ss <<fixed ;
        ss << ROUNDING(Support, 2) << "\t" << ROUNDING(Confidence, 2) << endl;
    
    }
        s= ss.str();
        output << s ;
}

//arr배열에서 중복이 없는 부분집합을 만듬
void Combination(vector<vector<int> > transaction,int *result,int index, int n, int r, int target,int *arr) {

    if (r == 0) {
        print(transaction,result, index,arr,n);

    } else if (target == n) {
        return;
    } else {
        result[index] = arr[target];
        Combination(transaction, result, index+1, n, r-1, target+1, arr);
        Combination(transaction, result, index, n, r, target+1, arr);
    }
    
}

//L(k+1)에 관한 연관법칙 구하기 ..  즉 k=1일땐 L(2)을 의미 ..
int DivideSubset(vector<vector<int> > transaction,vector<vector<Itemset> > *L,int k) {
    
    //L(k)의 i번째 itemset을 임시로 배열에 저장
    int *temp,q;
    int *result;
    
    for(int i=0; i<L->at(k).size(); i++) {
        
        int size = (int)L->at(k).at(i).frequent_itemset.size();
        temp= new int[size]; q=0;
        result = new int[size];
        for(set<int>::iterator it = L->at(k).at(i).frequent_itemset.begin() ;
            it != L->at(k).at(i).frequent_itemset.end(); it++) {
            temp[q++] = (*it);
        }
        
        for(int i=0; i<size; i++) {
            Combination(transaction, result,0,size,i, 0,temp);
        }
        
    }
    return 0;
}

int main(int argc, char ** argv) {
    
    int relative_support = atoi(argv[1]);
    char* input_name = argv[2];
    output_name = argv[3];
    
    char str[50];
    ifstream input;
    input.open(input_name);

    //전체 트랜잭션
    vector<vector<int> > transaction;
    vector<int> array;
    set<int> candidate_set;
    size_transaction=0;
    
    if(input.is_open()) {
        while(input.getline(str, sizeof(str))) {
            size_transaction++;
            char *ptr = strtok(str, "\t");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
            
            while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
            {
                int number = atoi(ptr);
                array.push_back(number);
                candidate_set.insert(number);
                ptr = strtok(NULL, "\t");      // 다음 문자열을 잘라서 포인터를 반환
            }
            
            
            transaction.push_back(array);
            array.clear();
        }
    }
    
    
    //상대적 지지도를 통해서 절대적 지지도를 구해냄
    minSupport = ceil(((double)size_transaction / 100) * relative_support);
    //cout << "min support : " << size_transaction << " " <<  minSupport << endl;
    
    int support[candidate_set.size()];
    memset(support,0,candidate_set.size()*sizeof(int));
    
    
    for(int i=0; i<transaction.size(); i++) {
        for(int j=0; j<transaction[i].size(); j++) {
            support[transaction[i][j]]++;
        }
    }
    
    //L1까지 완료
    vector<vector<Itemset> > L;    // L(i) : frequent itemset of size i
    vector<Itemset> Lk;
    set<int> Lk_temp;
    
    int *my_set = new int[candidate_set.size()],q=0;
    for(int i=0; i<candidate_set.size(); i++) {
        
        if(minSupport<=support[i]){
            Lk_temp.insert(i);
            my_set[q++] = i;
            Itemset itemset(Lk_temp,support[i]);
            Lk.push_back(itemset);
            Lk_temp.clear();
        }
    }
    L.push_back(Lk);
    Lk_temp.clear(); Lk.clear();
    
    //L2까지 완료
    for( int first = 0; first < q; ++first ) {
        for( int second = first+1; second < q; ++second ) {
            if( first != second ) {
                Lk_temp.insert(my_set[first]);
                Lk_temp.insert(my_set[second]);
                
                if(getSupport(transaction,&Lk_temp)>=minSupport) {
                    Itemset itemset(Lk_temp,getSupport(transaction,&Lk_temp));
                    Lk.push_back(itemset);
                }
                Lk_temp.clear();
            }
        }
    }
    L.push_back(Lk);
    Lk_temp.clear();
    Lk.clear();
    
    int res=9999,i=1;
    while(1) {
        
        res = make_Candidate_sets(transaction,&L, i);
        if(res==1 || res==0) {
            break;
        }
        i++;
    }
    //PrintAllSet(&L);
    input.close();
    ofstream output(output_name,ios_base::out | ios_base::binary | ios_base::trunc);
    
    for(int i=0; i< L.size(); i++) {
        DivideSubset(transaction,&L, i);
    }
    return 0;
}
