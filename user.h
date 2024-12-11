#include <iostream>
#include <fstream>

class User{
    public:
    void viewDesti(){
        system("cls");
        std::cout << "Where We Fly" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Yogyakarta, Indonesia" << std::endl;
        std::cout << "Singapore" << std::endl;
        std::cout << "Rome, Italy" << std::endl;
        std::cout << "Osaka, Japan" << std::endl;
        std::cout << "-----------------------------------" << std::endl;

        std::cout << "Press enter to continue...";
            std::cin.ignore();
            std::cin.get();
    }
    void viewFlights(){
        system("cls");
        std::cout << "Flights Available" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Jakarta(CGK) - Yogyakarta(YIA) " << std::endl;
        std::cout << "Jakarta(CGK) - Singapore(SIN) " << std::endl;
        std::cout << "Jakarta(CGK) - Rome(FCO) " << std::endl;
        std::cout << "Jakarta(CGK) - Osaka(KIX) " << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Press enter to continue...";
            std::cin.ignore();
            std::cin.get();
    }

    void viewmemberBenefit(){
        system("cls");
        std::cout << "Our Frequent Flyer Benefit" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "For Blue tier, you will get" << std::endl;
        std::cout << "Free WiFi on your flights" << std::endl;
        std::cout << "Save 15% for your seat selection" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "For Maroon tier, you will get" << std::endl;
        std::cout << "all benefits of Blue, plus :" << std::endl;
        std::cout << "Free on-board snacks on all your flights" << std::endl;
        std::cout << "Extra 10 kg baggage allowance" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "For Gold tier, you will get" << std::endl;
        std::cout << "all benefits of Maroon, plus :" << std::endl;
        std::cout << "Priority check-in " << std::endl;
        std::cout << "Priority boarding" << std::endl;
        std::cout << "Access to our exclusive lounge" << std::endl;
        std::cout << "Save 25% for your seat selection" << std::endl;
        std::cout << "Discount on redemption fee" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "For Platinum tier, you will get" << std::endl;
        std::cout << "all benefits of Gold, plus :" << std::endl;
        std::cout << "Free seat selection" << std::endl;
        std::cout << "Extra 25 kg baggage allowance" << std::endl;
        std::cout << "Our special service to assist you in airport " << std::endl;
        std::cout << "No redemption fee" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Press enter to continue...";
            std::cin.ignore();
            std::cin.get();
    }
};