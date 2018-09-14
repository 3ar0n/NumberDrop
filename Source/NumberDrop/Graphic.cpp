#include "NuDro.h"

void SetColor(int Text, int Background) //Thiết lập màu chữ, màu nền
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Background * 16 + Text);
}

void SetWindowsSize(int x, int y) //Thiết lập kích thước cửa sổ console
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	wchar_t str[256] = L"Number Dr0p - by 3ar0n";
	SetConsoleTitle(str);

	SMALL_RECT windowSize = { 0, 0, x - 1, y - 1 };
	SetConsoleWindowInfo(hConsole, true, &windowSize);

	if (y == 25)
		y = 10;
	COORD bufferSize = { x, y };
	SetConsoleScreenBufferSize(hConsole, bufferSize);
}

void putNumber(int key, int Color, int x, int y) //"Vẽ" số và in lên màn hình với màu và vị trí nhất định
{
	SetColor(Color);

	switch (key)
	{
	case 0:
		gotoxy(x - 1, y - 1);	printf("%c%c%c", 201, 205, 187);
		gotoxy(x - 1, y);		printf("%c %c", 186, 186);
		gotoxy(x - 1, y + 1);	printf("%c%c%c", 200, 205, 188);
		break;
	case 1:
		gotoxy(x, y - 1);		printf("%c", 187);
		gotoxy(x, y);			printf("%c", 186);
		gotoxy(x, y + 1);		printf("%c", 202);
		break;
	case 2:
		gotoxy(x - 1, y - 1);	printf("%c%c%c", 205, 205, 187);
		gotoxy(x - 1, y);		printf("%c%c%c", 201, 205, 188);
		gotoxy(x - 1, y + 1);	printf("%c%c%c", 200, 205, 205);
		break;
	case 3:
		gotoxy(x - 1, y - 1);	printf("%c%c%c", 205, 205, 187);
		gotoxy(x, y);			printf("%c%c", 205, 185);
		gotoxy(x - 1, y + 1);	printf("%c%c%c", 205, 205, 188);
		break;
	case 4:
		gotoxy(x - 1, y - 1);	printf("%c %c", 183, 183);
		gotoxy(x - 1, y);		printf("%c%c%c", 200, 205, 185);
		gotoxy(x + 1, y + 1);	printf("%c", 186);
		break;
	case 5:
		gotoxy(x - 1, y - 1);	printf("%c%c%c", 201, 205, 205);
		gotoxy(x - 1, y);		printf("%c%c%c", 200, 205, 187);
		gotoxy(x - 1, y + 1);	printf("%c%c%c", 205, 205, 188);
		break;
	case 6:
		gotoxy(x - 1, y - 1);	printf("%c%c%c", 201, 205, 205);
		gotoxy(x - 1, y);		printf("%c%c%c", 204, 205, 187);
		gotoxy(x - 1, y + 1);	printf("%c%c%c", 200, 205, 188);
		break;
	case 7:
		gotoxy(x - 1, y - 1);	printf("%c%c%c", 205, 205, 187);
		gotoxy(x, y);			printf("%c%c", 205, 206);
		gotoxy(x + 1, y + 1);	printf("%c", 186);
		break;
	case 8:
		gotoxy(x - 1, y - 1);	printf("%c%c%c", 201, 205, 187);
		gotoxy(x - 1, y);		printf("%c%c%c", 204, 205, 185);	
		gotoxy(x - 1, y + 1);	printf("%c%c%c", 200, 205, 188);
		break;
	case 9:
		gotoxy(x - 1, y - 1);	printf("%c%c%c", 201, 205, 187);
		gotoxy(x - 1, y);		printf("%c%c%c", 200, 205, 185);		
		gotoxy(x - 1, y + 1);	printf("%c%c%c", 205, 205, 188);
		break;
	}
	gotoxy(0, 0);
}

void putBorder(int x, int y, int width, int height, int Color, bool inner) //Vẽ khung viền
{
	SetColor(Color);
	int j;
	for (int i = 0; i < height; i++)
	{
		gotoxy(x, y);
		j = 0;
		while (j < width)//for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				if (i == 0)
					printf("%c", 201);
				else if (i == height - 1)
					printf("%c", 200);
				else
					printf("%c", 186);
			}
			else if (j == width - 1)
			{
				if (i == 0)
					printf("%c", 187);
				else if (i == height - 1)
					printf("%c", 188);
				else
					printf("%c", 186);
			}
			else
			{
				if (i == 0 || i == height - 1)
					printf("%c", 205);
				else
				{
					if (inner)
						printf(" ");
					else
					{
						j = width - 2;
						gotoxy(x + j + 1, y);
					}
				}
			}
			j++;
		}
		y++;
	}
}

int ColorByNumber(int number) //Thiết lập màu theo giá trị số
{
	switch (number)
	{
	case 1: case 6: return White;
	case 2: case 7: return Green;
	case 3: case 8: return Cyan;
	case 4: case 9: return Yellow;
	case 5: return Pink;
	default: return Black;
	}
}