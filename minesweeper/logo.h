#define RED "\x1b[31m"
#define NORMAL "\x1b[30m"
#define WHITE "\x1b[38;5;255m"
#define FGREENBG "\x1b[48;5;151m"
#define BLUEBG "\x1b[48;5;153m"

void logo();
void gotoxy(int, int);

void logo()
{
    int i;

    /*background color*/
    for(i = 0; i < 20;i ++)
    {
        printf("%s                                                                                                                        \n", BLUEBG);
    }
    for(i = 0; i < 10;i ++)
    {
        printf("%s                                                                                                                        \n", FGREENBG);
    }

    /*clouds*/
    gotoxy(26,5);
    printf("%s%c%c%s",WHITE,219,219,NORMAL);
    gotoxy(24,6);
    for(i = 0; i < 7; i++)
    {
        printf("%s%c%s",WHITE,219,NORMAL);
    }
    gotoxy(20,7);
    for(i = 0; i < 13; i++)
    {
        printf("%s%c%s",WHITE,219,NORMAL);
    }

    gotoxy(110,3);
    for(i = 0; i < 5; i++)
    {
        printf("%s%c%s",WHITE,219,NORMAL);
    }
    gotoxy(100,4);
    for(i = 0; i < 20; i++)
    {
        printf("%s%c%s",WHITE,219,NORMAL);
    }
    gotoxy(90,5);
    for(i = 0; i < 30; i++)
    {
        printf("%s%c%s",WHITE,219,NORMAL);
    }

    /*flags*/
    gotoxy(26,17);
    printf("%s%c%s",RED,220,NORMAL);
    gotoxy(26,18);
    printf("%s%c%c%c%s",RED,219,219,220,NORMAL);
    gotoxy(26,19);
    printf("%s%c%c%c%c%s",RED,219,219,219,219,NORMAL);
    gotoxy(26,20);
    printf("%c",219);

    gotoxy(100,20);
    printf("%s%c%s",RED,220,NORMAL);
    gotoxy(100,21);
    printf("%s%c%c%c%s",RED,219,219,220,NORMAL);
    gotoxy(100,22);
    printf("%s%c%c%c%c%s",RED,219,219,219,219,NORMAL);
    gotoxy(100,23);
    printf("%c",219);

    gotoxy(50,23);
    printf("%s%c%s",RED,220,NORMAL);
    gotoxy(50,24);
    printf("%s%c%c%c%s",RED,219,219,220,NORMAL);
    gotoxy(50,25);
    printf("%s%c%c%c%c%s",RED,219,219,219,219,NORMAL);
    gotoxy(50,26);
    printf("%c",219);

    /*bombs*/
    gotoxy(80,25);
    for(i = 0; i < 5; i++)
    {
        printf("%c",219);
    }
    gotoxy(80,24);
    for(i = 0; i < 5; i++)
    {
        printf("%c",219);
    }
    gotoxy(82,23);
    printf("%c",221);
    gotoxy(82,22);
    printf("%s%c%s",RED,220,NORMAL);

    gotoxy(9,22);
    for(i = 0; i < 5; i++)
    {
        printf("%c",219);
    }
    gotoxy(9,21);
    for(i = 0; i < 5; i++)
    {
        printf("%c",219);
    }
    gotoxy(11,20);
    printf("%c",221);
    gotoxy(11,19);
    printf("%s%c%s",RED,220,NORMAL);
}

void gotoxy(int x , int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
