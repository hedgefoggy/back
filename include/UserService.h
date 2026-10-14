#pragma once

#include <string>
#include <cstddef> // size_t
#include <optional>

#include "IUserRepository.h"

class UserService
{
private:
    IUserRepository& repository;

public:
    explicit UserService(IUserRepository& repository);

    bool register_user(int id, const std::string& name, int age);

    std::optional<User> find(int id) const;

    bool remove(int id);

    std::size_t count() const;

    bool update(int id, const std::string& name, int age);
    
};