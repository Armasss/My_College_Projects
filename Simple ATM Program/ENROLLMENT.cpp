//Created by: Mark Rainier Armas and Uriel Papa
//BSIS 2A DSA

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <time.h>
#include <windows.h>
#include <sys/stat.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include "design.h"
#define KEY 9
#define MAX 100
using namespace std;

typedef struct Account
{
    string accountNumber;
    string accountName;
    string birthday;
    string contactNumber;
    double initialDeposit;
    string pinCode;

} BANK;
typedef struct adtlist
{
    BANK account[MAX];
    int Last;
} LIST;

class RegistrationModule
{
private:
    LIST L;
    BANK *p;
    const double initial_deposite = 5000.00;
    const int min = 10000;
    const int max = 99999;
    const string pinPath = "D:\\pincode.txt";
    const string dataPath = "database.txt";
    string months[12] =
    {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    void addacc(BANK *p);
    void createfile(BANK *p);
    bool account_checker();
    void file();
    void registerAccount();
    string promptForAccountName();
    string promptForBirthday();
    string promptForContactNumber();
    double promptForInitialDeposit();
    string promptForPinCode();
    string generateAccountNumber();
    bool isDouble(string inputDeposit);
    bool isValidMonth(int month);
    bool isValidDay(int day, int month);
    bool isInsufficientBal(double user_deposit);
    bool promptForConfirmPincode(const char* originalPinCode);
    bool numberChecker(string contactNum);
    bool stringIsdigit(const string& input);
    bool atmIsremoved();
    void registrationUi(BANK A);
    string decrypt(string p);
    string encrypt(string p);
    void checkAtm_at_enroll();
    void editInfo(BANK *E);
    void display();
    void registered();

public:
    RegistrationModule()
    {
        L.Last = -1;
    }
    void atmdetect();
    void retrievefile();
};

string RegistrationModule::decrypt(string p)
{
    char pin[p.length() + 1];
    strcpy(pin,p.c_str());
    for(int i = 0; i < p.length(); i++)
    {
        pin[i] = pin[i] - KEY;
    }

    return string(pin);
}
string RegistrationModule::encrypt(string p)
{
    char pin[p.length() + 1];
    strcpy(pin,p.c_str());
    for(int i = 0; i < p.length(); i++)
    {
        pin[i] = pin[i] + KEY;
    }

    return string(pin);
}

void RegistrationModule::checkAtm_at_enroll()
{
    if(atmIsremoved())
    {
        clearArea(61,4,53,22);// whole box
        createBox(61,11,53,9,1);
        gotoxy(71,15); setColor(4); cout << "ATM WAS REMOVED DURING ENROLLMENT"<< flush;
        Sleep(2000);
        atmdetect();
    }
}

void RegistrationModule::atmdetect()
{
    struct stat sb;

    clearArea(5,3,110,24);
    createBox(37, 10, 45, 9, 1);
    logo();
    gotoxy(54,14); setColor(6); cout << "INSERT ATM" << flush;
    while (stat("D:/", &sb) != 0);
    gotoxy(53,14); setColor(2); cout << "ATM DETECTED" << flush;
    Sleep(2000);
    file();
}


bool RegistrationModule::atmIsremoved()
{
    struct stat sb;
    return stat("D:/", &sb) != 0;
}

void RegistrationModule::file()
{
    fstream fileptr(pinPath);
    clearArea(5,3,110,24);
    if (fileptr.fail())
    {
        createBox(38, 11, 44, 8, 1);
        gotoxy(49,14); setColor(4); cout << "ATM IS NOT REGISTERED" << flush;
        gotoxy(43,15); setColor(6); cout << "PROCEEDING TO REGISTRATION FORM..." <<flush ;
        Sleep(3000);
        registerAccount();
    }
    else
    {
        if (account_checker())
        {

            createBox(39, 9, 40, 10, 1);
            gotoxy(44,13); setColor(2); cout << "YOUR ATM IS ALREADY REGISTERED" << flush;
            gotoxy(53,14); setColor(6); cout << "REMOVE ATM" << flush;
            fileptr.close();
            while(atmIsremoved()==false);
            atmdetect();
        }
        else
        {
            createBox(13, 9, 93, 11, 1);
            gotoxy(30,13); setColor(4); cout << "YOU HAVE A PIN FILE BUT YOUR ACCOUNT IS NOT IN OUR DATABASE" << flush;
            gotoxy(42,14); setColor(6); cout << "PROCEEDING TO REGISTRATION FORM..." << endl;
            Sleep(3000);
            fileptr.close();
            registerAccount();

        }
    }
    file();
}



void RegistrationModule::addacc(BANK *p)
{
    L.Last++;
    L.account[L.Last] = *p;

}

void RegistrationModule::createfile(BANK *p)
{

    int i;
    ofstream fileptr(dataPath);

    for(i = 0; i <= L.Last; i++)
    {

        if(i == L.Last)
        {
            fileptr << L.account[i].accountName << ")" << L.account[i].accountNumber  << " " << fixed <<  L.account[i].initialDeposit << " " << L.account[i].contactNumber << " " << L.account[i].birthday << " " << encrypt(L.account[i].pinCode);
        }
        else
        {
            fileptr << L.account[i].accountName << ")" << L.account[i].accountNumber  << " " << fixed << L.account[i].initialDeposit << " " << L.account[i].contactNumber << " " << L.account[i].birthday << " " << encrypt(L.account[i].pinCode) << endl;
        }
    }
    fileptr.close();

    fileptr.open(pinPath);

    fileptr << p->accountNumber << " " <<  encrypt(p->pinCode);

    fileptr.close();

}

void RegistrationModule::retrievefile()
{
    ifstream fileptr(dataPath);


    if(fileptr.is_open())
    {
        BANK d;
        string line;
        int strline = 0, linelength, i = 0;
        while(getline(fileptr, line))
        {
            d.accountName = line.substr(0,line.find(')'));
            line = line.substr(line.find(')')+1, line.length()-d.accountName.length());
            istringstream AccDetails(line);
            AccDetails >> d.accountNumber >> d.initialDeposit >> d.contactNumber >> d.birthday >> d.pinCode;
            d.pinCode = decrypt(d.pinCode);
            addacc(&d);
            strline++;
        }

    }

    fileptr.close();
}

bool RegistrationModule::account_checker()
{

    BANK d;
    int i;
    string line;
    ifstream fileptr (pinPath);
    fileptr >> d.accountNumber >> d.pinCode;
    d.pinCode = decrypt(d.pinCode);
    for (i = 0; i <= L.Last; i++)
    {
        if(L.account[i].accountNumber == d.accountNumber && L.account[i].pinCode == d.pinCode)
        {
            fileptr.close();
            return true;
        }
    }
    fileptr.close();
    return false;
}

void RegistrationModule::registerAccount()
{
    clearArea(5,3,110,24);
    BANK newAccount;
    display();
    newAccount.accountNumber = generateAccountNumber();
    gotoxy(28,8);
    setColor(7);
    cout << newAccount.accountNumber << flush;
    newAccount.accountName = promptForAccountName();
    newAccount.birthday = promptForBirthday();
    newAccount.contactNumber = promptForContactNumber();
    newAccount.initialDeposit = promptForInitialDeposit();
    editInfo(&newAccount);
    newAccount.pinCode = promptForPinCode();
    addacc(&newAccount);
    createfile(&newAccount);
    registered();
    while(atmIsremoved()==false);
    clearArea(5,3,110,24);
    atmdetect();
}

string RegistrationModule::promptForAccountName()
{
    string accountName;
    createBox(61,11,53,9,1);
    createBox(67,14,42,3,7);
    gotoxy(68,13); setColor(7); cout << "ENTER ACCOUNT NAME " << flush ;
    gotoxy(90,17); setColor(7); cout << "Ex. Juan Dela Cruz"<< flush;
    showcursor(); gotoxy(69,15); getline(cin >> ws, accountName); hidecursor();
    checkAtm_at_enroll();
    createBox(67,13,42,5,7);
    gotoxy(79,15); setColor(2); cout << "INFORMATION SAVED" << flush;
    gotoxy(28,12); setColor(7); cout << accountName << flush;
    Sleep(2000);
    return accountName;
}

string RegistrationModule::promptForBirthday()
{
    int monthSelection = 0;
    int day;
    string monthInput,dayInput,yearInput;
    clearArea(61,4,53,22);// whole box
    createBox(67,23,42,3,7);
    gotoxy(82,24); setColor(7); cout <<"MM/DD/YYYY"<<flush;
    gotoxy(77, 5); setColor(7); cout << "ENTER YOUR BIRTH DATE" << flush;
    for (int i = 0; i < 12; i++)
    {
        if(i < 6)
        {
            gotoxy(73, 7 + i); setColor(7); cout << "[" << i+1 << "]" << months[i] << flush;
        }
        else
        {
            gotoxy(90, 1 + i); setColor(7); cout << "[" << i+1 << "]" << months[i]  <<flush;
        }
    }

    while (true)
    {
        createBox(67,14,42,3,7);
        gotoxy(69,15); setColor(7); cout <<"SELECT A MONTH: "<<flush;
        showcursor(); getline(cin>>ws, monthInput); hidecursor();
        if (stringIsdigit(monthInput) && monthInput.size() <= 2)
        {
            monthSelection = stoi(monthInput);
            if (isValidMonth(monthSelection))
            {
                break;
            }
        }
        clearArea(68,24,40,1);
        gotoxy(69,24); setColor(4); cout << "INVALID INPUT" << endl;
        Sleep(2000);
        clearArea(68,24,40,1);
        gotoxy(82,24); setColor(7); cout <<"MM/DD/YYYY"<<flush;

    }

    while (true)
    {
        createBox(67,17,42,3,7);
        gotoxy(69,18); setColor(7); cout << "ENTER A DAY (1 TO " << daysInMonth[monthSelection - 1] << "): " << flush ;
        showcursor();getline(cin>>ws, dayInput);hidecursor();
        if (stringIsdigit(dayInput) && dayInput.size() <= 2)
        {
            day = stoi(dayInput);
            if (isValidDay(day, monthSelection))
            {
                break;
            }
            else
            {
                clearArea(68,24,40,1);
                gotoxy(69,24); setColor(4); cout << "INVALID DAY FOR THE MONTH" << flush;
                Sleep(2000);
                clearArea(68,24,40,1);
                gotoxy(82,24); setColor(7); cout <<"MM/DD/YYYY"<<flush;
            }
        }
        else
        {
            clearArea(68,24,40,1);
            gotoxy(69,24); setColor(4); cout << "INVALID FORMAT" << flush;
            Sleep(2000);
            clearArea(68,24,40,1);
            gotoxy(82,24); setColor(7); cout <<"MM/DD/YYYY"<<flush;
        }
    }

    while (true)
    {
        createBox(67,20,42,3,7);
        gotoxy(69,21); setColor(7);
        cout <<"ENTER A YEAR: "<<flush;
        showcursor(); cin >> yearInput; hidecursor();
        cin.ignore();

        if (yearInput.length() == 4 && stringIsdigit(yearInput))
        {
            yearInput = yearInput.substr(yearInput.length() - 2);
            break;
        }
        else
        {
            clearArea(68,24,40,1);
            gotoxy(69,24); setColor(4); cout << "INVALID YEAR" << flush;
            Sleep(2000);
            clearArea(68,24,40,1);
            gotoxy(82,24); setColor(7); cout <<"MM/DD/YYYY"<<flush;
        }
    }

    string formattedDate = (monthSelection < 10 ? "0" : "") + to_string(monthSelection) + "/" +
                           (day < 10 ? "0" : "") + to_string(day) + "/" +
                           yearInput;


    clearArea(61,4,53,22);// whole box
    createBox(61,11,53,9,1);
    createBox(67,13,42,5,7);
    checkAtm_at_enroll();
    gotoxy(79,15); setColor(2); cout << "INFORMATION SAVED" << flush;
    gotoxy(28,16); setColor(7); cout << formattedDate << flush;
    Sleep(2000);
    return formattedDate;
}

string RegistrationModule::promptForContactNumber()
{
    clearArea(61,4,53,22);// whole box
    createBox(61,11,53,9,1);
    createBox(67,14,42,3,7);
    string contactNumber;
    do
    {
        gotoxy(68,13); setColor(7); cout << "ENTER YOUR CONTACT NUMBER: " << flush;
        gotoxy(93,17); cout << "Ex. 09123456789"<< flush;
        gotoxy(69,15); showcursor();getline(cin, contactNumber);hidecursor();
        if (!numberChecker(contactNumber))
        {
            gotoxy(69,15); setColor(4); cout << "INVALID CONTACT NUMBER" << flush;
            Sleep(2000);
            clearArea(68,15,40,1);
        }
    }
    while (!numberChecker(contactNumber));
    checkAtm_at_enroll();
    createBox(67,13,42,5,7);
    gotoxy(79,15); setColor(2); cout << "INFORMATION SAVED" << flush;
    gotoxy(28,20); setColor(7); cout << contactNumber << flush;
    Sleep(2000);
    return contactNumber;
}

double RegistrationModule::promptForInitialDeposit()
{
    clearArea(61,4,53,22);// whole box
    createBox(61,11,53,9,1);
    createBox(67,14,42,3,7);
    double deposit;
    do
    {
        createBox(67,14,42,3,7);
        string depositInput;
        gotoxy(68,13); setColor(7); cout << "ENTER INITIAL DEPOSIT" << flush;
        gotoxy(80,17); setColor(7); cout <<"Available Bill Denominations" << flush;
        gotoxy(87,18); cout <<"[50,100,200,500,1000]"<<flush;
        Sleep(2000);
        clearArea(80,17,29,2);
        gotoxy(90,17); setColor(7); cout << "[MIN. OF PHP 5000]"<< flush;
        gotoxy(69,15); showcursor(); getline(cin, depositInput); hidecursor();
        if (isDouble(depositInput))
        {
            deposit = stod(depositInput);
            if(depositInput.find('.')!= -1)
            {
                gotoxy(69,15); setColor(4); cout << "AMOUNT MUST BE WHOLE!" << flush;
                Sleep(2000);
            }
            else if(isInsufficientBal(deposit))
            {
                gotoxy(69,15); setColor(4); cout << "INVALID INTIAL DEPOSIT AMOUNT!" << flush;
                Sleep(2000);
            }
            else if(fmod(deposit,50)!= 0)
            {
                gotoxy(69,15); setColor(4); cout << "AMOUNT MUST BE MULTIPLES OF 50!" << flush;
                Sleep(2000);
            }
            else
            {
                break;
            }
        }
        else
        {
            gotoxy(69,15); setColor(4); cout << "INVALID INPUT" << flush;
            Sleep(2000);
        }
    }
    while (true);
    checkAtm_at_enroll();
    createBox(67,13,42,5,7);
    gotoxy(79,15); setColor(2); cout << "INFORMATION SAVED" << flush;
    gotoxy(28,24); setColor(7); cout << "Php " << deposit << flush;
    Sleep(2000);
    return deposit;
}

string RegistrationModule::promptForPinCode()
{
    int i;
    char pinCode[5];
    char inputChar;
    i = 0;
    do
    {
        clearArea(61,4,53,22);// whole box
        createBox(67,9,41,13,1);
        createBox(74,12,26,3,7);
        gotoxy(74,11); setColor(7); cout << "PLEASE ENTER YOUR PIN CODE" << flush ;
        i = 0;
        showcursor();
        do
        {
            gotoxy(85+i,13);
            inputChar = getch();
            if (isdigit(inputChar) && i < 4)
            {
                pinCode[i] = inputChar;
                putch('*');
                i++;
            }
            else if(inputChar == 8 && i > 0)
            {
                cout << "\b \b" << flush;
                i--;
            }
        }
        while (i < 4 || inputChar != 13);
        pinCode[i] = '\0';
        hidecursor();

        if(promptForConfirmPincode(pinCode) == false)
        {
            clearArea(61,4,53,22);
            createBox(74,11,26,9,12);
            gotoxy(76,15); setColor(4); cout << "PINCODE DOES NOT MATCH" << flush;
            Sleep(2000);
        }
        else
        {
            break;
        }
    }
    while(true);
    clearArea(61,4,53,22);// whole box
    createBox(61,11,53,9,1);
    createBox(67,13,42,5,7);
    checkAtm_at_enroll();
    gotoxy(79,15); setColor(2); cout << "INFORMATION SAVED" << flush;
    Sleep(2000);
    return string(pinCode);


}

bool RegistrationModule::promptForConfirmPincode(const char* originalPinCode)
{
    int i;
    char inputChar;
    char confirmationPinCode[5];
    createBox(74,17,26,3,7);
    gotoxy(76,16); setColor(7); cout << "CONFIRM YOUR PIN CODE" << flush ;
    i=0;
    showcursor();
    do
    {
        gotoxy(85+i,18);
        inputChar = getch();

        if (isdigit(inputChar)&& i <4)
        {
            confirmationPinCode[i] = inputChar;
            putch('*');
            i++;
        }
        else if(inputChar == 8 && i > 0)
        {
            cout << "\b \b" << flush;
            i--;
        }
    }
    while(i < 4 || inputChar != 13);
    confirmationPinCode[i] = '\0';
    hidecursor();

    return strcmp(originalPinCode, confirmationPinCode) == 0;
}

void RegistrationModule::registered()
{
    clearArea(61,4,53,22);// whole box
    createBox(61,11,53,9,1);
    gotoxy(77,14); setColor(2); cout << "ACCOUNT IS REGISTERED" << flush;
    gotoxy(78,16); setColor(6); cout<<"[PLEASE REMOVE ATM]" << flush;
}

bool RegistrationModule::isDouble(string inputDeposit)
{
    try
    {
        stod(inputDeposit);
        return true;

    }
    catch (...)
    {
        return false;
    }
}

bool RegistrationModule:: isValidMonth(int month)
{
    return month >= 1 && month <= 12;
}

bool RegistrationModule:: isValidDay(int day, int month)
{
    return day >= 1 && day <= daysInMonth[month - 1];
}

bool RegistrationModule:: isInsufficientBal(double user_deposit)
{
    return user_deposit<initial_deposite;
}

bool RegistrationModule:: numberChecker(string contactNum)
{
    return contactNum.length() == 11 && stringIsdigit(contactNum);
}

bool RegistrationModule:: stringIsdigit(const string& input)
{
    for (char c : input)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

string RegistrationModule:: generateAccountNumber()
{
    checkAtm_at_enroll();
    return to_string(min + rand() % (max - min + 1));
}
void RegistrationModule :: display()
{
    createBox(5,3,55, 24,7); // reference left
    createBox(60,3,55, 24,7); // reference right
    // LEFT
    createBox(6, 7, 20, 3, 3); // L
    createBox(26, 7, 33, 3, 3);
    createBox(6, 11, 20, 3, 3); // L
    createBox(26, 11, 33, 3, 3);
    createBox(6, 15, 20, 3, 3); // L
    createBox(26, 15, 33, 3, 3);
    createBox(6, 19, 20, 3, 3); // L
    createBox(26, 19, 33, 3, 3);
    createBox(6, 23, 20, 3, 3); // L
    createBox(26, 23, 33, 3, 3);
    gotoxy(22,5); cout <<"ACCOUNT INFORMATIONS" << flush;
    gotoxy(9,8); cout << "ACCOUNT NUMBER" << flush;
    gotoxy(10,12); cout << "ACCOUNT NAME" << flush;
    gotoxy(12,16); cout << "BIRTHDAY" << flush;
    gotoxy(9,20); cout << "CONTACT NUMBER" << flush;
    gotoxy(8,24); cout << "INITIAL DEPOSIT" << flush;

}

void RegistrationModule::editInfo(BANK *E)
{
    char temp, choice;
    do
    {
        int i = 0;
        clearArea(61,4,53,22);// whole box
        createBox(75,20,25,3,7);
        gotoxy(69,8); setColor(7); cout << "CHOOSE AN OPTION TO EDIT YOUR DETAILS" << flush;
        gotoxy(75,10); setColor(7); cout << "[1] EDIT ACCOUNT NAME" << flush;
        gotoxy(75,12); setColor(7); cout << "[2] EDIT BIRTHDAY" << flush;
        gotoxy(75,14); setColor(7); cout << "[3] EDIT CONTACT NUMBER" << flush;
        gotoxy(75,16); setColor(7); cout << "[4] EDIT INITIAL DEPOSIT" << flush;
        gotoxy(75,18); setColor(7); cout << "[5] PROCEED TO PIN CODE" << flush;
        gotoxy(77,21); setColor(7); cout << "ENTER YOUR CHOICE: " << flush;

        gotoxy(96,21);
        showcursor();
        do
        {
            temp = getch();
            if(isdigit(temp) && i == 0)
            {
                choice = temp;
                putch(choice);
                i++;
            }
            else if(temp == 8 && i == 1)
            {
                cout << "\b \b" << flush;
                i--;
            }
        }
        while(i < 0 || temp != 13);
        hidecursor();
        switch(choice)
        {
        case '1':
            clearArea(61,4,53,22);// whole box
            clearArea(27,12,30,1);
            E->accountName = promptForAccountName();
            break;
        case '2':
            clearArea(61,4,53,22);// whole box
            clearArea(27,16,30,1);
            E->birthday = promptForBirthday();
            break;
        case '3':
            clearArea(61,4,53,22);// whole box
            clearArea(27,20,30,1);
            E->contactNumber = promptForContactNumber();
            break;
        case '4':
            clearArea(61,4,53,22);// whole box
            clearArea(27,24,30,1);
            E->initialDeposit = promptForInitialDeposit();
            break;
        case '5':
            return;
        default:
            createBox(75,20,25,3,7);
            gotoxy(77,21); setColor(4); cout << "INVALID INPUT" << flush;
            Sleep(2000);
            createBox(75,20,25,3,7);
            break;
        }
    }
    while(choice != 5);
}


int main()
{
    hidecursor();
    srand(static_cast<unsigned int>(time(nullptr)));
    ios::sync_with_stdio(false);
    createBox(1,1,118, 28, 1);
    createBox(3, 2, 114, 26, 6);
    cout.unsetf(ios::floatfield);
    cout << fixed << setprecision(2) << flush;
    RegistrationModule reg;
    reg.retrievefile();
    reg.atmdetect();
}
