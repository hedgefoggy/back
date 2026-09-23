#include <iostream>
#include "User.h"

User::User(int id, const std::string& name, int age)
    : id(id),
      name(name),
      age(age)
{
}

int User::get_id() const
{
    return id;
}

const std::string& User::get_name() const
{
    return name;
}

int User::get_age() const
{
    return age;
}

void User::set_name(const std::string& name)
{
    this->name = name;
}

void User::set_age(int age)
{
    this->age = age;
}

void User::say_hello() const
{
    std::cout << "Hello, I am " << name << "\n";
}