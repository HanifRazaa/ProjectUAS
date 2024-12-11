
using namespace std;

int flyerPoints(){
    int flyerPoints = 0;
    return flyerPoints;
};

string memberStatus(int flyerpoints){
    string memberTier;
    if (flyerpoints<150){
        memberTier = "blue"; 
    }
    else if (flyerpoints<250){
        memberTier = "maroon";
    }
    else if (flyerpoints<350){
        memberTier = "gold";
    }
    else if (flyerpoints>=350){
        memberTier = "platinum";
    }
    return memberTier;
}

void memberBenefit(string tier){
    int tierCode;
    if (tier == "blue") {
        tierCode = 0;
    }
    else if (tier == "maroon") {
        tierCode = 1;
    }
    else if (tier == "gold") {
        tierCode = 2;
    }
    else if (tier == "platinum") {
        tierCode = 3;
    }

    const int BLUE = 0;
    const int MAROON = 1;
    const int GOLD = 2;
    const int PLATINUM = 3; 

    switch (tierCode) {
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
}

struct FlyerLoginInfo {
    std::string ID;
    std::string password;
};

class Flyer{
    private:
    std::string name;
    std::string flyerID;
    std::string password;
    int points;
    std::string tier;

    // bool _validateLogin(std::string _name, std::string _password){
    //     std::string line;
    //     bool isMemberValid = false;
    //     std::fstream file("flyers.csv");
    //     if (!file.is_open())
    //     {
    //         std::cerr << "Error to open file" << std::endl;
    //         return;
    //     }
    //     while (getline(file, line))
    //     {
    //         std::string data[5];
    //         std::string buff;
    //         int dataPos = 0;

    //         for (int i = 0; i < line.length(); i++)
    //         {
    //             if (line[i] == ',')
    //             {
    //                 data[dataPos] = buff;
    //                 dataPos++;
    //                 buff = "";
    //                 continue;
    //             }
    //             buff += line[i];
    //         }
    //         if(data[1] == _name && data[2] == _password){
    //             isMemberValid = true;
    //         }
    //     }
    //     file.close();
    //     return isMemberValid;
    // }
    public:
    Flyer(){}
    Flyer(std::string _name, std::string _flyerID, std::string _password){
        Flyer::name = _name;
        Flyer::flyerID = _flyerID;
        Flyer::password = _password;
    }

    Flyer(std::string _name, std::string _flyerID, int _points, std::string _tier)
    {
        Flyer::name = _name;
        Flyer::flyerID = _flyerID;
        Flyer::points = _points;
        Flyer::tier = _tier;
    }
    FlyerLoginInfo flyerLogin()
    {
        std::string _id, _password;
        system("cls");
        cout << "Please enter your flyer ID and password" << endl;
        cout << "----------" << endl;
        cout << "ID: ";
        cin >> _id;
        cout << "password: ";
        cin >> _password;
        return {_id, _password};
    }
    void bookFlight(){
        int choice;
        string id;
        std::string line;
        int currentPoints;
        bool isMemberFound = false;
        int points;
        system("cls");
        cout << "[1] CGK - YIA" << endl;
        cout << "[2] CGK - SIN" << endl;
        cout << "[3] CGK - FCO" << endl;
        cout << "[4] CGK - KIX" << endl;
        cout << "=============" << endl;
        cout << "Choose your Destination [1-4]: ";
        cin >> choice;
        cin.ignore();
        cout << "Please enter your id number: ";
        getline(cin, id);
        std::ofstream tempOut;
        std::fstream file("flyers.csv");
        if (!file.is_open())
        {
            std::cerr << "Error to open file" << std::endl;
            return;
        }
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

            if (data[0] == id){
                isMemberFound = true;
                points = stoi(data[4]);
                break;
            }
        }
        if(!isMemberFound){
            cout << "You are currently not a member, please register" << endl;
            cout << "Press enter to continue..." << endl;
            cin.get();
            return;
        }

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

        tempOut.open("temp.csv", std::ios::app);
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
            if (data[0] == id)
            {
                string tier = memberStatus(points);
                tempOut<< tier << ",";
            }
            else
            {
                tempOut << data[3] << ",";
            }
            if (data[0] == id)
            {
                tempOut << points << ",";
            }
            else
            {
                tempOut << data[4] << ",";
            }
            tempOut << std::endl;
        }
        tempOut.close();
        file.close();
        file2temp.close();

        remove("flyers.csv");
        rename("temp.csv", "flyers.csv");
    }
    
    void viewMemberstatus(){
        

        system("cls");
        cout << "Your Frequent Flyer tier is : " << Flyer::tier << endl;
        cout << "-----------------------------------" << endl;
        cout << "Flyer Points : " << Flyer::points << endl;
        cout << "In the next flight, you can: " << endl;
        memberBenefit(Flyer::tier);
    }
};

struct MemberValidationResult
{
    bool isValid;
    Flyer flyerMember;
};

MemberValidationResult validateMemberLogin(FlyerLoginInfo *loginInfo)
{
    std::string line;
    bool isMemberValid = false;
    std::fstream file("flyers.csv");
    Flyer flyer = Flyer("", "", 0, "");
    MemberValidationResult mvr = {isMemberValid, flyer};
    if (!file.is_open())
    {
        std::cerr << "Error to open file" << std::endl;
        return mvr;
    }
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
        cout << loginInfo->ID << " " << loginInfo->password << endl;
        if (data[0] == loginInfo->ID && data[2] == loginInfo->password)
        {
            mvr.isValid = true;
            mvr.flyerMember = Flyer(data[0], data[1], stoi(data[4]), data[3]);
        }
    }
    file.close();
    return mvr;
}