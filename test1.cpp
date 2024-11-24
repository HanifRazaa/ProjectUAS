#include <iostream>
using namespace std;

class user{
    public:
    void viewDesti(){
        cout << "Where We Fly" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Yogyakarta, Indonesia" << endl;
        cout << "Singapore" << endl;
        cout << "Rome, Italy" << endl;
        cout << "Osaka, Japan" << endl;
    }
    void viewFlights(){
        cout << "Flights Available" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Jakarta (CGK) - Yogyakarta (YIA)" << endl;
        cout << "Jakarta (CGK) - Singapore (SIN)" << endl;
        cout << "Jakarta (CGK) - Rome (FCO)" << endl;
        cout << "Jakarta (CGK) - Osaka (KIX)" << endl;
    }

    void viewMemberstatus(){
        cout << "Your Frequent Flyer tier is : " << memberStatus << endl;
        cout << "-----------------------------------" << endl;
        cout << "Flyer Points : " << flyerPoints << endl;
        cout << "-----------------------------------" << endl;
        cout << "In the next flight, you can : " << memberBenefit << endl;
    }
};

int flyerPoints(){
    int flyerPoints = 0;
};
string memberStatus(){
    string memberTier;
    int flyerpoints;
    if (flyerpoints<150){
        memberTier = "White"; 
    }
    else if (flyerpoints<250){
        memberTier = "Maroon";
    }
    else if (flyerpoints<350){
        memberTier = "Gold";
    }
    else if (flyerpoints>500){
        memberTier = "Black";
    }
    return memberTier;
}

string memberBenefit(){
    string benefit;
    string memberTier;
    if (memberTier == "White"){
        cout << "" << endl;
    }
    else if (memberTier == "Maroon"){
        cout << "" << endl;
    }
    else if (memberTier == "Gold"){
        cout << "" << endl;
    }
    else if (memberTier == "Black"){
        cout << "" << endl;
    }
    return benefit;
}
int main(){
    int choice = UserInput();
    switch (choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    }
    return 0;
};

int UserInput(){
    int choice;
    cout << "Welcome to Fly-Air" << endl;
    cout << "1. View Destination" << endl;
    cout << "2. View Flights" << endl;
    cout << "3. View Member Status" << endl;
    cout << "4. Book a Flight" << endl;
    cout << "5. Admin Login" << endl;
    cout << "6. Exit" << endl;
    cin >> choice;
    return choice;
};