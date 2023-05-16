#pragma once
#include <string>
#include "IEncryptor.h"

class Caesar : IEncryptor {
private:
    const std::string cyryllicAlph = "אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";
    const std::string latinAlph = "abcdefghijklmnopqrstuvwxyz";
public:
    std::string encrypt(std::string key, std::string msg) override;
    std::string decrypt(std::string key, std::string msg)  override;
};