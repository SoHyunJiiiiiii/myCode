#ifndef __CALC_HPP__
#define __CALC_HPP__

#include <string>
#include <iostream>
class Calc {
public:
	Calc(std::string type = ""): type(type) {};
	virtual ~Calc() {};
    virtual int calculate(std::string cmd, int x, int y)=0;
    std::string getType();
    void setType(std::string str);
protected:
	std::string type;
};

class BasicCalc : public Calc
{
public:
    BasicCalc() : Calc() {}
    BasicCalc(std::string type) : Calc(type) {};
    virtual int calculate(std::string cmd, int x, int y);
};

class ScientificCalc : public BasicCalc
{
public:
    ScientificCalc() : BasicCalc() {}
    ScientificCalc(std::string type) : BasicCalc(type) {};
    virtual ~ScientificCalc() {};
    virtual int calculate(std::string cmd, int x, int y);
};

class ProgrammerCalc : public BasicCalc
{
public:
    ProgrammerCalc() : BasicCalc() {}
    ProgrammerCalc(std::string type) : BasicCalc(type){}
    virtual ~ProgrammerCalc() {};
    virtual int calculate(std::string cmd, int x, int y);
};

#endif
