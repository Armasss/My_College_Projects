#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "background.h"
#define MIN 500000
#define MAX 1000000000
#define TRUE 1
#define FALSE 0
#define MONTH 5

void allocate(double *allocatedbudget, char name[30]);
void sort(double expenses[], double highest, double lowest);
void expenses(double *dailyexpenses, double allocatedbudget, double remainingbudget, char name[30], int day);
void budgetallocation(void);
void remcomputation(int);
int addentry();
void login(void);
void viewSummary(void);
void menu(void);
void loading1(void);
void loading2(void);

typedef struct{
    char name[30];
    double dailyexpenses[MONTH];
    double allocatedbudget;
    double remainingbudget;
    double highestex;
    double lowestex;
    double total;
}Expenses;

Expenses BM = {.name = "Building Maintenance"};
Expenses U = {.name = "Utilities"};
Expenses AE = {.name = "Administrative Expenses"};
Expenses EF = {.name = "Equipment and Furinitures"};
Expenses GL = {.name = "Groundskeeping and Landscaping"};
Expenses TI = {.name = "Technology Infrastructure"};

int main()
{
    system ("COLOR F0");
    loading1();
    Sleep(1500);
    system("cls");
    bg();
    login();
    budgetallocation();
    menu();
}

void remcomputation(int day)
{
    BM.remainingbudget -= BM.dailyexpenses[day];
    U.remainingbudget -= U.dailyexpenses[day];
    AE.remainingbudget -= AE.dailyexpenses[day];
    EF.remainingbudget -= EF.dailyexpenses[day];
    GL.remainingbudget -= GL.dailyexpenses[day];
    TI.remainingbudget -= TI.dailyexpenses[day];

}

void expenses(double *dailyexpenses, double allocatedbudget, double remainingbudget, char name[30], int day)
{
    if(remainingbudget == 0){
        gotoxy(35, 28);
        printf(RED"Budget has been depleted/No entered budget amount."NORMAL);
        getch();
        return;
    }
    system("cls");
    bg();
    gotoxy(53, 9);
    printf("DAY %i", day+1);
    gotoxy(5, 10);
    puts(name);
    gotoxy(5, 11);
    printf("ALLOCATED BUDGET: PHP %2.lf || REMAINING BUDGET: PHP %.2lf", allocatedbudget, remainingbudget);
    gotoxy(5, 13);
    printf("Amount: ");
    scanf("%lf", dailyexpenses);

    while (*dailyexpenses < 0 || *dailyexpenses > remainingbudget)
    {
        system("cls");
        bg();
        gotoxy(53, 9);
        printf("DAY %i", day+1);
        gotoxy(5, 10);
        puts(name);
        gotoxy(5, 11);
        printf("ALLOCATED BUDGET: PHP %2.lf || REMAINING BUDGET: PHP %.2lf", allocatedbudget, remainingbudget);
        gotoxy(5, 11);
        printf(RED"Expense amount cannot be less than 0 or greater than the remaining budget"NORMAL);
        gotoxy(5, 13);
        printf("Enter New Amount: ");
        scanf("%lf", dailyexpenses);
    }
}

void allocate(double *allocatedbudget, char name[30]) {

    system("cls");
    bg();
    gotoxy(49, 9);
    printf("BUDGET ALLOCATION");
    gotoxy(46, 11);
    puts(name);
    gotoxy(21, 13);
    printf("Minimum Required Budget: %sPHP 500,000%s || Maximum Allocated Budget: PHP 1,000,000,000", RED,NORMAL);
    gotoxy(21, 15);
    printf("*Do not put space between numbers. e.g. 1000");
    gotoxy(46, 17);
    printf("Enter Allocated Budget: ");
    scanf("%lf", allocatedbudget);

    while (*allocatedbudget < MIN || *allocatedbudget > MAX) {
        system("cls");
        bg();
        gotoxy(49, 9);
        printf("BUDGET ALLOCATION");
        gotoxy(46, 11);
        puts(name);
        gotoxy(21, 13);
        printf("Minimum Required Budget: %sPHP 500,000%s || Maximum Allocated Budget: PHP 1,000,000,000", RED,NORMAL);
        gotoxy(21, 15);
        printf(RED"*Do not put space between numbers. e.g. 1000"NORMAL);
        gotoxy(21, 16);
        printf(RED"*Please follow the Minimum and Maximum Budget."NORMAL);
        gotoxy(46, 18);
        printf("Enter New Allocated Budget: ");
        scanf("%lf", allocatedbudget);
    }
}

