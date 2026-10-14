#include <iostream>

#include "crow.h"
#include "InMemoryUserRepository.h"
#include "UserService.h"

int main()
{
    InMemoryUserRepository repo;   // создан первым
    UserService service(repo);     // создан вторым
    // при выходе из области видимости объекты уничтожаются в ОБРАТНОМ порядке:
    // сначала service, потом repo. Безопасно.

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
