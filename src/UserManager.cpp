#include <iostream>
#include "UserManager.h"

void UserManager::add_user(int id, const std::string& name, int age)
{
    users.push_back(User(id, name, age));
}

User* UserManager::find_user(int id)
{
    for (auto& user : users)
    {
        if (user.get_id() == id)
        {
            return &user;
        }
    }
    return nullptr;
}

bool UserManager::delete_user(int id)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if(it->get_id() == id)
        {
            users.erase(it);
            return true;
        }
    }
    return false;
}

bool UserManager::user_exists(int id) const
{
    for (const auto& user : users)
    {
        if (user.get_id() == id)
        {
            return true;
        }
    }
    return false;
}

int UserManager::get_user_count() const
{
    return users.size();
}

void UserManager::print_users() const
{
    for (const auto& user : users)
    {
        std::cout   << user.get_id()
                    << " "
                    << user.get_name()
                    << " "
                    << user.get_age()
                    << "\n";
    }
}

bool UserManager::add_user_if_not_exists(int id, const std::string& name, int age)
{
    for (const auto& user : users)
    {
        if (user.get_id() == id)
        {
            return false;
        }          
    }
    users.push_back(User(id, name, age));
    return true;  
}

bool UserManager::update_user(int id, const std::string& name, int age)
{
    for (auto& user : users)
    {
        if (user.get_id() == id)
        {
            user.set_name(name);
            user.set_age(age);
            return true;
        }
    }
    return false;
}