int addentry(int day)
{
    int choice;

    do
    {
        system("cls");
        bg();

        if(day > MONTH-1)
        {
            gotoxy(25, 12);
            printf("%sYou have completed entering all the data %s%c%s\n\n\n\n", GREEN4, RED, 3, NORMAL);
            system("pause");
            return day;
        }
        gotoxy(48, 9);
        printf("ADD/EDIT EXPENSE");
        gotoxy(53, 10);
        printf("DAY %i", day+1);
        gotoxy(30, 12);
        printf("*Choose expense category and input the expense amount.");
        gotoxy(6, 14);
        printf("[1] BUILDING MAINTENANCE");
        gotoxy(6, 15);
        printf("BUDGET: PHP %.2lf", BM.remainingbudget - BM.dailyexpenses[day]);
        gotoxy(6, 16);
        printf("EXPENSE: PHP %.2lf", BM.dailyexpenses[day]);
        gotoxy(48, 14);
        printf("[2] UTILITIES");
        gotoxy(48, 15);
        printf("BUDGET: PHP %.2lf", U.remainingbudget - U.dailyexpenses[day]);
        gotoxy(48, 16);
        printf("EXPENSE: PHP %.2lf", U.dailyexpenses[day]);
        gotoxy(82, 14);
        printf("[3] ADMINISTRATIVE EXPENSES");
        gotoxy(82, 15);
        printf("BUDGET: PHP %.2lf", AE.remainingbudget - AE.dailyexpenses[day]);
        gotoxy(82, 16);
        printf("EXPENSE: PHP %.2lf", AE.dailyexpenses[day]);
        gotoxy(6, 18);
        printf("[4] EQUIPMENT AND FURNITURES");
        gotoxy(6, 19);
        printf("BUDGET: PHP %.2lf", EF.remainingbudget - EF.dailyexpenses[day]);
        gotoxy(6, 20);
        printf("EXPENSE: PHP %.2lf", EF.dailyexpenses[day]);
        gotoxy(40, 18);
        printf("[5] GROUNDSKEEPING AND LANDSCAPING");
        gotoxy(40, 19);
        printf("BUDGET: PHP %.2lf", GL.remainingbudget - GL.dailyexpenses[day]);
        gotoxy(40, 20);
        printf("EXPENSE: PHP %.2lf", GL.dailyexpenses[day]);
        gotoxy(82, 18);
        printf("[6] TECHNOLOGY INFRASTRUCTURE");
        gotoxy(82, 19);
        printf("BUDGET: PHP %.2lf", TI.remainingbudget - TI.dailyexpenses[day]);
        gotoxy(82, 20);
        printf("EXPENSE: PHP %.2lf", TI.dailyexpenses[day]);
        gotoxy(30, 23);
        printf("[7] Save and proceed to next day");
        gotoxy(75, 23);
        printf("[8] Return to Main Menu");

        if(day == MONTH-1)
            {
                gotoxy(48, 10);
                printf("FINAL DAY [%i]", day+1);
                gotoxy(30, 23);
                printf(RED"[7] Save entered expenses       "NORMAL);
            }


        gotoxy(48, 26);
        printf("Enter Choice: ");
        scanf ("%i", &choice);

        switch(choice)
        {
            case 1: expenses(&BM.dailyexpenses[day], BM.allocatedbudget, BM.remainingbudget, BM.name, day); break;
            case 2: expenses(&U.dailyexpenses[day], U.allocatedbudget, U.remainingbudget, U.name, day); break;
            case 3: expenses(&AE.dailyexpenses[day], AE.allocatedbudget, AE.remainingbudget, AE.name, day); break;
            case 4: expenses(&EF.dailyexpenses[day], EF.allocatedbudget, EF.remainingbudget, EF.name, day); break;
            case 5: expenses(&GL.dailyexpenses[day], GL.allocatedbudget, GL.remainingbudget, GL.name, day); break;
            case 6: expenses(&TI.dailyexpenses[day], TI.allocatedbudget, TI.remainingbudget, TI.name, day); break;
            case 7: remcomputation(day); day ++;
        }

    }while(choice!=8);
    return day;
}

