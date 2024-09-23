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
    double balance;
    string pinCode;

} BANK;
typedef struct adtlist
{
    BANK account[MAX];
    int Last;
} LIST;

class TransactionModule
{
private:
    LIST L;
    const double minWithdraw = 100.00;
    const double maxWithdraw = 10000.00;
    const double maintainingBalance = 5000.00;
    const string pinPath = "D:\\pincode.txt";
    const string dataPath = "database.txt";
    int accIndex, recipientIndex;
    bool changePinFlag;
    bool account_checker(string accNum, string accPin);
    void savefile(BANK b);
    void addAccount(BANK y);
    void validateUser();
    void balanceInquiry();
    void withdraw();
    void deposit();
    void changePinCode();
    bool promptForConfirmPincode(const char* originalPinCode);
    void fundTransfer();
    bool recipient_finder(string name, string accNum);
    string encrypt(string p);
    string decrypt(string p);
    void proceed();
    void checkAtm_at_transac();
    bool stringIsdigit(const string& input);
    bool atmIsRemoved();
    bool isDouble(const string& input);
    void menu();

public:
    TransactionModule()
    {
        L.Last = -1;
    }
    void retrievefile();
    void checkPinfile();
};

bool TransactionModule::isDouble(const string& input)
    {
        try
        {
            stod(input);
            return true;

        }
        catch (...)
        {
            return false;
        }
    }
bool TransactionModule::account_checker(string accNum, string accPin)
{
    int i;
    for (i = 0; i <= L.Last; i++)
    {
        if(L.account[i].accountNumber == accNum && L.account[i].pinCode == accPin)
        {
            accIndex = i;
            return true;
        }
    }
    return false;
}

void TransactionModule::savefile(BANK b)
{

    int i;
    ofstream fileptr(dataPath);
    for(i = 0; i <= L.Last; i++)
    {

        if(i == L.Last)
        {
            fileptr << L.account[i].accountName << ")" << L.account[i].accountNumber  << " " << fixed << L.account[i].balance << " " << L.account[i].contactNumber << " " << L.account[i].birthday << " " << encrypt(L.account[i].pinCode);
        }
        else
        {
            fileptr << L.account[i].accountName << ")" << L.account[i].accountNumber  << " " << fixed << L.account[i].balance << " " << L.account[i].contactNumber << " " << L.account[i].birthday << " " << encrypt(L.account[i].pinCode) << endl;
        }
    }
    fileptr.close();

    if(changePinFlag == true)
    {
    fileptr.open(pinPath);

    fileptr << b.accountNumber << " " <<  encrypt(b.pinCode);

    fileptr.close();
    }

}

void TransactionModule::addAccount(BANK y)
{
    L.Last++;
    L.account[L.Last] = y;
}

