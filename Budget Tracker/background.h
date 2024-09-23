#define GREEN "\x1b[48;5;151m"
#define GREEN2 "\x1b[48;5;108m"
#define GREEN3 "\x1b[32m"
#define GREEN4 "\x1b[38;5;22m"
#define RED "\x1b[31m"
#define NORMAL "\x1b[30m"

void gotoxy(int, int);
void bg();
void bbg();

void gotoxy(int x , int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void bbg()
{
    for(int i = 0; i < 30;i ++)
    {
        printf("%s                                                                                                                        \n", GREEN);
    }
}

void bg()
{
    bbg();
    gotoxy(10,1);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(9,2);
    printf("%c%c", 219,219);
    gotoxy(9,3);
    printf("%c%c", 219,219);
    gotoxy(9,4);
    printf("%c%c", 219,219);
    gotoxy(10,5);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);


    gotoxy(19,1);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(18,2);
    printf("%c%c", 219,219);
    gotoxy(18,3);
    printf("%c%c", 219,219);
    gotoxy(18,4);
    printf("%c%c", 219,219);
    gotoxy(18,5);
    printf("%c%c", 219,219);
    gotoxy(23,2);
    printf("%c%c", 219,219);
    gotoxy(23,3);
    printf("%c%c", 219,219);
    gotoxy(23,4);
    printf("%c%c", 219,219);
    gotoxy(23,5);
    printf("%c%c", 219,219);
    gotoxy(20,3);
    printf("%c%c%c", 219,219,219);

    gotoxy(27,1);
    printf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219);
    gotoxy(27,2);
    printf("%c%c", 219,219);
    gotoxy(27,3);
    printf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219);
    gotoxy(32,4);
    printf("%c%c", 219,219);
    gotoxy(27,5);
    printf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219);

    gotoxy(36,1);
    printf("%c%c", 219,219);
    gotoxy(36,2);
    printf("%c%c", 219,219);
    gotoxy(36,3);
    printf("%c%c", 219,219);
    gotoxy(36,4);
    printf("%c%c", 219,219);
    gotoxy(36,5);
    printf("%c%c", 219,219);
    gotoxy(38,3);
    printf("%c%c%c", 219,219,219);
    gotoxy(41,1);
    printf("%c%c", 219,219);
    gotoxy(41,2);
    printf("%c%c", 219,219);
    gotoxy(41,3);
    printf("%c%c", 219,219);
    gotoxy(41,4);
    printf("%c%c", 219,219);
    gotoxy(41,5);
    printf("%c%c", 219,219);

    gotoxy(50,1);
    printf("%c%c%c%c%c%c%c%c", 219,219,219,219,219,219,219,219);
    gotoxy(53,2);
    printf("%c%c", 219,219);
    gotoxy(53,3);
    printf("%c%c", 219,219);
    gotoxy(53,4);
    printf("%c%c", 219,219);
    gotoxy(53,5);
    printf("%c%c", 219,219);

    gotoxy(60,1);
    printf("%c%c%c%c%c%c", 219,219,219,219,219,219);
    gotoxy(60,2);
    printf("%c%c",219,219);
    gotoxy(65,2);
    printf("%c%c",219,219);
    gotoxy(60,3);
    printf("%c%c%c%c%c%c", 219,219,219,219,219,219);
    gotoxy(60,4);
    printf("%c%c", 219,219);
    gotoxy(65,4);
    printf("%c%c", 219,219);
    gotoxy(60,5);
    printf("%c%c", 219,219);
    gotoxy(65,5);
    printf("%c%c", 219,219);

    gotoxy(70,1);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(69,2);
    printf("%c%c", 219,219);
    gotoxy(69,3);
    printf("%c%c", 219,219);
    gotoxy(69,4);
    printf("%c%c", 219,219);
    gotoxy(69,5);
    printf("%c%c", 219,219);
    gotoxy(74,2);
    printf("%c%c", 219,219);
    gotoxy(74,3);
    printf("%c%c", 219,219);
    gotoxy(74,4);
    printf("%c%c", 219,219);
    gotoxy(74,5);
    printf("%c%c", 219,219);
    gotoxy(71,3);
    printf("%c%c%c", 219,219,219);

    gotoxy(79,1);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(78,2);
    printf("%c%c", 219,219);
    gotoxy(78,3);
    printf("%c%c", 219,219);
    gotoxy(78,4);
    printf("%c%c", 219,219);
    gotoxy(79,5);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);

    gotoxy(87,1);
    printf("%c%c", 219,219);
    gotoxy(87,2);
    printf("%c%c", 219,219);
    gotoxy(87,3);
    printf("%c%c", 219,219);
    gotoxy(87,4);
    printf("%c%c", 219,219);
    gotoxy(87,5);
    printf("%c%c", 219,219);
    gotoxy(92,1);
    printf("%c%c", 219,219);
    gotoxy(91,2);
    printf("%c%c", 219,219);
    gotoxy(89,3);
    printf("%c%c%c",219,219,219);
    gotoxy(91,4);
    printf("%c%c", 219,219);
    gotoxy(92,5);
    printf("%c%c", 219,219);

    gotoxy(103,1);
    printf("%c%c%c%c%c%c%c", 220,220,219,219,219,220,220);
    gotoxy(103,2);
    printf("%c%c", 219,219);
    gotoxy(103,3);
    printf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219);
    gotoxy(108,4);
    printf("%c%c", 219,219);
    gotoxy(103,5);
    printf("%c%c%c%c%c%c%c", 223,223,219,219,219,223,223);

    gotoxy(0,7);
    for(int i = 0; i < 120; i++)
    {
        gotoxy(i,7);
        printf("%c",205);
    }
}