void menu()
{
    int choice, day=0;

    do
    {
        system("cls");
        bg();
        gotoxy(48,9);
        printf("MAIN MENU || DAY %i", day+1);
        gotoxy(41,11);
        printf("Please enter the correct characters");
        gotoxy(47,14);
        printf("[1] Add Entry");
        gotoxy(47,16);
        printf("[2] View Summary/Expense Breakdown");
        gotoxy(47,18);
        printf("[3] Exit");

        if (day > MONTH-1)
        {
            gotoxy(45,9);
            printf("MAIN MENU || %sCOMPLETED%s", GREEN4,NORMAL);
            gotoxy(47,14);
            printf(RED"[1] Add Entry"NORMAL);
        }

        gotoxy(47,23);
        printf("Enter your choice: ");
        scanf("%i", &choice);


        switch(choice)
        {
            case 1: day = addentry(day); break;
            case 2: viewSummary(); break;
            case 3: system("cls"); printf("\n\t\t\t\t\t\tSee you next time %s%c%s\n\n\n",RED, 3, NORMAL); break;
            default: printf("\n\n\t\t\t\t\t      %sChose only from 0 to 4%s",RED, NORMAL); printf("\n\n\t\t\t\t             Press any key to continue..."); getch();
        }
    }while(choice != 3);
}

void budgetallocation()
{
    float totalbudget;
    int choice, check = FALSE;

    do {
        system("cls");
        bg();
        gotoxy(47, 9);
        printf("BUDGET ALLOCATION");
        gotoxy(27, 11);
        printf("*Choose a category and enter the budget within the requirements.");
        gotoxy(6, 14);
        printf("[1] BUILDING MAINTENANCE");
        gotoxy(6, 15);
        printf("BUDGET: PHP %.2lf", BM.allocatedbudget);
        gotoxy(48, 14);
        printf("[2] UTILITIES");
        gotoxy(48, 15);
        printf("BUDGET: PHP %.2lf", U.allocatedbudget);
        gotoxy(82, 14);
        printf("[3] ADMINISTRATIVE EXPENSES");
        gotoxy(82, 15);
        printf("BUDGET: PHP %.2lf", AE.allocatedbudget);
        gotoxy(6, 18);
        printf("[4] EQUIPMENT AND FURNITURES");
        gotoxy(6, 19);
        printf("BUDGET: PHP %.2lf", EF.allocatedbudget);
        gotoxy(40, 18);
        printf("[5] GROUNDSKEEPING AND LANDSCAPING");
        gotoxy(40, 19);
        printf("BUDGET: PHP %.2lf", GL.allocatedbudget);
        gotoxy(82, 18);
        printf("[6] TECHNOLOGY INFRASTRUCTURE");
        gotoxy(82, 19);
        printf("BUDGET: PHP %.2lf", TI.allocatedbudget);
        gotoxy(40, 23);
        printf("[7] Proceed with the allocated budgets");
        gotoxy(48, 26);
        printf("Enter Choice: ");
        scanf("%i", &choice);


        switch (choice)
        {
            case 1: allocate(&BM.allocatedbudget, BM.name); BM.remainingbudget = BM.allocatedbudget;  break;
            case 2: allocate(&U.allocatedbudget, U.name); U.remainingbudget = U.allocatedbudget; break;
            case 3: allocate(&AE.allocatedbudget, AE.name); AE.remainingbudget = AE.allocatedbudget; break;
            case 4: allocate(&EF.allocatedbudget, EF.name); EF.remainingbudget = EF.allocatedbudget; break;
            case 5: allocate(&GL.allocatedbudget, GL.name); GL.remainingbudget = GL.allocatedbudget;  break;
            case 6: allocate(&TI.allocatedbudget, TI.name); TI.remainingbudget = TI.allocatedbudget; break;
            case 7:
                if(BM.allocatedbudget == 0  || U.allocatedbudget == 0 || AE.allocatedbudget == 0 || EF.allocatedbudget == 0 || GL.allocatedbudget == 0 || TI.allocatedbudget == 0){
                 gotoxy(36, 28); printf(RED"Cannnot proceed while categories have no allocated  budget"NORMAL); getch(); break;
                }else check = TRUE;
                gotoxy(39, 28); printf(GREEN4"Allocated Budget entered successfully."NORMAL); getch(); break;
            default: gotoxy(36, 28); printf(RED"Choice entered is out of range. Try again."NORMAL); getch();
        }

    } while (choice != 7 || check != TRUE);

    totalbudget = BM.allocatedbudget + U.allocatedbudget + AE.allocatedbudget + EF.allocatedbudget + GL.allocatedbudget + TI.allocatedbudget;
}

