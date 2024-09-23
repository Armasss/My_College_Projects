#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 23
#define TRUE 1
#define FALSE 0
#define LIVES 3
#define DEFAULTPOSITION 20
#define ENEMY_COUNT 60
#define MAX_BULLET 5

int IncreaseScore();
int MaxBullet();
int BottomEnemyCheck(int bomb_x, int y);
int BombHit();
int EnemyWallCheck();
void OpeningScreen();
void LoadingScreen();
void UpdateFrame();
void PrintBoard();
void CopyDefaultWorld();
void BulletMovement();
void EraseBullet();
void BulletHit();
void RemoveDebris();
void DropBomb(int bomb_x);
void BombMovement();
void EraseBomb();
void EnemyMovement();
void EnemyMoveDown();

int x, y, dy, i, bullet_count, game_on_flag = TRUE;
char retry;

typedef struct {
	char world[HEIGHT][WIDTH+1];
	int heroposition, lives;
	int score;
}SPACEINVADERS;

char defaultworld[HEIGHT][WIDTH+1] = {
        "*                                      *",
		"*    M M M M M M M M M M M M M M M     *",
		"*    M M M M M M M M M M M M M M M     *",
		"*    M M M M M M M M M M M M M M M     *",
		"*    M M M M M M M M M M M M M M M     *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                   A                  *",
		"****************************************"};
SPACEINVADERS SI = (SPACEINVADERS){{{0}}, DEFAULTPOSITION, LIVES, 0};

