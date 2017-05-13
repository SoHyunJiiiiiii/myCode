#include "calc.hpp"
#include <cmath>
std::string Calc::getType() {
    return type;
}

void Calc::setType(std::string str) {
    Calc::type = str;
}

int BasicCalc::calculate(std::string cmd, int x, int y) {
    if(cmd=="add"){
        return x + y;
    }
    else if(cmd=="sub"){
        return x - y;
    }
    else if(cmd=="mul"){
        return x * y;
    }
    else if(cmd=="div"){
        if(y==0)
            return -1;
        return x / y;
    }
    return -1;
};

int ScientificCalc::calculate(std::string cmd, int x, int y) {
    if(cmd=="pow"){
        return pow(x , y);
    }
    else{
        return BasicCalc::calculate(cmd, x, y);
    }
}

int ProgrammerCalc::calculate(std::string cmd, int x, int y){
    if(cmd=="lshift"){
        return x << y;
    }
    else if(cmd == "rshift"){
        return x >> y;
    }
    else
        return BasicCalc::calculate(cmd, x, y);
}
