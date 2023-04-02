#pragma once
#include <string>

class IHasher{
public:
    virtual std::string hash(std::string msg) = 0;
};