//
//  grader.cpp
//  8_3
//
//  Created by 지소현 on 2016. 11. 21..
//  Copyright © 2016년 지소현. All rights reserved.
//``
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "grader.hpp"
vector<pair<string, double> > student_grades;
inline bool CompareStudent(const pair<string, double>& a,const pair<string, double>& b){
    return a.second > b.second;
}



double GetNumberGrade(const string& str){//1,const string& str2,const string& str3,const string& str4) {
    //(A=4.0, B=3.0, C=2.0, D=1.0, F=0.0, P=4.0)
    double grade;
    
    if(str=="P"){
        grade=4.0;
    }
    else if(str=="A"){
        grade=4.0;
    }
    else if(str=="B"){
        grade=3.0;
    }
    else if(str=="C"){
        grade=2.0;
    }
    else if(str=="D"){
        grade=1.0;
    }
    else{
        grade=0.0;
    }
    return grade;
}


int main() {
	SubjectPassFail subject1("Seminar", 1, 70);
	SubjectGrade subject2("C++", 6, 90, 80, 70, 60);
	SubjectGrade subject3("Calculus", 3, 80, 60, 40, 20);
	SubjectGrade subject4("Statistics", 2, 80, 70, 60, 50);
    
	const int total_credit = subject1.credit() + subject2.credit()
		+ subject3.credit() + subject4.credit();
	string cmd;
    string student;
    int grade1,grade2,grade3,grade4;
    
	while (cmd != "quit") {
        double sum=0,res=0;
		cin >> cmd;
		if (cmd == "eval") {
            cin >> student >> grade1 >> grade2 >> grade3 >> grade4;
            cout << student <<" " <<subject1.GetGrade(grade1) << " " << subject2.GetGrade(grade2) << " " << subject3.GetGrade(grade3) << " " << subject4.GetGrade(grade4) << endl;
            
            sum = (GetNumberGrade(subject1.GetGrade(grade1)) * subject1.credit()
                   + GetNumberGrade(subject2.GetGrade(grade2)) * subject2.credit()
                   + GetNumberGrade(subject3.GetGrade(grade3)) * subject3.credit()
                   + GetNumberGrade(subject4.GetGrade(grade4)) * subject4.credit() );
            res = (sum / total_credit);
            student_grades.push_back(make_pair(student, res));
		}
    }
	sort(student_grades.begin(), student_grades.end(), CompareStudent);
    vector<pair<string,double> >::iterator it;
    for(it=student_grades.begin(); it!= student_grades.end(); it++){
        cout << it->first << " " ;
        cout.precision(3);
        cout << it->second << endl;
    }

	return 0;
}