void MoveCursorToXY(int x, int y) {
	COORD coord = (COORD){x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void LoadingScreen()
{
	MoveCursorToXY(36, 14);
	printf("Loading...");
	MoveCursorToXY(30, 15);

	for(i = 1; i <= 20; i++){
		Sleep(100);
		printf("%c", 178);
	}
	system("cls");
}
void OpeningScreen() {
	system("cls");
	printf( "Welcome to the mini Space Invaders game!"
			"\n\n\nGame instructions:"
			"\n\n-> Use left and right arrow keys to move the hero, up arrow key to shoot bullets. There can be a maximum of %d bullets on the screen at once."
			"\n\n-> As the hero, your mission is to stop aliens from invading the Earth. For every invader you kill, your score will increase by 10 points. Kill all invaders to save the Earth and win the game."
			"\n\n-> Here you are provided with %d lives. Your lives will decrease as invaders manage to bomb and kill you."
			"\n\n-> You can pause the game in its middle by pressing the P key. To continue the paused game press P once again."
			"\n\n-> If you want to exit the game at any point press Esc (you will lose all progress)."
			"\n\n\nPress any key to play the game...", MAX_BULLET, LIVES);
			getch();

	system("cls");
}

void CopyDefaultWorld()
{
	for(y = 0; y < HEIGHT; y++){
		for(x = 0; x < WIDTH + 1; x++){
			SI.world[y][x] = defaultworld[y][x];
		}
	}
}
void PrintBoard()
{
    MoveCursorToXY(36, 3);
	printf("SCORE: %i     LIVES: %i", SI.score, SI.lives);
    for(y=0;y<HEIGHT;y++){
       MoveCursorToXY(36, 4 + y);
       printf("%s\n",SI.world[y]);
   }
}
int MaxBullet()
{
    bullet_count = 0;
	for(y = HEIGHT - 3; y > 0; y--){
		for(x = 1; x < WIDTH - 1; x++){
			if(SI.world[y][x] == '^'){
				if(++bullet_count >= MAX_BULLET){
					return FALSE;
				}
			}
		}
	}
	return TRUE;
}
void BulletMovement()
{
	for(y = 2; y < HEIGHT - 2; y++){
		for(x = 0; x < WIDTH; x++){
			if(SI.world[y][x] == '^'){
				SI.world[y-1][x] = '^';
				SI.world[y][x] = ' ';
			}
		}
	}
}

void BulletHit()
{
	for(y = 1; y < HEIGHT - 2; y++){
		for(x = 1; x < WIDTH - 1; x++){
			if(SI.world[y][x] == '^'){
				switch(SI.world[y-1][x]) {
					case 'U':
						SI.world[y-1][x] = 'X';
						SI.world[y][x] = ' ';
						break;
					case 'M':
						SI.world[y-1][x] = 'X';
						SI.world[y][x] = ' ';
						if(IncreaseScore())
							return;
				}
			}
		}
	}
}

void EraseBullet()
{
    for(x = 1; x < WIDTH - 1; x++){
		if(SI.world[1][x] == '^'){
			SI.world[1][x] = ' ';
		}
    }
}

void BombMovement()
{
	for(y = HEIGHT - 3; y > 1; y--){
		for(x = 1; x < WIDTH - 1; x++){
			if(SI.world[y][x] == 'U'){
				SI.world[y][x] = ' ';
				if(SI.world[y + 1][x] != 'M'){
					SI.world[y+1][x] = 'U';
				}
			}
		}
	}
}
void EraseBomb()
{
	for(x = 1; x < WIDTH - 1; x++){
		if(SI.world[HEIGHT-2][x] == 'U')
			SI.world[HEIGHT-2][x] = ' ';
	}
}
void RemoveDebris()
{
	for(y = 1; y < HEIGHT - 1; y++){
		for(x = 1; x < WIDTH-1; x++){
			if(SI.world[y][x] == 'X'){
				SI.world[y][x] = ' ';
			}
		}
	}
}
void DropBomb(int bomb_x)
{

	for(y = 1; y < HEIGHT - 4; y++){
		if(rand()%8 && SI.world[y][bomb_x] == 'M'){
			for(dy = 1; dy < 7; dy++){
				if(BottomEnemyCheck(bomb_x, y+dy)){
					break;
				}
			}
        }
    }
}

int BottomEnemyCheck(int bomb_x, int y)
{
	for(x = bomb_x - 2; x < bomb_x + 3; x++){
		if(SI.world[y][x] == 'M'){
			return FALSE;
        }
	}
	SI.world[y][bomb_x] = 'U';
	return TRUE;
}

int BombHit()
{
    switch(SI.world[HEIGHT - 3][SI.heroposition])
    {
        case 'U':
            SI.lives--;
            SI.world[HEIGHT - 3][SI.heroposition] = ' ';
            SI.world[HEIGHT - 2][SI.heroposition] = 'X';
            return TRUE;
        case 'M':
            SI.lives--;
            SI.world[HEIGHT - 3][SI.heroposition] = ' ';
            SI.world[HEIGHT - 2][SI.heroposition] = 'X';
            if(IncreaseScore()){
                return FALSE;
            }
            return TRUE;
    }
	return FALSE;
}

int EnemyWallCheck()
{
	for(y = 1; y < HEIGHT - 1; y++){
		if(SI.world[y][1] == 'M' || SI.world[y][WIDTH-2] == 'M'){
			return TRUE;
		}
	}
	return FALSE;
}
void EnemyMovement()
{
	static int move_left_flag = FALSE;
	if(move_left_flag){
		for(y = 1; y < HEIGHT - 1; y++){
			for(x = 1; x < WIDTH - 1; x++){
				if(SI.world[y][x] == 'M') {
					SI.world[y][x] = ' ';
					SI.world[y][x-1] = 'M';
				}
			}
		}
	}
	else{
        for(y = 1; y < HEIGHT - 1; y++){
			for(x = WIDTH - 2; x > 0; x--){
				if(SI.world[y][x] == 'M'){
					SI.world[y][x] = ' ';
					SI.world[y][x+1] = 'M';
				}
			}
        }
	}
	if(EnemyWallCheck()){
		move_left_flag = !move_left_flag;
		EnemyMoveDown();
		for(x = 1; x < WIDTH  - 1; x++){
			if(SI.world[HEIGHT-2][x] == 'M'){
				game_on_flag = FALSE;
				PrintBoard();
				MoveCursorToXY(36, 5 + HEIGHT);
				printf("Invaders have invaded the Earth.");
				MoveCursorToXY(36, 6 + HEIGHT);
				printf("Mission failed. We'll get 'em next time...");
				MoveCursorToXY(36, 7 + HEIGHT);
				printf("(Press C to continue...)");
				getch();
				system("cls");
				return;
			}
		}
	}
}
void EnemyMoveDown()
{
	for(y = HEIGHT - 3; y > 0; y--){
		for(x = 1; x < WIDTH - 1; x++){
			if(SI.world[y][x] == 'M') {
				SI.world[y][x] = ' ';
				SI.world[y+1][x] = 'M';
			}
		}
	}
}
void UpdateFrame()
{
	for(i = 0; game_on_flag; i++){
		PrintBoard();
		Sleep(25);
		if(kbhit()) {
			char key = getch();
			switch(key) {
				case 'd':
					if(SI.heroposition < WIDTH - 2){
						SI.world[HEIGHT - 2][SI.heroposition] = ' ';
						SI.world[HEIGHT - 2][++SI.heroposition] = 'A';
					}
					break;
				case 'a':
					if(SI.heroposition > 1) {
						SI.world[HEIGHT - 2][SI.heroposition] = ' ';
						SI.world[HEIGHT - 2][--SI.heroposition] = 'A';
					}
					break;
				case 'h':
					if(MaxBullet())
						SI.world[HEIGHT - 3][SI.heroposition] = '^';
					break;
			}
		}
		RemoveDebris();
		EraseBomb();
		EraseBullet();
		if(BombHit()) {
			PrintBoard();
			if(!SI.lives) {
				game_on_flag = FALSE;
				MoveCursorToXY(36, 5 + HEIGHT);
				printf("Invaders killed you.");
				MoveCursorToXY(36, 6 + HEIGHT);
				printf("Mission failed. We'll get 'em next time...");
				MoveCursorToXY(36, 7 + HEIGHT);
				printf("(Press any key to continue...)");
				getch();
				system("cls");
				return;
			}
			Sleep(400);
			SI.world[HEIGHT-2][SI.heroposition] = 'A';
		}
		BulletHit();
		if(!(i%4)){
			BombMovement();
			BulletMovement();
		}
		if(!(i%4)){
			DropBomb(rand()%17 + 4);
        }
		if(!(i%12)){
			EnemyMovement();
        }
	}
}
int IncreaseScore()
{

	SI.score += 10;
	if(SI.score == 10*ENEMY_COUNT){
		game_on_flag = FALSE;
		PrintBoard();
		MoveCursorToXY(36, 5 + HEIGHT);
		printf("You saved the Earth from invaders.");
		MoveCursorToXY(36, 6 + HEIGHT);
		printf("CONGRATULATION! A WINRAR IS YOU!!!");
		MoveCursorToXY(36, 7 + HEIGHT);
		printf("(Press any key to continue...)");
		getch();
		system("cls");
		return TRUE;
	}
	return FALSE;

}
int main(){
 do
 {
    OpeningScreen();
    LoadingScreen();
    CopyDefaultWorld();
    PrintBoard();
    UpdateFrame();

    MoveCursorToXY(36, 14);
    printf("You scored: %i", SI.score);
    MoveCursorToXY(36, 15);
    printf("Do you want to try again?");
    MoveCursorToXY(36, 16);
    printf("[Y]es || [N]o");

    retry = getch();
    retry = toupper(retry);

    while(retry != 'Y' && retry != 'N'){
        system("cls");
        MoveCursorToXY(36, 14);
        printf("Please enter the correct character");
        MoveCursorToXY(36, 15);
        printf("Do you want to try again?");
        MoveCursorToXY(36, 16);
        printf("[Y]es || [N]o");
        retry = getch();
        retry = toupper(retry);
    }

    if(retry == 'N'){
        exit(0);
    }

    SI = (SPACEINVADERS){{{0}}, DEFAULTPOSITION, LIVES, 0};
    game_on_flag = TRUE;

 }while(retry == 'Y');

}

