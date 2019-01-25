#include "Game.h"
#include "Menu.h"
#include "ConsoleLib.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include "Color.h"

extern bool Started, ReGer;
extern int lives, Speed, CouOfSw, SelCol, SelCol2;
bool  UnPause = false, NextGen = false;
using namespace std;
void StartGame()
{
	char Symb, sSymb, rSymb;
	int randX, key = 0, nextY = 0, LifesY = 20, LifesX = 0, tScore = 0, Score = 0, Fail = 0, Temp = 0, Choise, Choise2 = 0;
	srand((unsigned)time(0));
	GameLevel();

	if (lives == 0 && CouOfSw == 1)
	{
		lives = 12;
		Speed = 500;
	}
	else if (lives == 0 && CouOfSw == 2)
	{
		lives = 6;
		Speed = 100;
	}
	else if (lives == 0 && CouOfSw == 3)
	{
		lives = 3;
		Speed = 50;
	}

	while (true)
	{
	for (int j = 1;j <= 3; j++)
	{
		for (int i = 0;i <= lives - 1; i++)
		{
			if ((i == 12 || i == 24 || i == 36) && lives > i)
			{
				if (LifesY == 22) break;
				LifesY++;
				LifesX = 0;
			}
			Temp = i;
			WriteChar(3 + LifesX, LifesY, 3);
			LifesX++;
		}
		if (Temp + 1 == lives) break;
		if (LifesY == 22) break;
	}
	SetColor(White, Black);

	WriteStr(67, 12, "Score:");
	WriteStr(67, 14, " Fail:");
	WriteStr(69, 16, "Speed");

	SetColor(SelCol, SelCol2);

	WriteStr(5, 17, "Lives:");
	WriteStr(1, 1, "Press Esc to get");
	WriteStr(3, 3, "back in Menu");
	GotoXY(11, 17);
	cout << lives;
	SetColor(White, Black);
	GotoXY(74, 12);
	cout << Score;

	GotoXY(74, 14);
	cout << Fail;
	ReGer = false;
	while (lives != 0 && ReGer != true)
	{
		if (Score == 999)
		{
			//win
		}
		else if (Fail == 999)
		{
			//lose
		}

		Symb = rand() % (90 - 65 + 1) + 65;
		randX = rand() % (61 - 19 + 1) + 19;
		sSymb = 97 + rand() % 25 + 1;
		rSymb = 93 + rand() % 60 + 1;
		if (CouOfSw == 1)
		{
			switch (Symb)
			{
			case 65:
				sSymb = 97;
				break;
			case 66:
				sSymb = 98;
				break;
			case 67:
				sSymb = 99;
				break;
			case 68:
				sSymb = 100;
				break;
			case 69:
				sSymb = 101;
				break;
			case 70:
				sSymb = 102;
				break;
			case 71:
				sSymb = 103;
				break;
			case 72:
				sSymb = 104;
				break;
			case 73:
				sSymb = 105;
				break;
			case 74:
				sSymb = 106;
				break;
			case 75:
				sSymb = 107;
				break;
			case 76:
				sSymb = 108;
				break;
			case 77:
				sSymb = 109;
				break;
			case 78:
				sSymb = 110;
				break;
			case 79:
				sSymb = 111;
				break;
			case 80:
				sSymb = 112;
				break;
			case 81:
				sSymb = 113;
				break;
			case 82:
				sSymb = 114;
				break;
			case 83:
				sSymb = 115;
				break;
			case 84:
				sSymb = 116;
				break;
			case 85:
				sSymb = 117;
				break;
			case 86:
				sSymb = 118;
				break;
			case 87:
				sSymb = 119;
				break;
			case 88:
				sSymb = 120;
				break;
			case 89:
				sSymb = 121;
				break;
			case 90:
				sSymb = 122;
				break;
			}
		}
		else if (CouOfSw == 2 && NextGen == true)
		{
			Choise = rand() % 2 + 1;
			if (Choise == 1)
			{
				Symb = sSymb;
			}
			NextGen = false;
		}
		else if (CouOfSw == 3 && NextGen == true)
		{
			Choise = rand() % 2 + 1;
			if (Choise == 1)
			{
				Symb = sSymb;
			}
			NextGen = false;
		}

		if (Speed > 500)
		{
			GotoXY(67, 18);
			cout << "Very Slow";
		}
		else if (Speed <= 500 && Speed > 100)
		{
			GotoXY(67, 18);
			cout << "   Slow ";
		}
		else if (Speed <= 100 && Speed > 80)
		{
			GotoXY(67, 18);
			cout << "  Normal ";
		}
		else if (Speed <= 80 && Speed > 50)
		{
			GotoXY(67, 18);
			cout << "   Fast ";
		}
		else if (Speed <= 50 && Speed > 20)
		{
			GotoXY(67, 18);
			SetColor(Red, Black);
			cout << "Very Fast";
			SetColor(White, Black);
		}
		else
		{
			GotoXY(67, 18);
			SetColor(LightRed, Black);
			cout << "  INSANE";
			SetColor(White, Black);
		}
		if (tScore == 10 && Speed > 100)
		{
			tScore = 0;
			Speed -= 100;
		}
		else if (tScore == 10 && Speed <= 100 && Speed > 20)
		{
			tScore = 0;
			Speed -= 10;
		}
		else if (tScore == 10 && Speed <= 20 && Speed > 1)
		{
			Speed--;
		}
		while (nextY < 24 && key != Symb && key != sSymb && ReGer != true)
		{
			Sleep(Speed);
			if (nextY > 0) WriteChar(randX, nextY - 1, Null);
			WriteChar(randX, nextY, Symb);
			nextY++;
			while (_kbhit())
			{
				key = _getch();
				if (key == 27)
				{
					Started = true;
					if (Menu())
					{
						SetColor(Black, Black);
						for (int i = 3; i <= 18; i++) WriteChars(25, i, Null, 32);
						SetColor(SelCol, SelCol2);
						for (int i = 20;i <= 22; i++) WriteChars(3, i, Null, 12);
						LifesX = 0;
						LifesY = 20;
						SetColor(White, Black);
					}
				}
				if (key == Symb || key == sSymb)
				{
					Score++;
					tScore++;
					GotoXY(74, 12);
					cout << Score;
					NextGen = true;
					break;
				}
				else if (key != 27 || key != sSymb)
				{
					Fail++;
					GotoXY(74, 14);
					cout << Fail;
				}
			}
			if (nextY == 24)
			{
				lives--;
				SetColor(SelCol, SelCol2);
				GotoXY(11, 17);
				cout << lives;
				if (lives < 10)
				{
					WriteChar(12, 17, Null);
				}
				else if (lives < 100)
				{
					WriteChar(13, 17, Null);
				}
				else if (lives < 1000)
				{
					WriteChar(14, 17, Null);
				}
				SetColor(White, Black);
				if (lives < 36)
				{
					SetColor(SelCol, SelCol2);
					WriteChar(3 + (LifesX - 1), LifesY, Null);
					LifesX--;
					if (LifesX + 3 == 3)
					{
						LifesX = 12;
						LifesY--;
					}
					SetColor(White, Black);
				}
			}
		}
		WriteChar(randX, nextY - 1, Null);
		nextY = 0;
		}
		if (lives == 0)
		{
			key = _getch();
			switch (key)
			{
			case 27:
				Started = false;
					for (int y = 1; y <= 24; y++)
					{
						SetColor(Black, Black);
						WriteChars(0, y, Null, 100);
					}
				Menu();
				break;
			case 13:
				if (CouOfSw == 1)
				{
					lives = 12;
					LifesY = 20;
					LifesX = 0;
					Speed = 500;
					Score = 0;
					Fail = 0;
				}
				else if (CouOfSw == 2)
				{
					lives = 6;
					LifesY = 20;
					LifesX = 0;
					Speed = 100;
					Score = 0;
					Fail = 0;
				}
				else if (CouOfSw == 3)
				{
					lives = 3;
					LifesY = 20; 
					LifesX = 0;
					Speed = 50;
					WriteChars(74, 12, Null, 3);
					Score = 0;
					WriteChars(74, 14, Null, 3);
					Fail = 0;
				}
				break;
			}
		}
		SetColor(SelCol, SelCol2);
	}
}