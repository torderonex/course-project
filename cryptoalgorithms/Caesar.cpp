#include "Caesar.h"
#include <string>
#include <fstream>

std::string Caesar::encrypt(std::string key,std::string msg){
    int k = std::stoi(key);
    std::string result;
    for (size_t i = 0; i < msg.length(); i++)
    {
        result += msg[i] + k;
    }
    return result;
}

std::string Caesar::decrypt(std::string key, std::string msg){
    int k = std::stoi(key);
    std::string result;
    for (size_t i = 0; i < msg.length(); i++)
    {
        result += msg[i] - k;
    }
    return result;
}