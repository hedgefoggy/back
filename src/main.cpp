#include <iostream>

#include "crow.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]()
    {
        return "Hello Backend!";
    });

    std::cout << "Server started on port 18080\n";

    app.port(18080).multithreaded().run();

    return 0;
}
