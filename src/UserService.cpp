#include "UserService.h"

UserService::UserService(IUserRepository& repository)
    : repository(repository)
{
}

bool UserService::register_user(
    int id,
    const std::string& name,
    int age
)
{
    return repository.add(id, name, age);
}

std::optional<User> UserService::find(int id) const
{
    return repository.find(id);
}

bool UserService::remove(int id)
{
    return repository.remove(id);
}

std::size_t UserService::count() const
{
    return repository.count();
}

bool UserService::update(int id, const std::string& name, int age)
{
    return repository.update(id, name, age);
}
