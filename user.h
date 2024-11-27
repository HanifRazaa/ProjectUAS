#include <iostream>

class User{
    public:
    void viewDesti(){
        system("cls");
        std::cout << "Where We Fly" << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << "Yogyakarta, Indonesia" << endl;
        std::cout << "Singapore" << endl;
        std::cout << "Rome, Italy" << endl;
        std::cout << "Osaka, Japan" << endl;
        std::cout << "-----------------------------------" << endl;

        std::cout << "Press enter to continue...";
            std::cin.ignore();
            std::cin.get();
    }
    void viewFlights(){
        system("cls");
        std::cout << "Flights Available" << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << "Jakarta - Yogyakarta " << endl;
        std::cout << "Jakarta - Singapore " << endl;
        std::cout << "Jakarta - Rome " << endl;
        std::cout << "Jakarta - Osaka " << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << "Press enter to continue...";
            std::cin.ignore();
            std::cin.get();
    }

    string viewmemberBenefit(){
        system("cls");
        std::cout << "Our Frequent Flyer Benefit" << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << "For Blue tier, you will get" << endl;
        std::cout << "Free WiFi on your flights" << endl;
        std::cout << "Save 15% for your seat selection" << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << "For Maroon tier, you will get" << endl;
        std::cout << "all benefits of Blue, plus :" << endl;
        std::cout << "Free on-board snacks on all your flights" << endl;
        std::cout << "Extra 10 kg baggage allowance" << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << "For Gold tier, you will get" << endl;
        std::cout << "all benefits of Maroon, plus :" << endl;
        std::cout << "Priority check-in " << endl;
        std::cout << "Priority boarding" << endl;
        std::cout << "Access to our exclusive lounge" << endl;
        std::cout << "Save 25% for your seat selection" << endl;
        std::cout << "Discount on redemption fee" << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << "For Platinum tier, you will get" << endl;
        std::cout << "all benefits of Gold, plus :" << endl;
        std::cout << "Free seat selection" << endl;
        std::cout << "Extra 25 kg baggage allowance" << endl;
        std::cout << "Our special service to assist you in airport " << endl;
        std::cout << "No redemption fee" << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << "Press enter to continue...";
            std::cin.ignore();
            std::cin.get();
    }
};