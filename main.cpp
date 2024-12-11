#include <iostream>
#include <string>
#include "admin.h"
#include "flyer.h"
using namespace std;

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
    arrAdmin[3] = Admin("asd", "UID1323", "asd");

    Flyer arrFlyer[10];

    while (true) {
        int choice;
        system("cls");
        cout << "Welcome to Horizon Vista" << endl;
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
            FlyerLoginInfo loginInfo = f.flyerLogin();
            MemberValidationResult mvr = validateMemberLogin(&loginInfo);
            if(!mvr.isValid){
                cout << "Wrong ID or password" << endl;
                cout << "Press enter to continue ..." << endl;
                cin.ignore();
                cin.get();
                continue;
            }
            mvr.flyerMember.viewMemberstatus();
            cout << "Press enter to continue ..." << endl;
            cin.ignore();
            cin.get();
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