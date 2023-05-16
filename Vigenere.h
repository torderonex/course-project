#pragma once
#include "IEncryptor.h"
class Vigenere : IEncryptor
{
public:
    std::string encrypt(std::string key, std::string msg) override;
    std::string decrypt(std::string key, std::string msg)  override;
};

