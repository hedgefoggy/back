#pragma once

#include <string>
#include <vector>
#include "User.h"

class UserManager
{
private:
    std::vector<User> users;
    
public:
    void add_user(int id, const std::string& name, int age);
    
    User* find_user(int id);

    bool delete_user(int id);

    bool user_exists(int id) const;

    int get_user_count() const;

    void print_users() const;

    bool add_user_if_not_exists(int id, const std::string& name, int age);

    bool update_user(int id, const std::string& name, int age);
};