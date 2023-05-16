#include "CRC32.h"
#include <string>

std::string CRC32::hash(std::string data) {
    const unsigned char* buffer = reinterpret_cast<const unsigned char*>(data.data());
    unsigned int len = data.length();

    while (len--) {
        crc ^= *buffer++;
        for (int bit = 0; bit < 8; bit++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            }
            else {
                crc = (crc >> 1);
            }
        }
    }
    std::string hash = std::to_string(crc ^ 0xFFFFFFFF);
    return hash;
}