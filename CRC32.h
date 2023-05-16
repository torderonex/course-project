#include "IHasher.h"

class CRC32 : IHasher {
private:
    unsigned int crc = 0xFFFFFFFF;
public:
    std::string hash(std::string msg)  override;
};