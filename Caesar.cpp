#include "Caesar.h"
#include <string>
#include <iostream>
#include <codecvt>


std::string Caesar::encrypt(std::string key, std::string msg) {
    int k = std::stoi(key);
    std::wstring m(msg.begin(),msg.end());
    std::wstring result;
    for (size_t i = 0; i < m.length(); i++)
    {
        char letter = std::tolower(m[i]);
        if (latinAlph.find(letter) == std::string::npos && cyryllicAlph.find(letter) == std::string::npos)
        {
            result += m[i];
        }
        else if (latinAlph.find(letter) != std::string::npos) {
            int index = (latinAlph.find(letter) + k) % latinAlph.length();
            result += latinAlph[index];
        }
        else if (cyryllicAlph.find(letter) != std::string::npos) {
            int index = (cyryllicAlph.find(letter) + k) % cyryllicAlph.length();
            result += cyryllicAlph[index];
        }
    }
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;  
    return conv.to_bytes(result);
}

std::string Caesar::decrypt(std::string key, std::string msg) {
    int k = std::stoi(key);
    std::string result;
    for (size_t i = 0; i < msg.length(); i++)
    {
        char letter = std::tolower(msg[i]);
        if (latinAlph.find(letter) == std::string::npos && cyryllicAlph.find(letter) == std::string::npos)
        {
            result += msg[i];
        }
        else if (latinAlph.find(letter) != std::string::npos) {
            int index = (latinAlph.find(letter) - k + latinAlph.length()) % latinAlph.length();
            result += latinAlph[index];
        }
        else if (cyryllicAlph.find(letter) != std::string::npos) {
            int index = (cyryllicAlph.find(letter) - k + cyryllicAlph.length()) % cyryllicAlph.length();
            result += cyryllicAlph[index];
        }
    }   
    return result;
}