void login()
{
    char username[30];
    char password[30];

    gotoxy(50,9);
    printf("LOGIN");

    gotoxy(45,12);
    printf("Enter username: ");
    scanf("%s", username);
    gotoxy(45,14);
    printf("Enter password: ");
    scanf("%s", password);

    // Check username and password
    if (strcmp(username, "admin")+1 == TRUE && strcmp(password, "pass")+1 == TRUE) {
        loading2();
        return;
    } else {
        gotoxy(35,17);
        printf(RED"Invalid username or password. Exiting program.\n\n"NORMAL);
        exit(0);
    }
}

void loading1()
{
    system("cls");
    bbg();
    gotoxy(47,10);
    printf("Loading.... Please wait\n");
    printf("\n\t\t\t\t   ");


    for(int i = 1; i <= 50; i++)
    {
        printf("%s%c%s", GREEN4, 176, NORMAL);
    }

    printf("\r");
    printf("\t\t\t\t   ");

    for(int i = 1; i <= 50; i++)
    {
        Sleep(30);
        printf("%s%c%s", GREEN4, 219, NORMAL);
    }
    printf("\n\n\t\t\t\t\t    Successfully Loaded. Welcome %s%c%s",RED,3,NORMAL);
}

void loading2(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tLoading");
    for(int i =0; i <= 6; i++){
        Sleep(300);
        printf(".");
    }
}

void sort(double expenses[], double highest, double lowest)
{
    lowest = expenses[0];
    highest = expenses[0];

    for(int i = 0; i < 30; i++){

        if(lowest > expenses[i])
        {
            lowest = expenses[i];
        }

        if(highest < expenses[i])
        {
            highest = expenses[i];
        }
    }

    printf("\nLARGEST NUMBER: %lf\n", BM.highestex);
    printf("SMALLEST NUMBER: %lf", BM.lowestex);

}

void viewSummary() {
    system("cls");
    bg();

    printf("\n\n\t\t\t\t\t         SUMMARY\n\n");

    Expenses expenses[] = {BM, U, AE, EF, GL, TI};
    int numExpenses = sizeof(expenses) / sizeof(expenses[0]);

    double totalExpenses = 0.0;
    double totalAllocatedBudget = 0.0;

    double largestExpense = expenses[0].allocatedbudget - expenses[0].remainingbudget;
    double smallestExpense = expenses[0].allocatedbudget - expenses[0].remainingbudget;
    int largestIndex = 0, smallestIndex = 0;

    for (int i = 0; i < numExpenses; i++) {
        double enteredExpenses = expenses[i].allocatedbudget - expenses[i].remainingbudget;
        double totalBudget = expenses[i].allocatedbudget;

        printf("\t\t\t\t%-35s: PHP %.2lf\n", expenses[i].name, totalBudget);
        printf("\t\t\t\t   Total Expenses: PHP %.2lf\n", enteredExpenses);
        printf("\t\t\t\t   Total Budget: PHP %.2lf\n", totalBudget - enteredExpenses);

        totalExpenses += enteredExpenses;
        totalAllocatedBudget += totalBudget;

        if (enteredExpenses > largestExpense) {
            largestExpense = enteredExpenses;
            largestIndex = i;
        }

        if (enteredExpenses < smallestExpense || i == 0) {
            smallestExpense = enteredExpenses;
            smallestIndex = i;
        }

        printf("\n");
    }

    double remainingBudget = totalAllocatedBudget - totalExpenses;
    printf("\n\t\t\t\t >> Total Budget: (All Categories) PHP %.2lf\n", totalAllocatedBudget);
    printf("\t\t\t\t >> Total Expenses: (All Categories) PHP %.2lf\n", totalExpenses);
    printf("\t\t\t\t >> Remaining Budget: (All Categories) PHP %.2lf\n", remainingBudget);

    printf("\n\n\t\t\t\t >> Largest Expense: (%s) PHP %.2lf\n", expenses[largestIndex].name, largestExpense);
    printf("\t\t\t\t >> Smallest Expense: (%s) PHP %.2lf\n", expenses[smallestIndex].name, smallestExpense);

    printf("\n\n");

    system("pause");
}
