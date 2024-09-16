#pragma once

#include <cstdint>
#include <string>

using namespace std;

class Param {
    protected:
    Param(string l, bool f);
    string label;
    bool floating;

    public:
    virtual ~Param() = default;
    void toString();
    bool match(Param &p2); //this matches only the label/type, not the value
    string getLabel() const;
    bool isFloating();
};

class IntParam: public Param {
    int64_t value;

    public:
    IntParam(string l, int64_t v);
    ~IntParam();
    int64_t getValue() const;
    void setValue(int64_t v);
};

class FloatParam: public Param {
    double value; //how did they only think of fixed width floats in C++23??

    public:
    FloatParam(string l, uint64_t v);
    ~FloatParam();

    double getValue() const;
    void setValue(double v);
};