#pragma once

#include <cstdint>
#include <string>
#include <functional>
#include "response.h"

using namespace std;

template<class T> //T is the object the automation is running on (such as the tile or voxel info manager), R is the return type, if any
class Automation {
    T *obj;
    function<bool(T*)> func;

    public:
    Automation(T* o, function<bool(T*)> f);
    bool run();
};