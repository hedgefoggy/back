#pragma once

#include <vector>
#include "IUserRepository.h"
#include "User.h"

class InMemoryUserRepository : public IUserRepository
{
private:
    std::vector<User> users;

public:
    bool add(int id, const std::string& name, int age) override;
    std::optional<User> find(int id) const override;
    bool remove(int id) override;
    bool update(int id, const std::string& name, int age) override;
    std::size_t count() const override;
    bool exists(int id) const override;
};