#pragma once

#include <string>
#include "UserManager.h"

class UserService
{
private:
    UserManager manager;

public:
    bool register_user(int id, const std::string& name, int age);

    User* find_user(int id);

    bool delete_user(int id);

    int get_user_count() const;

    bool update_user(int id, const std::string& name, int age);
    
};