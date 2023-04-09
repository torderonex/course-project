#pragma once
#include <string>
#include "IEncryptor.h"
#include <fstream>

class RSA {
public:
    std::string encrypt(std::string key, std::string msg); //override;
   // std::ofstream encryptFile(std::string key, std::ifstream msg) override;
    
   std::string decrypt(std::string key, std::string msg) ;  //override;    
};