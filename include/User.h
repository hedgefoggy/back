#pragma once

#include <string>

class User
{
private :
    int id;
    std::string name;
    int age;

public: 
    User(int id, const std::string& name, int age);

    int get_id() const;
    const std::string& get_name() const;
    int get_age() const;

    void set_name(const std::string& name);
    void set_age(int age);

    void say_hello() const;
};