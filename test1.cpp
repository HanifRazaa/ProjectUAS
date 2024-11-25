#include <iostream>
#include <string>
using namespace std;

class user{
    public:
    void viewDesti(){
        system("cls");
        cout << "Where We Fly" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Yogyakarta, Indonesia" << endl;
        cout << "Singapore" << endl;
        cout << "Rome, Italy" << endl;
        cout << "Osaka, Japan" << endl;
    }
    void viewFlights(){
        system("cls");
        cout << "Flights Available" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Jakarta - Yogyakarta " << endl;
        cout << "Jakarta - Singapore " << endl;
        cout << "Jakarta - Rome " << endl;
        cout << "Jakarta - Osaka " << endl;
    }

    string viewmemberBenefit(){
        system("cls");
        cout << "Our Frequent Flyer Benefit" << endl;
        cout << "-----------------------------------" << endl;
        cout << "For Blue tier, you will get" << endl;
        cout << "Free WiFi on your flights" << endl;
        cout << "Save 15% for your seat selection" << endl;
        cout << "-----------------------------------" << endl;
        cout << "For Maroon tier, you will get" << endl;
        cout << "all benefits of Blue, plus :" << endl;
        cout << "Free on-board snacks on all your flights" << endl;
        cout << "Extra 10 kg baggage allowance" << endl;
        cout << "-----------------------------------" << endl;
        cout << "For Gold tier, you will get" << endl;
        cout << "all benefits of Maroon, plus :" << endl;
        cout << "Priority check-in " << endl;
        cout << "Priority boarding" << endl;
        cout << "Access to our exclusive lounge" << endl;
        cout << "Save 25% for your seat selection" << endl;
        cout << "Discount on redemption fee" << endl;
        cout << "-----------------------------------" << endl;
        cout << "For Platinum tier, you will get" << endl;
        cout << "all benefits of Gold, plus :" << endl;
        cout << "Priority check-in " << endl;
        cout << "Priority boarding" << endl;
        cout << "all benefits of Gold, plus :" << endl;
        cout << "Free seat selection" << endl;
        cout << "Extra 25 kg baggage allowance" << endl;
        cout << "Our special service to assist you in airport " << endl;
        cout << "No redemption fee" << endl;
    }
};

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
    string benefit;
    string memberTier;
    if (memberTier == "Blue"){
        cout << "Free WiFi on your flights" << endl;
        cout << "Save 15% for your seat selection" << endl;
    }
    else if (memberTier == "Maroon"){
        cout << "all benefits of Blue, plus :" << endl;
        cout << "Free on-board snacks on all your flights" << endl;
        cout << "Extra 10 kg baggage allowance" << endl;
    }
    else if (memberTier == "Gold"){
        cout << "all benefits of Maroon, plus :" << endl;
        cout << "Priority check-in " << endl;
        cout << "Priority boarding" << endl;
        cout << "Access to our exclusive lounge" << endl;
        cout << "Save 25% for your seat selection" << endl;
        cout << "Discount on redemption fee" << endl;
    }
    else if (memberTier == "Platinum"){
        cout << "all benefits of Gold, plus :" << endl;
        cout << "Free seat selection" << endl;
        cout << "Extra 25 kg baggage allowance" << endl;
        cout << "Our special service to assist you in airport " << endl;
        cout << "No redemption fee" << endl;
    }
    return benefit;
    }

class Admin : public user{
    private:
    string name;
    string id;
    string password;
    public:
    void adminLogin(){
        system("cls");
        cout << "Enter your ID and password" << endl;
    }
    void createFlyer(){

    }
};

class Flyer{
    public:
    void flyerLogin(){
        system("cls");
        cout << "Please enter your flyer ID and password" << endl;
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
int main(){
    user u;
    Admin n;
    Flyer f;
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
        f.flyerLogin();
    }
    else if (choice == 5){
        f.bookFlight();
    }
    else if (choice == 6){
        n.adminLogin();
    }
    else {
        system("cls");
        cout << "Thank you for choosing our airline" << endl;
    }
    return choice;
};