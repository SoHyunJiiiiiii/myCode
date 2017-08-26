//
//  main.cpp
//  TV크기
//
//  Created by 지소현 on 2017. 8. 26..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <iostream>
#include <math.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int dialog,height,width;

    scanf("%d %d %d",&dialog,&height,&width);
    
    double x  = dialog / sqrt((pow(height,2)+pow(width, 2)));
    
    printf("%d %d",int(height*x),int(width*x));
    return 0;
}
