#include "UserService.h"

bool UserService::register_user(
    int id,
    const std::string& name,
    int age
)
{
    return manager.add_user_if_not_exists(id, name, age);
}

User* UserService::find_user(int id)
{
    return manager.find_user(id);
}

bool UserService::delete_user(int id)
{
    return manager.delete_user(id);
}

int UserService::get_user_count() const
{
    return manager.get_user_count();
}

bool UserService::update_user(int id, const std::string& name, int age)
{
    return manager.update_user(id, name, age);
}
