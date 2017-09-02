//
//  main.cpp
//  1316_그룹단어체커
//
//  Created by 지소현 on 2017. 9. 2..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
    // insert code here...
    int N;
    int word=0;
    int count[30];
    scanf("%d",&N);
    while(N--) {
        bool flag =true;
        memset(count, 0, sizeof(count));
        
        string str;
        cin >> str;
//        strcpy(cstr,str.c_str());
        
        
        count[str[0]-'a']++;
        for(int i=1; i<str.size(); i++) {
            if(count[str[i]-'a']!=0 && str[i]!=str[i-1]){
                flag = false;
                break;
            }
            count[str[i]-'a']++;
        }

        if(flag)
            word++;
        
    }
    
    printf("%d",word);
    return 0;
}
