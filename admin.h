#include <iostream>
#include "user.h"

class Admin : public User{
    private:
        std::string name;
        std::string id;
        std::string password;

        bool _validateLogin(std::string _name, std::string _password, Admin arrAdmin[10]) {
            bool isSuccess = false;
            for (int i = 0; i < 10; i++) {
                if (_name == arrAdmin[i].name && _password == arrAdmin[i].password) {
                    isSuccess = true;
                    break;
                }
            }
            if (isSuccess) {
                std::cout << "Login success." << std::endl;
                return isSuccess;
            }
            else {
                std::cout << "Invalid username or password. Please try again." << std::endl;
                return isSuccess;
            }
        }

    public:
        Admin(std::string _name, std::string _id, std::string _password){
            Admin::name = _name;
            Admin::id = _id;
            Admin::password = _password;
        }

        Admin(){}

        bool adminLogin(Admin arrAdmin[10]){
            std::string _name, _password;
            system("cls");
            std::cout << "Enter your username and password :" << std::endl;
            std::cout << "----------" << std::endl;
            std::cout << "username: ";
            std::cin >> _name;
            std::cout << "password: ";
            std::cin >> _password;

            std::cout << "----------" << std::endl;
            bool loginStatus = Admin::_validateLogin(_name, _password, arrAdmin);
            
            if (!loginStatus) {
                std::cout << "Press enter to continue...";
                std::cin.ignore();
                std::cin.get();
                return loginStatus;
            }
            return loginStatus;
        }
        void createFlyer(){

        }

        void editFlyer(){

        }

        void deleteFlyer(){

        }
};