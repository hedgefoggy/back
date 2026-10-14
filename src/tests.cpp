#include <iostream>

#include "UserService.h"
#include "TestUtils.h"
#include "InMemoryUserRepository.h"

bool run_user_service_tests()
{
    InMemoryUserRepository repo;
    UserService service(repo);

    bool all_tests_passed = true;

    all_tests_passed = 
        check(
            service.register_user(1, "Alex", 25), 
            "REGISTER NEW USER"
        ) && all_tests_passed;

    all_tests_passed = 
        check(
            service.register_user(1, "Bob", 30) == false,
            "REJECT DUPLICATE USER"
        ) && all_tests_passed;

    all_tests_passed = 
        check(
            service.count() == 1u,
            "SERVICE USER COUNT"
        ) && all_tests_passed;

    all_tests_passed = 
        check(
            service.update(1, "Bob", 30),
            "UPDATE EXISTING USER"
        ) && all_tests_passed;

    all_tests_passed = 
        check(
            service.find(1)->get_name() == "Bob",
            "CHECK UPDATE NAME"
        ) && all_tests_passed;
    
    all_tests_passed = 
        check(
            service.find(1)->get_age() == 30,
            "CHECK UPDATE AGE"
        ) && all_tests_passed;

    all_tests_passed = 
        check(
            service.update(99, "Nobody", 100) == false,
            "UPDATE NON EXISTING USER"
        ) && all_tests_passed;        
    
    all_tests_passed = 
        check(
            service.find(1).has_value(),
            "FIND EXISTING USER"
        ) && all_tests_passed;

    all_tests_passed = 
        check(
            !service.find(99).has_value(),
            "FIND NON EXISTING USER"
        ) && all_tests_passed;

    all_tests_passed = 
        check(
            service.remove(1),
            "DELETE EXISTING USER"
        ) && all_tests_passed;

    all_tests_passed = 
        check(
            service.count() == 0u,
            "COUNT AFTER DELETE"
        ) && all_tests_passed;

    all_tests_passed = 
        check(
            service.remove(1) == false,
            "DELETE NON EXISTING USER"
        ) && all_tests_passed;

    return all_tests_passed;
}

int main ()
{
    bool all_tests_passed = true;

    // all_tests_passed =
    //     run_user_manager_tests() && all_tests_passed;

    all_tests_passed =
        run_user_service_tests() && all_tests_passed;


    if (all_tests_passed)
    {
        std::cout << "ALL TESTS PASSED\n";
        return 0;
    }

    std::cout << "SOME TEST FAILED\n";
    return 1;
}
