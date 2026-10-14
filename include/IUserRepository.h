#pragma once

#include <string>
#include <cstddef> // size_t
#include <optional>

#include "User.h"


class IUserRepository
{
public:
    virtual ~IUserRepository() = default;

    virtual bool add(int id, const std::string& name, int age) = 0;

    // Возвращает копию найденного пользователя или пустой optional, если такого нет.
    virtual std::optional<User> find(int id) const = 0;

    virtual bool remove(int id) = 0;

    virtual bool update(int id, const std::string& name, int age) = 0;

    virtual std::size_t count() const = 0;

    virtual bool exists(int id) const = 0;
};