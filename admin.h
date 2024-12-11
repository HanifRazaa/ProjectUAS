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
            system("cls");
            std::string tiers[4] = {
                "blue", "maroon", "gold", "platinum"
            };
            std::string name, id, password;
            int flyerTier;
            std::ofstream FlyerO;
            FlyerO.open("flyers.csv", std::ios::app);
            std::cout << "Add new flyer" << std::endl;
            std::cout << "=============" << std::endl;
            std::cout << "[1] Blue" << std::endl;
            std::cout << "[2] Maroon" << std::endl;
            std::cout << "[3] Gold" << std::endl;
            std::cout << "[4] Platinum" << std::endl;
            std::cout << "=============" << std::endl;
            std::cin.ignore();
            std::cout << "ID: ";
            getline(std::cin, id);
            std::cout << "Name: ";
            getline(std::cin, name);
            std::cout << "Create Password: ";
            getline(std::cin, password);
            std::cout << "Choose Tier [1-4]: ";
            std::cin >> flyerTier;
            FlyerO << id << ",";
            FlyerO << name << ",";
            FlyerO << password << ",";
            FlyerO << tiers[flyerTier-1] << ",";
            FlyerO << "0" << ",";
            FlyerO << std::endl;
            FlyerO.close();
            std::cout << "\nFlyer Created" << std::endl;
            std::cout << "-------------" << std::endl;
            std::cout << "Press Enter to Continue..." << std::endl;
            std::cin.ignore();
            std::cin.get();
        }

        void editFlyer(){
            system("cls");
            std::string tiers[4] = {"blue", "maroon", "gold", "platinum"};
            std::ofstream tempOut;
            std::fstream file("flyers.csv");
            if (!file.is_open())
            {
                std::cerr << "Error to open file" << std::endl;
                return;
            }
            int selectedIndex;
            std::string line;
            int memberIndex = 1;
            std::cout << "TIERS" << std::endl;
            std::cout << "=============" << std::endl;
            std::cout << "[1] Blue" << std::endl;
            std::cout << "[2] Maroon" << std::endl;
            std::cout << "[3] Gold" << std::endl;
            std::cout << "[4] Platinum" << std::endl;
            std::cout << "=============\n" << std::endl;
            std::cout << "INDEX | FLYER NAME | TIER" << std::endl;
            std::cout << "------|------------|-----" << std::endl;
            while (getline(file, line))
            {
                std::string data[5];
                std::string buff;
                int dataPos = 0;

                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] == ',')
                    {
                        data[dataPos] = buff;
                        dataPos++;
                        buff = "";
                        continue;
                    }
                    buff += line[i];
                }

                std::cout << "[" << memberIndex << "] ";
                std::cout << data[1] << " | ";
                std::cout << data[3];
                std::cout << "\n======\n";
                memberIndex++;
            }
            int updatedTier;
            std::cout << "Please enter index of member: ";
            std::cin >> selectedIndex;
            std::cout << "New flyer tier [1-4]: ";
            std::cin >> updatedTier;

            tempOut.open("temp.csv", std::ios::app);
            memberIndex = 1;
            std::ifstream file2temp("flyers.csv");
            if (!file2temp.is_open())
            {
                std::cerr << "Error to open file" << std::endl;
                return;
            }
            while (getline(file2temp, line))
            {
                std::string data[5];
                std::string buff;
                int dataPos = 0;

                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] == ',')
                    {
                        data[dataPos] = buff;
                        dataPos++;
                        buff = "";
                        continue;
                    }
                    buff += line[i];
                }

                tempOut << data[0] << ",";
                tempOut << data[1] << ",";
                tempOut << data[2] << ",";
                if (memberIndex == selectedIndex)
                {
                    tempOut << tiers[updatedTier-1] << ",";
                }
                else
                {
                    tempOut << data[3] << ",";
                }
                tempOut << data[4] << ",";
                tempOut << std::endl;
                memberIndex++;
            }
            tempOut.close();
            file.close();
            file2temp.close();

            remove("flyers.csv");
            rename("temp.csv", "flyers.csv");
        }

        void deleteFlyer(){
            system("cls");
            std::ofstream tempOut;
            std::fstream file("flyers.csv");
            if (!file.is_open())
            {
                std::cerr << "Error to open file" << std::endl;
                return;
            }
            int selectedIndex;
            std::string line;
            int memberIndex = 1;
            std::cout << "INDEX | FLYER NAME | ID" << std::endl;
            std::cout << "------|------------|------------" << std::endl;
            while (getline(file, line))
            {
                std::string data[5];
                std::string buff;
                int dataPos = 0;

                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] == ',')
                    {
                        data[dataPos] = buff;
                        dataPos++;
                        buff = "";
                        continue;
                    }
                    buff += line[i];
                }

                std::cout << "[" << memberIndex << "] ";
                std::cout << data[1] << " | ";
                std::cout << data[0];
                std::cout << "\n======\n";
                memberIndex++;
            }
            std::cout << "Please enter index of flyer: ";
            std::cin >> selectedIndex;

            tempOut.open("temp.csv", std::ios::app);
            memberIndex = 1;
            std::ifstream file2temp("flyers.csv");
            if (!file2temp.is_open())
            {
                std::cerr << "Error to open file" << std::endl;
                return;
            }
            while (getline(file2temp, line))
            {
                if (memberIndex == selectedIndex)
                {
                    memberIndex++;
                    continue;
                }
                std::string data[5];
                std::string buff;
                int dataPos = 0;

                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] == ',')
                    {
                        data[dataPos] = buff;
                        dataPos++;
                        buff = "";
                        continue;
                    }
                    buff += line[i];
                }

                tempOut << data[0] << ",";
                tempOut << data[1] << ",";
                tempOut << data[2] << ",";
                tempOut << data[3] << ",";
                tempOut << data[4] << ",";
                tempOut << std::endl;
                memberIndex++;
            }
            tempOut.close();
            file.close();
            file2temp.close();

            remove("flyers.csv");
            rename("temp.csv", "flyers.csv");
        }
};