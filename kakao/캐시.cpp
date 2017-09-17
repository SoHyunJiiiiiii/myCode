//
//  main.cpp
//  캐시
//
//  Created by 지소현 on 2017. 9. 16..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int Miss = cacheSize, Hit = 0;
    vector<string> cache;
    bool flag = false;
    
    if(cacheSize==0) {
        return cities.size() * 5;
    }
    
    for(int i=0; i<cacheSize; i++) {
        cache.push_back(cities[i]);
    }
    
    for(int i=cacheSize; i<cities.size(); i++) {
        
        
        
        for(int j=0; j<cache.size(); j++) {
            
            if(cache[j].length() == cities[i].length()) {
                string str1=cities[i];
                for (int k=0; k<str1.size(); k++)
                {
                    str1[k]=toupper(str1[k]); //소문자를 대문자로 교환.
                }
                
                string str2=cache[j];
                for (int k=0; k<str2.size(); k++)
                {
                    str2[k]=toupper(str2[k]); //소문자를 대문자로 교환.
                }
                
                if(str1==str2) {
                    cache.erase(cache.begin()+j);
                    flag = true; Hit++;
                }
            }
        }
        
        //못찾았다면?
        if(!flag) {
            cache.erase(cache.begin());
            Miss++;
        }
        cache.push_back(cities[i]);
        flag=false;
        
    }
    answer += Miss*5 + Hit;
    return answer;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int cacheSize,n;
    cin >> cacheSize >> n ;

    string city;
    vector<string> cities;
    for(int i=0; i<n; i++) {
        cin >> city;
        cities.push_back(city);
    }
    cout << solution(cacheSize, cities) << endl;
    return 0;
}
