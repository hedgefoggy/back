#include <iostream>
#include <string>

#include "UserService.h"


int main()
{
    UserService service;

    while (true)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Register user\n";
        std::cout << "2. Show user count\n";
        std::cout << "3. Find user\n";
        std::cout << "4. Delete user\n";
        std::cout << "5. Update user\n";
        std::cout << "0. Exit\n";

        std::cout << "Choose action: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
            case 0: // Exit
                std::cout << "Goodbye!\n";
                return 0;            
            
            case 1: // Register
            {
                int id;
                std::string name;
                int age;

                std::cout << "Enter id: ";
                std::cin >> id;

                std::cout << "Enter name: ";
                std::cin >> name;

                std::cout << "Enter age: ";
                std::cin >> age;

                if (service.register_user(id, name, age))
                {
                    std::cout << "User registered successfully\n";
                }
                else
                {
                    std::cout << "User with this id already exists\n";
                }
                break;
            }

            case 2: // Count
                std::cout << "User count: " << service.get_user_count() << "\n";
                break;            

            case 3: // Find
            {
                int id;

                std::cout << "Enter id: ";
                std::cin >> id;

                User* user = service.find_user(id);

                if (user != nullptr)
                {
                    std::cout << "User found:\n";
                    std::cout << "ID: " << user->get_id() << "\n";
                    std::cout << "Name: " << user->get_name() << "\n";
                    std::cout << "Age: " << user->get_age() << "\n";
                }
                else
                {
                    std::cout << "User not found\n";
                }
                break;
            }

            case 4: // Delete
            {
                int id;
                std::cout << "Enter id: ";
                std::cin >> id;

                if (service.delete_user(id))
                {
                    std::cout << "User deleted successfully\n";
                }
                else
                {
                    std::cout << "User not found\n";
                }
                break;
            }

            case 5: // Update
            {
                int id;
                std::string name;
                int age;

                std::cout << "Enter id: ";
                std::cin >> id;

                std::cout << "Enter new name: ";
                std::cin >> name;

                std::cout << "Enter new age: ";
                std::cin >> age;

                if (service.update_user(id, name, age))
                {
                    std::cout << "User updated successfully\n";
                }
                else
                {
                    std::cout << "User not found\n";
                }
                break;
            }
            
            default:
                std::cout << "Unknown command\n";
                break;                
        }
    }
    return 0;
}