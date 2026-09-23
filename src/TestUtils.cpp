#include <iostream>

#include "TestUtils.h"

bool check(bool condition, const std::string& test_name)
{
    if (condition)
    {
        std::cout << test_name << " PASSED\n";
        return true;
    }
    else
    {
        std::cout << test_name << " FAILED\n";
        return false;
    }
}