#include <iostream>
#include <string>
#include "admin.h"
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
    string name;
    string flyerID;
    string password;
    bool _validateLogin(string _name, string _password, Flyer arrFlyer[10]){}
    public:
    Flyer(string _name, string _flyerID, string _password){
        Flyer::name = _name;
        Flyer::flyerID = _flyerID;
        Flyer::password = _password;
    }
    Flyer(){}
    void flyerLogin(Flyer arrFlyer[10]){
        string _name, _password;
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

int UIAdmin(Admin *n){
    while (true){
        int choice;
        system("cls");
        cout << "Welcome Welcome, Admin!" << endl;
        cout << "1. Add Flyer" << endl;
        cout << "2. Edit Flyer" << endl;
        cout << "3. Delete Flyer" << endl;
        cout << "4. Logout" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        if (choice == 1){
            n->createFlyer();
        }
        else if (choice == 2){
            n->editFlyer();
        }
        else if (choice == 3){
            n->deleteFlyer();
        }
        else if (choice == 4){
            system("cls");
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            cin.ignore();
            cin.get();
        }
    }
}
int main(){
    User u;
    Admin n;
    Flyer f;
    
    Admin arrAdmin[10];
    arrAdmin[0] = Admin("hnfraza", "UID1321", "razaasadmin");
    arrAdmin[1] = Admin("alxtabita", "UID1322", "sandraasadmin");
    arrAdmin[2] = Admin("44liyah", "UID1323", "aalasadmin");

    Flyer arrFlyer[10];

    while (true) {
        int choice;
        system("cls");
        cout << "Welcome to Fly-Air" << endl;
        cout << "1. View Destination" << endl;
        cout << "2. View Flights" << endl;
        cout << "3. View Frequent Flyer Benefits" << endl;
        cout << "4. Frequent Flyer" << endl;
        cout << "5. Book a Flight" << endl;
        cout << "6. Admin Login" << endl;
        cout << "7. Exit" << endl;
        cout << "Please enter your choice : ";
        cin >> choice;
        if (choice == 1){
            u.viewDesti();
        }
        else if (choice == 2){
            u.viewFlights();
        }
        else if (choice == 3){
            u.viewmemberBenefit();
        }
        else if (choice == 4){
            f.flyerLogin(arrFlyer);
        }
        else if (choice == 5){
            f.bookFlight();
        }
        else if (choice == 6){
            bool loginState = n.adminLogin(arrAdmin);
            if (loginState) {
                UIAdmin(&n);
            }
        }
        else if (choice == 7){
            cout << "Thank you for choosing our airline" << endl;
            break;
        }
        else {
            cout << "Please select a valid option" << endl;
        }
    }
    return 0;
}

