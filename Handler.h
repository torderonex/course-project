#pragma once
#include "crow.h"

class Handler
{
public:
	void crc32(const crow::request& req, crow::response& res);
	void md5(const crow::request& req, crow::response& res);
	
	void caesarEncrypt(const crow::request& req, crow::response& res);
	void caesarDecrypt(const crow::request& req, crow::response& res);

	void vigenereEncrypt(const crow::request& req, crow::response& res);
	void vigenereDecrypt(const crow::request& req, crow::response& res);

};

