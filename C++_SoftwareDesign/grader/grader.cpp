//
//  grader.cpp
//  8_3
//
//  Created by 지소현 on 2016. 11. 21..
//  Copyright © 2016년 지소현. All rights reserved.
//

#include "grader.hpp"


string SubjectPassFail::GetGrade(int score) const
{
    if(score >= pass_score_){
        return "P";
    }
    return "F";
}

// 100 >= "A" >= cutA > "B" >= cutB > "C" >= cutC > "D" >= cutD > "F".
string SubjectGrade::GetGrade(int score) const
{
    if(score <= 100 && score >= cutA_){
        return "A";
    }
    else if(score < cutA_ && score >= cutB_){
        return "B";
    }
    else if(score < cutB_ && score >= cutC_){
        return "C";
    }
    else if(score < cutC_ && score >= cutD_){
        return "D";
    }
    else{ //if(score < cutD_){
        return "F";
    }
}
