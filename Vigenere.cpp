#include "Vigenere.h"
#include <string>

std::string Vigenere::encrypt(std::string key, std::string msg) {
    std::string result;
    int k = 0;
    for (int i = 0; i < msg.length(); i++) {
        char c = msg[i];
        if (isalpha(c)) {
            int shift = key[k++ % key.length()] - 'a';
            c = tolower(c);
            c = 'a' + (c - 'a' + shift) % 26;
            if (isupper(msg[i])) {
                c = toupper(c);
            }

        }
        result += c;
    }
    return result;
}

std::string Vigenere::decrypt(std::string key, std::string msg) {
    std::string result;
    int k = 0;
    for (int i = 0; i < msg.length(); i++) {
        char c = msg[i];
        if (isalpha(c)) {
            int shift = key[k++ % key.length()] - 'a';
            c = tolower(c);
            c = 'a' + (c - 'a' - shift + 26) % 26;
            if (isupper(msg[i])) {
                c = toupper(c);
            }
        }
        result += c;
    }
    return result;
}
