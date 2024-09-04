#pragma once

#include <cstdint>
#include <string>

using namespace std;

class Param {
    protected:
    Param(uint16_t h, string l, bool f);
    uint16_t hash;
    string label;
    bool floating;

    public:
    virtual ~Param() = default;
    void toString();
    bool match(Param &p2); //this matches only the hash/label, not the value
    string getLabel() const;
    uint16_t getHash();
};

class IntParam: public Param {
    int64_t value;

    public:
    IntParam(uint16_t h, string l, int64_t v);
    ~IntParam();
    int64_t getValue() const;
    void setValue(int64_t v);
};

class FloatParam: public Param {
    uint16_t hash;
    string label;
    double value; //how did they only think of fixed width floats in C++23??

    public:
    FloatParam(uint16_t h, string l, uint64_t v);
    ~FloatParam();

    double getValue() const;
    void setValue(double v);
};