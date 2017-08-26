//
//  main.cpp
//  네번째수
//
//  Created by 지소현 on 2017. 8. 26..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[5];
    for(int i=0; i<3; i++) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+3);
    
    if(arr[1]-arr[0] > arr[2]-arr[1]) {
        printf("%d", arr[0]+ (arr[2]-arr[1]));
    } else if(arr[1]-arr[0] < arr[2]-arr[1]) {
        printf("%d", arr[1]+ (arr[1]-arr[0]));
    }  else {
        printf("%d", arr[2]+ (arr[1]-arr[0]));
    }

    return 0;
}
