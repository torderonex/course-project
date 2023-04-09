#include "RSA.h"
#include <string>
#include <fstream>
#include <cmath>
#include <vector>

int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}

std::vector<int> to_bytes(std::string msg){
    std::vector<int> res;    
    for (size_t i = 0; i < msg.length(); i++)
    {
        res.push_back((int)msg[i]);
    }
    
    return res;
}

std::string to_str(std::vector<int> num){
    std::string res;
    for (size_t i = 0; i < num.size(); i++)
    {
        res += num[i];
    }
    return res;
}

/*
std::string RSA::encrypt(std::string key,std::string msg){
    double p = 3;
    double q = 7;
    double n=p*q;
    double count;
    double totient = (p-1)*(q-1);
 
    double e=2;
 
    while(e<totient){
    count = gcd(e,totient);
    if(count==1)
        break;
    else
        e++;
    }
 
    std::vector<int> msgBytes = to_bytes(msg);
    for (size_t i = 0; i < msgBytes.size(); i++)
    {
        msgBytes[i] = pow(msgBytes[i], e);
        msgBytes[i] = fmod(msgBytes[i],n);
    }
    
    return to_str(msgBytes);
}
*/

std::string RSA::encrypt(std::string key, std::string msg){
    const std::string& ciphertext = msg;
    const std::string& private_key = key;
    const uint8_t* ptr = reinterpret_cast<const uint8_t*>(private_key.c_str());
    uint32_t n_size = *(uint32_t*)ptr;
    ptr += sizeof(uint32_t);
    std::vector<uint8_t> n(n_size);
    std::copy(ptr, ptr + n_size, n.begin());
    ptr += n_size;
    uint32_t d_size = *(uint32_t*)ptr;
    ptr += sizeof(uint32_t);
    std::vector<uint8_t> d(d_size);
    std::copy(ptr, ptr + d_size, d.begin());

    // Convert the ciphertext to a vector of bytes
    std::vector<uint8_t> ciphertext_bytes(ciphertext.begin(), ciphertext.end());

    // Compute the length of the plaintext and allocate a buffer
    uint32_t key_size = n.size();
    uint32_t block_size = key_size - 1;
    uint32_t num_blocks = (ciphertext_bytes.size() + block_size - 1) / block_size;
    std::vector<uint8_t> plaintext_bytes(num_blocks * key_size);

    // Decrypt each block of the ciphertext
    for (uint32_t i = 0; i < num_blocks; i++) {
        // Extract the next block of ciphertext
        std::vector<uint8_t> block(block_size);
        uint32_t block_start = i * block_size;
        uint32_t block_end = block_start + block_size;
        if (block_end > ciphertext_bytes.size()) {
            block_end = ciphertext_bytes.size();
        }
        std::copy(ciphertext_bytes.begin() + block_start, ciphertext_bytes.begin() + block_end, block.begin());

        // Decrypt the block using the private key
        uint64_t c = 0;
        for (uint32_t j = 0; j < block_size; j++) {
            c <<= 8;
            if (j < block_size - block_end + block_start) {
                continue;
            }
            c |= block[j];
        }
        uint64_t m = 1;
        for (uint32_t j = 0; j < d.size(); j++) {
            uint8_t b = d[j];
            for (uint32_t k = 0; k < 8; k++) {
                m = (m * m) % *(uint64_t*)n.data();
                if (b & 0x80) {
                    m = (m * c) % *(uint64_t*)n.data();
                }
                b <<= 1;
            }
        }

        // Write the decrypted block to the plaintext buffer
        for (uint32_t j = 0; j < key_size; j++) {
            plaintext_bytes[i * key_size + j] = (m >> (8 * (key_size - 1 - j))) & 0xFF;
        }
    }

    // Convert the plaintext bytes to a string and return it
    std::string plaintext(plaintext_bytes.begin(), plaintext_bytes.end());
    return plaintext;
}

std::string RSA::decrypt(std::string key, std::string msg){
    return " ";
}

