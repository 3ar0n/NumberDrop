#include "NuDro.h"

void Create_Code(int Point, char Str[])
{
	srand(time(NULL));
	int Val1 = 100 + rand() % 900;
	printf("Val1 = %d\n", Val1);
	int Val2 = Val1 + Point;
	char Str0[3], Str1[4], Str2[11];
	
	int tmp;
	for (int i = 2; i >= 0; i--)
	{
		tmp = Val1 % 10;
		Val1 = Val1 / 10;
		if (tmp == 0)
			Str0[i] = 'Z';
		else
			Str0[i] = 'A' + tmp - 1;
	}
	
	Str1[0] = '0' + Val2 / 1000;
	Str1[1] = '0' + Val2 / 100 % 10;
	Str1[2] = '0' + Val2 / 10 % 10;
	Str1[3] = '0' + Val2 % 10;

	for (int j = 0; j < 7; j++)
	{
		if (j % 2 == 0)
			Str[j] = Str1[j / 2];
		else
			Str[j] = Str0[(j - 1) / 2];
	}
	if (Str1[0] == '0')
		Str[7] = 'T' - 1;
	else
		Str[7] = 'T' + Str1[0] - '0';

	if (Str1[1] == '0')
		Str[8] = 'H' - 1;
	else
		Str[8] = 'H' + Str1[1] - '0';

	if (Str1[2] == '0')
		Str[9] = 'Z';
	else
		Str[9] = 'A' + Str1[2] - '0';

	if (Str1[3] == '0')
		Str[10] = 'I' - 1;
	else
		Str[10] = 'I' + Str1[3] - '0';
}