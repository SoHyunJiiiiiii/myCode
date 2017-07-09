//
//  main.cpp
//  회의실배정
//
//  Created by 지소현 on 2017. 7. 9..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
struct timeTable {
    int start,finish;
};

int compareTime (const timeTable& a,const timeTable& b) {
    if(a.finish == b.finish) {
        return a.start < b.start;
    }
    return a.finish < b.finish;
}

int main(int argc, const char * argv[]) {
    
    int num,count=0;
    
    
    cin >> num;
    if(num <1 || num >100000) {
        return 0;
    }

    int start,finish;
    timeTable meeting;
    vector<timeTable> result;
    for(int i=0; i<num; i++) {
    
        cin >> start >> finish;
        meeting.start = start;
        meeting.finish = finish;
        result.push_back(meeting);
        
        if(start <0 || start > pow(2,32)-1 || finish <0 || finish > pow(2,32)-1)
            return 0;
        
    }
    
    sort(result.begin(),result.end(),compareTime);
    
    int last_finish = 0;
    for(int i=0; i<num; i++) {
        if(result[i].start >= last_finish) {
            last_finish = result[i].finish;
            count++;
        }
    }
    
    
    cout << count << endl;
    return 0;
}
