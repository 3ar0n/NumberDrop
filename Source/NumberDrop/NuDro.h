#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

typedef struct Number * nb;
struct Number
{
	int key;
	int color;
	int posX;
	int posY;
};

typedef struct menu * opt;
struct menu
{
	int value;
	char text[255];
	opt next;
	opt prev;
};

#define mDelay 60

//WindowsSize
#define DefaultSizeX 89
#define DefaultSizeY 40

//key
#define Up 22472
#define Left 22475
#define Right 22477
#define Down 22480
#define Enter 13
#define Esc 27
#define New 78
#define Hint 72
#define Clear 67
#define Erase 69
#define Check 75
#define Mute 77

//color
#define Black 0
#define Blue_D 1
#define Green_D 2
#define Cyan_D 3
#define Red_D 4
#define Pink_D 5
#define Yellow_D 6
#define White_D 7
#define Grey 8
#define Blue 9
#define Green 10
#define Cyan 11
#define Red 12
#define Pink 13
#define Yellow 14
#define White 15

//Data.cpp
int Read_Key();
void gotoxy(int x, int y);
bool checkPos(Number *Num, int count, int pos);
void IntToString(int x, char str[]);
int CharToInt(char ch);
int randomPosX(int sizeX);

//Graphic.cpp
void SetColor(int Text = White, int Background = Black);
void SetWindowsSize(int x = 80, int y = 25);
void putNumber(int key, int Color, int x, int y);
void putBorder(int x, int y, int width, int height, int Color, bool inner = false);
int ColorByNumber(int number);

//Main.cpp
void showScore(int Point);
void Game(int sizeX, int sizeY, int *Point);

//StartScreen.cpp
void CreateMenu(opt *head);
int Select(opt head, int x, int y, bool saved);

//Encrypt
void Create_Code(int Point, char Str[]);