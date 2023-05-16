#pragma once
#include <string>

class IEncryptor {
public:
    virtual std::string encrypt(std::string key, std::string msg) = 0;
    virtual std::string decrypt(std::string key, std::string msg) = 0;
};