#define CROW_ENABLE_SSL

#include "crow.h"
#include "Handler.h"
int main()
{

    crow::SimpleApp app;
    Handler handler;
    CROW_ROUTE(app, "/md5").methods("POST"_method)
        ([&handler](const crow::request& req, crow::response& res) {
        handler.md5(req, res);
            });

    CROW_ROUTE(app, "/crc32").methods("POST"_method)
        ([&handler](const crow::request& req, crow::response& res) {
        handler.crc32(req, res);
            });

    CROW_ROUTE(app,"/caesar/encrypt").methods("POST"_method)
        ([&handler](const crow::request& req, crow::response& res) {
        handler.caesarEncrypt(req, res);
            });

    CROW_ROUTE(app, "/caesar/decrypt").methods("POST"_method)
        ([&handler](const crow::request& req, crow::response& res) {
        handler.caesarDecrypt(req, res);
            });

    CROW_ROUTE(app, "/vigenere/encrypt").methods("POST"_method)
        ([&handler](const crow::request& req, crow::response& res) {
        handler.vigenereEncrypt(req, res);
            });

    CROW_ROUTE(app, "/vigenere/decrypt").methods("POST"_method)
        ([&handler](const crow::request& req, crow::response& res) {
        handler.vigenereDecrypt(req, res);
            });

    app.ssl_file("server.crt", "server.key").port(18080).run();
}