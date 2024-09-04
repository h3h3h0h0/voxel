#pragma once

#include <cstdint>
#include <string>

using namespace std;

class Tag {
    uint16_t hash;
    string label;
    string value;

    public:
    Tag(uint16_t h, string l);
    Tag(uint16_t h, string l, string v);
    ~Tag();

    void toString();
    string getLabel() const;
    string getValue() const;
    void setValue(string s) const;
    uint16_t getUID();
    bool match(const Tag &t2); //this matches only the hash/label, not the value
    bool operator==(const Tag &t2); //these operators match the value as well
    bool operator!=(const Tag &t2) {return !(*this == t2);}
};