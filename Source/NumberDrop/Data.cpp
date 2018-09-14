#include "NuDro.h"

int Read_Key()
{
	switch (getch())
	{
	case 13: return Enter;
	case 27: return Esc;
	case 'm': case 'M':
		return Mute;
	case 224:
		switch (getch())
		{
		case 72: return Up;
		case 75: return Left;
		case 77: return Right;
		case 80: return Down;
		}
	case 48: return 0;
	case 49: return 1;
	case 50: return 2;
	case 51: return 3;
	case 52: return 4;
	case 53: return 5;
	case 54: return 6;
	case 55: return 7;
	case 56: return 8;
	case 57: return 9;
	default: return -1;
	}
}

void gotoxy(int x, int y) //Dịch chuyển con trỏ đến vị trí (x,y) trên màn hình console
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

bool checkPos(Number *Num, int count, int pos) //Kiểm tra tọa độ x của các số trong mảng (n số) xem có bị trùng nhau hay không
{
	for (int i = 0; i < count; i++)
	{
		if (i != pos && Num[i].posX != 0)
		{
			if (Num[pos].posX == Num[i].posX)
				return true;
		}
	}
	return false;
}

void IntToString(int x, char str[]) //Chuyển số thành chuỗi (theo thứ tự ngược lại)
{
	int i = 0;
	if (x == 0)
	{
		str[0] = '0';
		str[1] = NULL;
	}
	else
	{
		while (x)
		{
			str[i] = x % 10 + '0';
			x = x / 10;
			i++;
		}
		str[i] = NULL;
	}
}

int CharToInt(char ch) //Chuyển kí tự thành chữ số
{
	int num = 0;
	if (ch >= '0' && ch <= '9')
		num = num * 10 + ch - '0';
	return num;
}

int randomPosX(int sizeX)
{
	//return (1 + rand() % (sizeX / 3 - 2)) * 3 + 1; //90 => +1
	return (1 + rand() % (sizeX / 3 - 2)) * 3 + 2;   //89 => +2
}