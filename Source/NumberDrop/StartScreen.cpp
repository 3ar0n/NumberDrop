#include "NuDro.h"

void CreateMenu(opt *head)
{
	opt p1 = (opt)malloc(sizeof(menu));
	p1->value = 1;
	strcpy(p1->text, "   N E W   G A M E   ");

	opt p2 = (opt)malloc(sizeof(menu));
	p2->value = 2;
	strcpy(p2->text, "   C O N T I N U E   ");

	opt p3 = (opt)malloc(sizeof(menu));
	p3->value = 3;
	strcpy(p3->text, "H O W   T O   P L A Y");

	opt p4 = (opt)malloc(sizeof(menu));
	p4->value = 4;
	strcpy(p4->text, "      A B O U T      ");

	opt p5 = (opt)malloc(sizeof(menu));
	p5->value = 5;
	strcpy(p5->text, "       E X I T       ");

	*head = p1;
	p1->prev = NULL;
	p2->prev = p1;
	p3->prev = p2;
	p4->prev = p3;
	p5->prev = p4;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
}

int Select(opt head, int x, int y, bool saved)
{
	int Key;
	int X = x, Y = y + 3;
	opt p = head;
	SetColor(Cyan_D);
	while (p)
	{
		gotoxy(x, y + p->value * 3);
		if (p->value == 2 && !saved)
		{
			SetColor(Grey);
			printf("%s", p->text);
			putBorder(x - 1, y + p->value * 3 - 1, 23, 3, Grey);
			SetColor(Cyan_D);
		}
		else
		{
			printf("%s", p->text);
			putBorder(x - 1, y + p->value * 3 - 1, 23, 3, Cyan_D);
		}
		p = p->next;
	}
	p = head;
	gotoxy(X, Y);
	SetColor(Cyan);
	printf("%s", p->text);
	putBorder(X - 1, Y - 1, 23, 3, Cyan);
	gotoxy(0, 0);
	do
	{
		Key = Read_Key();
		if (Key == Up || Key == Down)
		{
			if (Key == Up && p->prev)
			{
				gotoxy(X, Y);
				SetColor(Cyan_D);
				printf("%s", p->text);
				putBorder(X - 1, Y - 1, 23, 3, Cyan_D);

				p = p->prev;
				Y = Y - 3;
				if (p->value == 2 && !saved)
				{
					p = p->prev;
					Y = Y - 3;
				}

				gotoxy(X, Y);
				SetColor(Cyan);
				printf("%s", p->text);
				putBorder(X - 1, Y - 1, 23, 3, Cyan);
			}
			if (Key == Down && p->next)
			{
				gotoxy(X, Y);
				SetColor(Cyan_D);
				printf("%s", p->text);
				putBorder(X - 1, Y - 1, 23, 3, Cyan_D);

				p = p->next;
				Y = Y + 3;
				if (p->value == 2 && !saved)
				{
					p = p->next;
					Y = Y + 3;
				}

				gotoxy(X, Y);
				SetColor(Cyan);
				printf("%s", p->text);
				putBorder(X - 1, Y - 1, 23, 3, Cyan);
			}
		}
		gotoxy(0, 0);
	} while (Key != Enter);
	SetColor(15);
	return p->value;
}