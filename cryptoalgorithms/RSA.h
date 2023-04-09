#pragma once
#include <string>
#include "IEncryptor.h"
#include <fstream>

class RSA : IEncryptor{
public:
    std::string encrypt(std::string key, std::string msg) override;
    
   std::string decrypt(std::string key, std::string msg) override;    
};