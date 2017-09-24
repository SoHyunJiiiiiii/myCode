//
//  main.cpp
//  암복호화
//
//  Created by 지소현 on 2017. 9. 23..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    string menu,secretword,word,result;
    int rotate = 0;
    cin >> menu >> secretword >> rotate >> word;

    
    if(menu=="encrypt") {
        string temp;
        //원본문자 + 비밀키 문자 = 변환키
        for(int i=0; i<secretword.size(); i++) {
        
            int res =(int)(secretword[i] -'a') + (int)(word[i] -'a') ; //+'a';
            res %= 26;  //z=25니까
            char ch = res+'a';
            temp += ch;
        }

        for(int j=0, i=(int)(temp.size())+rotate; j<temp.size(); j++,i++) {
                result += temp[i%temp.size()];
        }
    
    } else {
        string temp;
        //rotate먼저 해줘야함 (반대순서로..)
        for(int j=0,i=(int)(word.size())-rotate; j<word.size(); j++,i++) {
            temp += word[i%word.size()];
        }
    
        //원본문자 + 비밀키 문자 = 변환키
        for(int i=0; i<temp.size(); i++) {
            
            int res = (int)(temp[i] -'a') - (int)(secretword[i] -'a');
            if(res<0)   res += 26;

            char ch = res +'a';
            result += ch;
        }
    }
    cout << result <<endl;
    return 0;
}
