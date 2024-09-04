#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <unordered_map>
#include "tag.h"
#include "parameter.h"

using namespace std;

enum infotype {
    TAG,
    INTPARAM,
    FLOATPARAM
};

class InfoManager {
    unordered_map<uint16_t, vector<Tag>> tags;
    unordered_map<uint16_t, vector<Param>> params; 
    hash<string>& hasher; //this should be central, not per instance, as the hashes should be consistent

    public:
    InfoManager(hash<string> &h);
    ~InfoManager();
    bool insertTag(string label, string value="");
    bool removeTag(string label);
    string getTagValue(string label);
    bool insertIntParam(string label, int64_t value);
    bool insertFloatParam(string label, double value);
    bool removeParam(string label);
    int64_t getIntValue(string label);
    double getFloatValue(string label);
    infotype getType(string label); //this gets the first one it sees (ideally you would want to keep it organized)
    bool hasTag(string label);
    bool hasParam(string label);
};