void TransactionModule::validateUser()
{
    char inputPin[5];
    char inputChar;
    int i;
    int attempts = 0;

    createBox(34, 8 , 51, 13, 1);

    while (attempts < 3)
    {

        createBox(37, 10, 45, 3, 2);
        createBox(37, 13 , 45, 3, 2);
        createBox(37, 16 , 45, 3, 2);
        gotoxy(39,11);setColor(14); cout << "Welcome, " << L.account[accIndex].accountName << "!" << flush;
        gotoxy(39,14);setColor(14); cout << "Please input your PIN code to proceed" << flush;
        gotoxy(39,17);setColor(14); cout << "Enter PIN Code: " << flush;
        i = 0;
        showcursor();
        do
        {
                inputChar = getch();
                if (isdigit(inputChar) && i < 4)
                {
                    inputPin[i] = inputChar;
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
        inputPin[i] = '\0';

        hidecursor();
        checkAtm_at_transac();

        if (strcmp(L.account[accIndex].pinCode.c_str(), inputPin) == 0)
        {
            return;
        }
        else
        {
            createBox(37, 10 , 45, 9, 12);
            gotoxy(49,14);setColor(4);cout << "Incorrect PIN code." << flush;
            Sleep(2000);
            attempts++;

            if (attempts == 3)
            {
                createBox(37, 10 , 45, 9, 12);
                gotoxy(44,13);setColor(4);cout << "You have exceeded the maximum" << flush;
                gotoxy(42,15);setColor(4);cout <<"number of attempts. Eject ATM card."<< flush;
                while(atmIsRemoved()==false);
                checkPinfile();
            }
        }
    }
}

void TransactionModule::balanceInquiry()
{
    clearArea(5,3,110,24);
    createBox(35,9,49,12,1);
    createBox(39, 12, 41, 7,15);
    gotoxy(52,11);setColor(1);cout << "BALANCE INQUIRY"<< flush;
    gotoxy(41,14);setColor(10); cout << "Account Name: " << L.account[accIndex].accountName << flush;
    gotoxy(41,16);setColor(10);cout << "Current Balance: Php " << L.account[accIndex].balance << flush;
    getch();
    menu();
}

void TransactionModule::withdraw()
{

    string input;
    clearArea(5,3,110,24);
    createBox(33,8,53,14,2);
    createBox(37, 18, 45, 3, 7);
    gotoxy(55,10);setColor(1);cout << "WITHDRAW"<< flush;
    gotoxy(41,12);setColor(6); cout << "[Min: Php " << minWithdraw << ", Max: Php " << maxWithdraw << "]" << flush;
    gotoxy(45,14);setColor(6); cout << "Available Bill Denominations" << flush;
    gotoxy(44,15);setColor(6); cout << "[50 , 100 , 200 , 500 , 1000]" << flush;
    gotoxy(38,17);setColor(15);cout << "Enter amount: "<< flush;
    showcursor();gotoxy(38,19);getline(cin >> ws, input); hidecursor();


    if (!isDouble(input))
    {
        createBox(37, 18, 45, 3, 12);
        gotoxy(45,19);setColor(4);cout << "Please enter a valid amount." << flush;
        Sleep(2000);
        menu();
    }

    double amount = stod(input);

    if(input.find('.')!= -1)
    {
        createBox(37, 18, 45, 3, 12);
        gotoxy(49,19);setColor(4); cout << "Amount must be whole!" << flush;
        Sleep(2000);
        menu();
    }else if (amount < minWithdraw || amount > maxWithdraw)
    {
        createBox(37, 18, 45, 3, 12);
        gotoxy(46,19);setColor(4); cout << "Invalid withdrawal amount!" << flush;//
        Sleep(2000);
        menu();
    }else if(fmod(amount,50) != 0)
    {
        createBox(37, 18, 45, 3, 12);
        gotoxy(43,19); setColor(4);cout << "Amount should be a multiple of 50!" << flush;
        Sleep(2000);
        menu();
    }else if (amount >  L.account[accIndex].balance)
    {
        createBox(37, 18, 45, 3, 12);
        gotoxy(45,19); setColor(4);cout << "Insufficient funds!" << flush;
        Sleep(2000);
        menu();
    }else if(L.account[accIndex].balance - amount < maintainingBalance){
        createBox(37, 18, 45, 3, 12);
        gotoxy(47,19); setColor(4);cout << "Below Maintaining Balance!" << flush;
        Sleep(2000);
        menu();
    }

    proceed();
    checkAtm_at_transac();
    L.account[accIndex].balance -= amount;
    clearArea(33,8,53,14);
    createBox(33,9,53,11,2);
    gotoxy(48,11);setColor(2);cout << "Withdrawal successful!" << flush;
    createBox(37, 13 , 45, 3, 7);
    gotoxy(39,14);setColor(6); cout << "New balance: Php " << L.account[accIndex].balance << flush;
    createBox(37, 16 , 45, 3, 7);
    savefile(L.account[accIndex]);
    gotoxy(51,17);setColor(6);cout << "PLEASE REMOVE ATM"<< flush;
    while(atmIsRemoved()==false);
    clearArea(33,9,53,11);
    checkPinfile();
}

void TransactionModule::deposit()
{
    string input;
    clearArea(5,3,110,24);
    createBox(33,9,53,12,2);
    createBox(37, 17, 45, 3, 7);
    gotoxy(55,11);setColor(1);cout << "DEPOSIT"<< flush;
    gotoxy(46,13);setColor(6); cout << "Accepts Bill Denominations" << flush;
    gotoxy(45,14);setColor(6); cout << "[50 , 100 , 200 , 500 , 1000]" << flush;
    gotoxy(38,16);setColor(15);cout << "Enter amount: "<< flush;
    showcursor();gotoxy(38,18);getline(cin >> ws, input);hidecursor();


    if (!isDouble(input))
    {
        createBox(37, 17, 45, 3, 12);
        gotoxy(45,18);setColor(4);cout << "Please enter a valid amount." << flush;
        Sleep(2000);
        menu();
    }
    double amount = stod(input);

    if(input.find('.')!= -1)
    {
        createBox(37, 17, 45, 3, 12);
        gotoxy(49,18);setColor(4);cout << "Amount must be whole!" << flush;
        Sleep(2000);
        menu();
    }else if(fmod(amount,50) != 0)
    {
        createBox(37, 17, 45, 3, 12);
        gotoxy(43,18);setColor(4); cout << "Amount should be a multiple of 50!" << flush;
        Sleep(2000);
        menu();
    }

    proceed();
    checkAtm_at_transac();
    L.account[accIndex].balance += amount;
    clearArea(33,9,53,12);
    createBox(33,9,53,11,2);
    gotoxy(50,11);setColor(2);cout << "Deposit successful!" << flush;
    createBox(37, 13 , 45, 3, 7);
    gotoxy(39,14);setColor(7); cout << "New balance: Php " <<L.account[accIndex].balance << flush;
    createBox(37, 16 , 45, 3, 7);
    savefile(L.account[accIndex]);
    gotoxy(51,17);setColor(6);cout << "PLEASE REMOVE ATM"<< flush;
    while(atmIsRemoved()==false);
    clearArea(33,9,53,11);
    checkPinfile();
}

void TransactionModule::changePinCode()
{
    int i = 0;
    char currentPin[5];
    char newPin[5];
    char inputChar;
    bool check;
    int accountNum;
    string name;
    clearArea(5,3,110,24);
    createBox(33,11,53,8,1);
    createBox(36,15,47,3,7);
    gotoxy(54, 12); cout << "CHANGE PIN" << flush;
    gotoxy(37, 14); cout << "ENTER CURRENT PIN: " << flush;
    i = 0;
    gotoxy(57, 16);
    showcursor();
    do
    {
        inputChar = getch();
        if (isdigit(inputChar) && i < 4)
        {
            currentPin[i] = inputChar;
            gotoxy(57+i, 16); putch('*');
            i++;
        }else if(inputChar == 8 && i > 0)
        {
            cout << "\b \b" << flush;
            i--;

        }
    }
    while (i < 4 || inputChar != 13);
    currentPin[i] = '\0';
    hidecursor();

    if(strcmp(currentPin, L.account[accIndex].pinCode.c_str()) == 0)
    {
        do
        {
            createBox(33,8,53,13,1);
            createBox(36,12,47,3,7);
            gotoxy(54, 9); cout << "CHANGE PIN" << flush;
            gotoxy(37, 11); cout << "ENTER NEW PIN: " << flush;
            i = 0;
            gotoxy(57, 13);
            do
            {
                inputChar = getch();
                if (isdigit(inputChar) && i < 4)
                {
                    newPin[i] = inputChar;
                    gotoxy(57+i, 13); putch('*');
                    i++;
                }else if(inputChar == 8 && i > 0)
                {
                cout << "\b \b" << flush;
                i--;
                }

            }
            while (i < 4 || inputChar != 13);
            newPin[i] = '\0';
            checkAtm_at_transac();

            if(strcmp(newPin, L.account[accIndex].pinCode.c_str()) == 0)
            {
                createBox(36,11,47,9,12);
                gotoxy(43,15);setColor(4);cout << "NEW PIN IS THE SAME TO OLD PIN" << flush;
                Sleep(2000);

            }else if(promptForConfirmPincode(newPin) == false)
            {
                createBox(36,10,47,10,12);
                gotoxy(48,15);setColor(4);cout << "PINCODE DOES NOT MATCH" << flush;
                Sleep(2000);
            }else{
                break;
            }
        }
        while(true);

        proceed();
        checkAtm_at_transac();
        L.account[accIndex].pinCode = newPin;
        createBox(36,10,47,10,2);
        changePinFlag = true;
        savefile(L.account[accIndex]);
        gotoxy(45,14);setColor(2);cout << "PINCODE CHANGED SUCCESFULLY!" << flush;
        gotoxy(54,15);setColor(6);cout << "REMOVE ATM"<<flush;
        while(atmIsRemoved()==false);
        checkPinfile();
    }
    else
    {
        createBox(36,13,47,5,12);
        gotoxy(55,15);setColor(4);cout << "WRONG PIN"<<flush;
        Sleep(2000);
        menu();
    }
}

bool TransactionModule::promptForConfirmPincode(const char* originalPinCode)
{
    int i;
    char inputChar;
    createBox(36,17,47,3,7);
    gotoxy(37,16);setColor(15);cout << "Confirm PIN Code: " << flush;
    char confirmationPinCode[5];
    gotoxy(57, 18);
    i=0;
    showcursor();
    do
    {
         inputChar = getch();

        if (isdigit(inputChar) && i < 4)
        {
            confirmationPinCode[i] = inputChar;
            gotoxy(57+i, 18); putch('*');
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
    checkAtm_at_transac();
    return strcmp(originalPinCode, confirmationPinCode) == 0;
}

void TransactionModule::fundTransfer()
{
    string recipientName;
    string recipientAccountNumber;
    clearArea(5,3,110,24);createBox(33,7,53,16,1); createBox(36,12,47,3,7); createBox(36,15,47,3,7); createBox(36,18,47,3,7);
    gotoxy(53,9);setColor(1);cout << "FUND TRANSFER"<<flush;
    gotoxy(36,11);setColor(2);cout << "Recipient Details: "<<flush;
    gotoxy(37,13);setColor(15);cout << "Enter Name: "<< flush;
    showcursor();gotoxy(49,13); getline(cin >>ws, recipientName);hidecursor();
    gotoxy(37,16);setColor(15);cout << "Enter Account number: "<<flush;
    showcursor(); gotoxy(59,16);getline(cin >> ws, recipientAccountNumber);hidecursor();

    if(!stringIsdigit(recipientAccountNumber))
    {
        clearArea(37,16,44,1);
        gotoxy(53,16);setColor(4);cout << "Invalid Input"<<flush;
        Sleep(2000);
        menu();
    }
    if (recipient_finder(recipientName, recipientAccountNumber))
    {

        if(L.account[recipientIndex].accountNumber == L.account[accIndex].accountNumber)
        {
            clearArea(37,19,44,1);
            gotoxy(45,19);setColor(4);cout << "The account details are yours"<<flush;
            Sleep(2000);
            menu();
        }
        string input;
        gotoxy(37,19);setColor(15);cout << "Enter transfer amount: "<<flush;
        showcursor(); gotoxy(60,19);getline(cin >> ws, input); hidecursor();

        if (!isDouble(input))
        {
            clearArea(37,19,44,1);
            gotoxy(45,19);setColor(4);cout << "Please enter a valid amount."<<flush;
            Sleep(2000);
            menu();
        }

        double amount = stod(input);

        if(input.find('.') != -1 && input.length() - input.find('.') - 1 > 2)
        {
            clearArea(37,19,44,1);
            gotoxy(39,19);setColor(4);cout << "Only Amounts with two decimals allowed!"<<flush;
            Sleep(2000);
            menu();
        }else if (amount > L.account[accIndex].balance)
        {
            clearArea(37,19,44,1);
            gotoxy(50,19);setColor(4);cout << "Insufficient funds!"<<flush;
            Sleep(2000);
            menu();
        }else if(L.account[accIndex].balance - amount < maintainingBalance)
        {
            clearArea(37,19,44,1);
            gotoxy(47,19); setColor(4);cout << "Below Maintaining Balance!" << flush;
            Sleep(2000);
            menu();
        }

        proceed();
        checkAtm_at_transac();
        L.account[accIndex].balance -= amount;
        L.account[recipientIndex].balance += amount;
        savefile(L.account[accIndex]);
        clearArea(33,7,53,16); createBox(35,9,50,11,7); createBox(38,10,44,3,7); createBox(38,13,44,3,7); createBox(38,16,44,3,7);
        gotoxy(48,11);setColor(2);cout << "Fund Transfer Successful" << flush;
        gotoxy(40,14); setColor(6);cout << "New Balance: Php " << L.account[accIndex].balance << flush;
        gotoxy(55,17); setColor(4); cout << "REMOVE ATM" << flush;
        while(atmIsRemoved()==false);
        checkPinfile();


    }
    else
    {
        gotoxy(50,19); setColor(4); cout << "Recipient not found" << flush;
        Sleep(2000);
        menu();
    }
}

bool TransactionModule::recipient_finder(string name, string accNum)
{
    int i;
    for (i = 0; i <= L.Last; i++)
    {
        if(L.account[i].accountNumber == accNum && L.account[i].accountName == name)
        {
            recipientIndex = i;
            return true;
        }
    }
    return false;
}

string TransactionModule::encrypt(string p)
{
    char pin[p.length() + 1];
    strcpy(pin,p.c_str());
    for(int i = 0; i < p.length(); i++)
    {
        pin[i] = pin[i] + KEY;
    }

    return string(pin);
}

string TransactionModule::decrypt(string p)
{
    char pin[p.length() + 1];
    strcpy(pin,p.c_str());
    for(int i = 0; i < p.length(); i++)
    {
        pin[i] = pin[i] - KEY;
    }

    return string(pin);
}

void TransactionModule::proceed()
{
    char choice;
    createBox(40,11,40,8,7);
    gotoxy(45,14);setColor(6);cout << "Proceed with the Transaction?" << flush;
    gotoxy(53,15);setColor(6);cout << "[Y]es || [N]o" << flush;
    do
    {
       choice = getch();
       choice = toupper(choice);
    }while(choice != 'N' && choice != 'Y');

    if(choice == 'N')
    {
        menu();
    }

}


void TransactionModule::retrievefile()
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
            AccDetails >> d.accountNumber >> d.balance >> d.contactNumber >> d.birthday >> d.pinCode;
            d.pinCode = decrypt(d.pinCode);
            addAccount(d);
            strline++;
        }

    }

    fileptr.close();
    cout << flush;
}

bool TransactionModule::atmIsRemoved()
{
    struct stat sb;
    return(stat("D:/", &sb) != 0);
}

void TransactionModule::checkAtm_at_transac()
{
    if(atmIsRemoved())
    {
        createBox(34,11,51, 7,7);
        gotoxy(40,14);setColor(4);cout <<"Your ATM was removed during transaction" << flush;
        Sleep(2000);
        checkPinfile();
    }
}

void TransactionModule::checkPinfile()
{
    changePinFlag = false;
    clearArea(5,3,110,24);
    createBox(37, 10, 45, 9, 7);
    logo();
    gotoxy(54,14);setColor(6);cout << "INSERT ATM" << flush;
    string line;
    string accNum;
    string accPin;
    ifstream fileptr;

    do
    {
        fileptr.open(pinPath);
    }
    while(fileptr.fail());
    fileptr >> accNum >> accPin;
    clearArea(5,3,110,24);
    if(account_checker(accNum, decrypt(accPin)))
    {
        fileptr.close();
        validateUser();
        menu();

    }
    else
    {
        clearArea(54,14,10,1);
        createBox(37, 10, 45, 9, 7);
        gotoxy(43,13);setColor(4);cout << "We have no record of your Account\n" << flush;
        gotoxy(50,15);setColor(6);cout << "Please REMOVE ATM\n" << flush;
        fileptr.close();
        while(atmIsRemoved()==false);
        checkPinfile();
    }

}

void TransactionModule::menu()
{
    bool fundTransferFlag = false;
    char temp,choice;
    int i = 0;
    clearArea(5,3,110,24);
    createBox(36, 6 , 47, 18, 6);
    gotoxy(55,9);setColor(1);cout << "ATM MENU\n" << flush;
    gotoxy(48,11);setColor(15);cout << "[1] Balance Inquiry\n" <<  flush;
    gotoxy(48,12);setColor(15);cout << "[2] Withdraw\n" <<  flush;
    gotoxy(48,13);setColor(15);cout << "[3] Deposit\n" <<  flush;
    gotoxy(48,14);setColor(15);cout << "[4] Fund Transfer\n" <<  flush;
    gotoxy(48,15);setColor(15);cout << "[5] Change PIN Code\n" <<  flush;
    gotoxy(48,16);setColor(15);cout << "[6] Exit\n" <<  flush;
    createBox(48, 19, 22, 3, 7);
    gotoxy (50, 20);setColor(10);cout << "Enter choice: " << flush;

    showcursor();
    do
    {
        temp = getch();
        if(isdigit(temp) && i == 0)
        {
            choice = temp;
            putch(choice);
            i++;
        }else if(temp == 8 && i == 1)
        {
            cout << "\b \b" << flush;
            i--;
        }
    }while(i < 0 || temp != 13);
    hidecursor();

    checkAtm_at_transac();

    switch (choice)
    {
    case '1':
        checkAtm_at_transac();
        balanceInquiry();
        break;
    case '2':
        withdraw();
        break;
    case '3':
        deposit();
        break;
    case '4':
        fundTransfer();
        break;
    case '5':
        changePinCode();
        break;
    case '6':
        checkAtm_at_transac();
        createBox(45, 19, 29, 3, 7);
        gotoxy(48,20);setColor(10);cout << "Transaction Complete..." << flush;
        Sleep(2000);
        gotoxy(48, 20);setColor(6);cout << "Please remove your card" << flush;
        while(atmIsRemoved()==false);
        checkPinfile();
        break;
    default:
        checkAtm_at_transac();
        createBox(43, 19, 33, 3, 7);
        gotoxy(52,20);setColor(4);cout << "Invalid choice!"<< flush;
        Sleep(2000);
        gotoxy(45,20);setColor(6);cout << "Please select a valid option." << flush;
        Sleep(2000);
        menu();//recursion
        break;
    }

}

bool TransactionModule::stringIsdigit(const string& input)
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


int main()
{
    ios::sync_with_stdio(false);
    hidecursor();
    createBox(1,1,118, 28, 1);
    createBox(3, 2, 114, 26, 6);
    clearArea(5,3,110,24);
    cout.unsetf(ios::floatfield);
    cout << fixed << setprecision(2) << flush;
    TransactionModule T;
    T.retrievefile();
    T.checkPinfile();


}

