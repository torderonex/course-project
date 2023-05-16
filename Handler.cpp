#include "Handler.h"
#include "CRC32.h"
#include "MD5.h"
#include "Caesar.h"
#include "Vigenere.h"
#include <regex>

bool contains_only_digits(const std::string& str) {
    std::regex pattern("\\d+");
    return std::regex_match(str, pattern);
}

void Handler::md5(const crow::request& req, crow::response& res) {
    auto json = crow::json::load(req.body);
    std::string msg = "";
    if (json && json.has("msg")) {
        msg = json["msg"].s();
    }
    else {
        res.write("Invalid body request");
        res.code = 400;
        res.end();

    }
    MD5 md5;
    res.write(md5.hash(msg));
    res.end();
}

void Handler::crc32(const crow::request& req, crow::response& res) {
    auto json = crow::json::load(req.body);
    std::string msg = "";
    if (json && json.has("msg")) {
        msg = json["msg"].s();
    }
    else {
        res.write("Invalid body request");
        res.code = 400;
        res.end();
    }
    CRC32 crc32;
    res.write(crc32.hash(msg));
    res.end();
}

void Handler::caesarEncrypt(const crow::request& req, crow::response& res) {
    auto json = crow::json::load(req.body);
    std::string msg;
    std::string key;
    if (json && json.has("msg") && json.has("key")) {
        msg = json["msg"].s();
        key = json["key"].s();
    }
    else {
        res.write("Invalid body request");
        res.code = 400;
        res.end();
    }
    if (!contains_only_digits(key))
    {
        res.code = 400;
        res.write("Incorrect key");
        res.end();
    }
    Caesar caesar;
    res.write(caesar.encrypt(key, msg));
    res.end();
}

void Handler::caesarDecrypt(const crow::request& req, crow::response& res) {
    auto json = crow::json::load(req.body);
    std::string msg;
    std::string key;
    if (json && json.has("msg") && json.has("key")) {
        msg = json["msg"].s();
        key = json["key"].s();
    }
    else {
        res.write("Invalid body request");
        res.code = 400;
        res.end();
    }
    Caesar caesar;
    if (! contains_only_digits(key))
    {
        res.code = 400;
        res.write("Incorreñt key");
        res.end();
    }
    res.write(caesar.decrypt(key, msg));
    res.end();
}

void Handler::vigenereEncrypt(const crow::request& req, crow::response& res) {
    auto json = crow::json::load(req.body);
    std::string msg;
    std::string key;
    if (json && json.has("msg") && json.has("key")) {
        msg = json["msg"].s();
        key = json["key"].s();
    }
    else {
        res.write("Invalid body request");
        res.code = 400;
        res.end();
    }
    Vigenere vigenre;
    res.write(vigenre.encrypt(key, msg));
    res.end();
}

void Handler::vigenereDecrypt(const crow::request& req, crow::response& res) {
    auto json = crow::json::load(req.body);
    std::string msg;
    std::string key;
    if (json && json.has("msg") && json.has("key")) {
        msg = json["msg"].s();
        key = json["key"].s();
    }
    else {
        res.write("Invalid body request");
        res.code = 400;
        res.end();
    }
    Vigenere vigenere;
    res.write(vigenere.decrypt(key, msg));
    res.end();
}