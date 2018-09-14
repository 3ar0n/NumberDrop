#include "NuDro.h"

int main()
{
	SetWindowsSize(DefaultSizeX, DefaultSizeY);
	int Score, Key, Choose;
	char VALUE[11];
	opt headMenu;
	CreateMenu(&headMenu);

	//gotoxy(DefaultSizeX / 2 - 5, DefaultSizeY / 2 - 2);
	//printf("Number Dr0p");
	//gotoxy(DefaultSizeX / 2 - 15, DefaultSizeY / 2 + 1);
	//printf("press 'Enter' to (re)start game");
	//gotoxy(DefaultSizeX / 2 - 9, DefaultSizeY / 2 + 2);
	//printf("press 'Esc' to exit");
	//gotoxy(0, 0);
	//do
	//{
	//	Key = Read_Key();
	//} while (Key != Esc && Key != Enter);
	//if (Key == Esc)
	//	exit(0);
	do
	{
		system("cls");
		Choose = Select(headMenu, 35, 20, false);

		switch (Choose)
		{
		case 1:
			putBorder(1, 3, DefaultSizeX - 2, DefaultSizeY - 4, Yellow_D, true);
			gotoxy(2, 1);
			//printf("Press ESC to exit       [Testing zone]");
			printf("Number Dr0p - version 1.10");
			gotoxy(DefaultSizeX / 2 + 5, 1);
			printf("Sound: On");
			gotoxy(DefaultSizeX - 13, 1);
			printf("Score:    0");

			do
			{
				Score = 0;
				Game(DefaultSizeX, DefaultSizeY, &Score);

				putBorder(34, 15, DefaultSizeX - 66, DefaultSizeY - 30, White_D, true);
				gotoxy(40, 17);
				printf("YOUR SCORE:");
				showScore(Score);
				Beep(440, 200);
				Beep(294, 600);
				gotoxy(0, 0);

				do
				{
					Key = Read_Key();
				} while (Key != Esc && Key != Enter);
				if (Key == Enter)
					putBorder(1, 3, DefaultSizeX - 2, DefaultSizeY - 4, Yellow_D, true);
			} while (Key != Esc);
			break;
		case 3:
			system("cls");
			Create_Code(69, VALUE);
			for (int i = 0; i < 11; i++)
				printf("%c", VALUE[i]);
			getch();
			break;
		case 5:
			break;
		default:
			printf("Do nothing");
		}
	} while (Choose != 5);

	return 0;
}

void showScore(int Point) //Vẽ điểm số cuối cùng lên màn hình
{
	char str[7];
	IntToString(Point, str);
	int tmp, LenOfString = strlen(str);
	for (int i = 0; i < LenOfString; i++)
	{
		tmp = CharToInt(str[i]);
		putNumber(tmp, White, (DefaultSizeX + 1) / 2 + 2 * (LenOfString - 1 - 2 * i), DefaultSizeY / 2 + 1);
	}
}

void Game(int sizeX, int sizeY, int *Point)
{
	srand((unsigned)time(NULL));
	//Tạo mảng chứa n số
	int count = 6;
	Number *Num = (Number*)malloc(count * sizeof(Number));

	for (int i = 0; i < count; i++)
		Num[i].posX = 0;
	//Khởi tạo trị số ngẫu nhiên (màu theo số); tọa độ (x,y) ngẫu nhiên và không trùng cột
	for (int i = 0; i < count; i++)
	{
		Num[i].key = rand() % 9 + 1;
		Num[i].color = ColorByNumber(Num[i].key);
		do
		{
			Num[i].posX = randomPosX(DefaultSizeX);
		} while (checkPos(Num, count, i) == true);
		Num[i].posY = 4 - (sizeY - 6) * i / count;
	}

	int Key, Timer = 0, Sound = 1;
	nb Lowest = &Num[0];
	bool Pressed = false;

	//Testing
	//gotoxy(44, 1);
	//printf("%d", Lowest->key);

	//Vòng lặp game
	do
	{
		for (int i = 0; i < count; i++)
		{
			if (Lowest == NULL)
				Lowest = &Num[i];

			//Xóa số tại vị trí cũ rồi thay đổi vị trí
			if (Num[i].posY > 4 && Num[i].key != 0)
				putNumber(Num[i].key, Black, Num[i].posX, Num[i].posY);

			Num[i].posY = Num[i].posY + 1;

			//In số lên màn hình (trong phạm vi khung), xóa nếu số đó đã được nhấn
			if (Num[i].posY > 4)
			{
				if (Num[i].posY < sizeY - 3)	//Viền dưới khung
				{
					if (Num[i].key != 0)
						putNumber(Num[i].key, Num[i].color, Num[i].posX, Num[i].posY);
				}
				else							//Chạm viền: - nếu số được nhấn (chuyển thành số 0) thì quay trở lại lên trên và tiếp tục
				{								//			 - nếu chưa được nhấn => kết thúc trò chơi
					if (Num[i].key == 0)
					{
						srand(*Point);
						Num[i].key = rand() % 9 + 1;
						Num[i].color = ColorByNumber(Num[i].key);
						do
						{
							Num[i].posX = randomPosX(DefaultSizeX);
						} while (checkPos(Num, count, i) == true);
						Num[i].posY = 4;
					}
					else
						goto LOOP_End;
				}
			}
		}

		//Nhận phím được nhấn. Nếu đúng => xóa số, đổi giá trị thành 0 (vẫn cho di chuyển xuống viền dưới)
		if (kbhit())
		{
			Key = Read_Key();
			if (Key == Lowest->key)
			{
				Pressed = true;
				putNumber(Lowest->key, Black, Lowest->posX, Lowest->posY);
				Lowest->key = 0;
				(*Point)++;
				if (Num[*Point % count].key != 0)
					Lowest = &Num[*Point % count];
				else
					Lowest = NULL;
				//gotoxy(44, 1);
				//printf("%d", Lowest->key);
				gotoxy(83, 1);
				SetColor(Yellow_D);
				printf("%5d", *Point);
			}
			else if (Key == Mute)
			{
				Sound = 1 - Sound;
				gotoxy(DefaultSizeX / 2 + 12, 1);
				SetColor(Yellow_D);
				if (Sound)
					printf("On ");
				else
					printf("Off");
			}
		}

		if (Sound == 1)
		{
			if (Pressed)
				Beep(440, mDelay);
			else
			{
				if (*Point < mDelay * 2)
					Sleep(2 * mDelay - *Point / 2 - Pressed * mDelay);
				else
					Sleep(mDelay);
			}
		}
		else
		{
			if (*Point < mDelay * 2)
				Sleep(2 * mDelay - *Point / 2);
			else
				Sleep(mDelay);
		}
		
		if (Pressed)
			Pressed = false;
	} while (1);
LOOP_End:
	free(Num);
}