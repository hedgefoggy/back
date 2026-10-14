#include "InMemoryUserRepository.h"

bool InMemoryUserRepository::add(int id, const std::string& name, int age)
{
    if (exists(id))
        {
            return false;            
        }
    users.push_back(User(id, name, age));
    return true;
}

std::optional<User> InMemoryUserRepository::find(int id) const
{
    for (const auto& user : users)
    {
        if (user.get_id() == id)
        {
            return user;
        }
    }
    return std::nullopt;
}

bool InMemoryUserRepository::remove(int id)
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

bool InMemoryUserRepository::update(int id, const std::string& name, int age)
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

std::size_t InMemoryUserRepository::count() const
{
    return users.size(); // Если int: return static_cast<int>(users.size());
}

bool InMemoryUserRepository::exists(int id) const
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