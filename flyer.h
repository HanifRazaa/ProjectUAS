
#include <iostream>
using namespace std;

int flyerPoints(){
    int flyerPoints = 0;
    return flyerPoints;
};

string memberStatus(){
    string memberTier;
    int flyerpoints;
    if (flyerpoints<150){
        memberTier = "Blue"; 
    }
    else if (flyerpoints<250){
        memberTier = "Maroon";
    }
    else if (flyerpoints<350){
        memberTier = "Gold";
    }
    else if (flyerpoints>500){
        memberTier = "Platinum";
    }
    return memberTier;
}

string memberBenefit(){

    const int BLUE = 0;
    const int MAROON = 1;
    const int GOLD = 2;
    const int PLATINUM = 3; 

    string benefit;
    int memberTier;
    switch (memberTier) {
        case BLUE:
            cout << "Free WiFi on your flights" << endl;
            cout << "Save 15% for your seat selection" << endl;
            break;
        case MAROON:
            cout << "all benefits of Blue, plus :" << endl;
            cout << "Free on-board snacks on all your flights" << endl;
            cout << "Extra 10 kg baggage allowance" << endl;
            break;
        case GOLD:
            cout << "all benefits of Maroon, plus :" << endl;
            cout << "Priority check-in " << endl;
            cout << "Priority boarding" << endl;
            cout << "Access to our exclusive lounge" << endl;
            cout << "Save 25% for your seat selection" << endl;
            cout << "Discount on redemption fee" << endl;
            break;
        case PLATINUM:
            cout << "all benefits of Gold, plus :" << endl;
            cout << "Free seat selection" << endl;
            cout << "Extra 25 kg baggage allowance" << endl;
            cout << "Our special service to assist you in airport " << endl;
            cout << "No redemption fee" << endl;
            break;
    }
    return benefit;
}

class Flyer{
    private:
    std::string name;
    std::string flyerID;
    std::string password;
    bool _validateLogin(std::string _name, std::string _password, Flyer arrFlyer[10]){}
    public:
    Flyer(std::string _name, std::string _flyerID, std::string _password){
        Flyer::name = _name;
        Flyer::flyerID = _flyerID;
        Flyer::password = _password;
    }
    Flyer(){}
    void flyerLogin(Flyer arrFlyer[10]){
        std::string _name, _password;
        system("cls");
        cout << "Please enter your flyer ID and password" << endl;
        cout << "----------" << endl;
            cout << "username: ";
            cin >> _name;
            cout << "password: ";
            cin >> _password;

            cout << "----------" << endl;
            Flyer::_validateLogin(_name, _password, arrFlyer);
            
            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();
    }
    void bookFlight(){
        int choice;
        int points = flyerPoints();
        system("cls");
        cout << "Choose your Destination" << endl;
        cout << "1. CGK - YIA" << endl;
        cout << "2. CGK - SIN" << endl;
        cout << "3. CGK - FCO" << endl;
        cout << "4. CGK - KIX" << endl;
        cin >> choice;
        if (choice == 1){
           cout << "Your flight is booked" << endl;
           points += 60;
        }
        else if (choice == 2){
            cout << "Your flight is booked" << endl;
            points += 80;
        }
        else if (choice == 3){
            cout << "Your flight is booked" << endl;
            points += 200;
        }
        else if (choice == 4){
            cout << "Your flight is booked" << endl;
            points += 150;
        }
        
    }
    
    void viewMemberstatus(){
        string benefit = memberBenefit();
        int points = flyerPoints();
        string tier = memberStatus();

        system("cls");
        cout << "Your Frequent Flyer tier is : " << tier << endl;
        cout << "-----------------------------------" << endl;
        cout << "Flyer Points : " << points << endl;
        cout << "In the next flight, you can : " << benefit << endl;
    }
};