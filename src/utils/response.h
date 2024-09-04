#pragma once

#include <cstdint>
#include <string>

using namespace std;

template<class T>
class Response {
    T data;
    int status;

    public:
    Response(T d, int stat): data(d), status(stat) {}
    T getData() {return data;}
    int status() {return status;}
};