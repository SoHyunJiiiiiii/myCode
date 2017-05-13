#ifndef __POLY_DIFF_HPP__
#define __POLY_DIFF_HPP__

#include <vector>
#include <iostream>
#define MINUS -999
#define PLUS 999
using namespace std;
class Variable {
public:
    Variable(int degree,int constant,int plus_state);
    int GetDiff(int x);
    int GetPlusState();
    
private:
    int degree_;
    int constant_;
    int plus_state_;
};

class PolyDiff {
public:
    void SetVariables(string data);
    void GetDiff(int x);
    
private:
    vector<Variable> variables_;
};

#endif
