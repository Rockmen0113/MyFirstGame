#include <iostream>
#include <conio.h>
#include "ConsoleLib.h"
#include "Menu.h"
#include "Game.h"
#include "Color.h"
using namespace std;
int lives = 6, Speed = 100, CouOfSw = 2, ColorText = 4, ColorBackGround = 15, SelCol = 4, SelCol2 = 15, n2, curItem2;
bool isSettings = false, Started = false, OnF = false, ReGer = false, IfColCh = false;
bool Menu()
{
	const int Esc = 27;
	const int Enter = 13;
	const int itemCount = 7;
	ShowCursor(false);
	SetColor(SelCol, SelCol2);
	int n = 0, curItem = 1, key, X = 30, Len = 22, Xn = 0, LenG = 0;
	if (isSettings)
	{
		isSettings = false;
	}
	if (Started)
	{
		PauseMenuLevel();
	}
	else 
	{
		MenuLevel();
	}
	do
	{
		if (IfColCh == true)
		{
			SettingsLevel();
			IfColCh = false;
			n2 = n;
			curItem2 = curItem;
		}

		ChangeTextAttr(X + Xn, 6 + (curItem + n), White, Black, Len + LenG);
		ChangeTextAttr(X + Xn, 7 + (curItem + n), White, Black, Len + LenG);
		ChangeTextAttr(X + Xn, 8 + (curItem + n), White, Black, Len + LenG);
		key = _getch();
		if (key == Enter && isSettings == false)
		{
			switch (curItem + n)
			{
			case -2:
				ReGer = true;
				return true;
				break;
			case 1:
				StartGame();
				break;
			case 4:
				SettingsLevel();
				isSettings = true;
				n = 0;
				X = 47;
				curItem = -2;
				Len = 18;
				break;
			case 7:
				exit(0);
				break;
			}
		}
		else if (key == Enter && isSettings)
		{
			switch (X + Xn)
				{
				case 53:
					if (Started == false)
					{
						for (int y = 1; y <= 24; y++)
						{
							SetColor(Black, Black);
							WriteChars(0, y, Null, 100);
						}
					}
						SetColor(SelCol, SelCol2);
						if (Started)
						{
							if (IfColCh == false)
							{
								GameLevel();
							}
							for (int i = 0; i <= 24; i++)
							{
								WriteChar(18, i, Vert);
								WriteChar(62, i, Vert);
							}
							WriteChar(65, 10, LeftTopD);
							WriteChars(66, 10, HorzD, 11);
							WriteChar(77, 10, RightTopD);
							for (int i = 11; i < 21; i++)
							{
								WriteChar(65, i, VertD);
								SetColor(Black, Black);
								WriteChar(66, i, Null);
								SetColor(SelCol, SelCol2);
								WriteChar(64, i, Null);
								WriteChar(63, i, Null);
							}
							for (int i = 1; i < 10; i++)
							{
								WriteChar(64, i, Null);
								WriteChar(63, i, Null);
								WriteChar(65, i, Null);
								WriteChar(66, i, Null);
							}
							for (int i = 1; i < 24; i++)
							{
								SetColor(Black, Black);
								WriteChars(19, i, Null, 43);
								SetColor(SelCol, SelCol2);
							}
						}
						if (Started)
						{
							isSettings = false;
							PauseMenuLevel();
							X = 30;
							n = 0;
							curItem = 1;
							Len = 22;
							Xn = 0;
							LenG = 0;
						}
						else
						{
							Menu();
						}
					break;
				case 20:
					ManualSettingsLevel();
					break;
				}
		}
		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(X + Xn, 6 + (curItem + n), SelCol, SelCol2, Len + LenG);
			ChangeTextAttr(X + Xn, 7 + (curItem + n), SelCol, SelCol2, Len + LenG);
			ChangeTextAttr(X + Xn, 8 + (curItem + n), SelCol, SelCol2, Len + LenG);

			switch (key)
			{
			case 72:		// Up
				if (curItem + n == 1 && isSettings == false && Started != true)
					n = itemCount - 1;
				else if (curItem + n == -2 && isSettings)
				{
					n = itemCount + 6;
					Xn = 6;
					LenG = -6;
				}
				else if (curItem + n == -2 && Started)
				{
					n = itemCount - 1;
				}
				else if (isSettings && curItem + n == 11)
				{
					n -= 4;
					Xn = 0;
					LenG = 0;
				}
				//else if (isSettings && curItem + n == -2 && OnF == false)
				//{
				//	OnF = true;
				//	Xn = 6;
				//	LenG = -12;
				//}
				//else if (isSettings && (curItem + n == -2 || curItem + n == 4) && OnF)
				//{
				//	OnF = false;
				//	Xn = 0;
				//	LenG = 0;
				//}
				else
					n -= 3;
				break;
			case 80:		// Down
				if (curItem + n == itemCount && Started == false && isSettings == false)
				{
					n = 0;
				}
				else if (curItem + n == itemCount && Started && isSettings == false)
				{
					n = -3;
				}
				else if (isSettings && curItem + n == itemCount)
				{
					n += 4;
					Xn = 6;
					LenG = -6;
				}
				else if (isSettings && curItem + n == 11)
				{
					n = 0;
					Xn = 0;
					LenG = 0;
				}
				//else if (isSettings && curItem + n == 1 && OnF == false)
				//{
				//	OnF = true;
				//	Xn = 6;
				//	LenG = -12;
				//}
				//else if (isSettings && (curItem + n == -2 || curItem + n == 4) && OnF)
				//{
				//	OnF = false;
				//	Xn = 0;
				//	LenG = 0;
				//}
				else
					n += 3;
				break;
			case 75:		//Left
				if (curItem + n == -2 && isSettings && CouOfSw == 2)
				{
					WriteStr(53, 5, " Easy  ");
					CouOfSw--;
					lives = 12;
					Speed = 500;
				}
				else if (curItem + n == -2 && isSettings && CouOfSw == 1)
				{
					WriteStr(53, 5, " Hard  ");
					CouOfSw = 3;
					lives = 3;
					Speed = 50;
				}
				else if (curItem + n == -2 && isSettings && CouOfSw == 3)
				{
					WriteStr(53,5, "Normal");
					CouOfSw--;
					lives = 6;
					Speed = 100;
				}


				if (curItem + n == 4 && isSettings && ColorText == 4)
				{
					WriteStr(50, 11, "    Cyan    ");
					ColorText--;
					SelCol = 3;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 3)
				{
					WriteStr(50, 11, "    Green   ");
					ColorText--;
					SelCol = 2;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 2)
				{
					WriteStr(50, 11, "    Blue    ");
					ColorText--;
					SelCol = 1;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 1)
				{
					WriteStr(50, 11, "    Yellow  ");
					ColorText = 14;
					SelCol = 14;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 14)
				{
					WriteStr(50, 11, "LightMagenta");
					ColorText--;
					SelCol = 13;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 13)
				{
					WriteStr(50, 11, "  LightRed  ");
					ColorText--;
					SelCol = 12;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 12)
				{
					WriteStr(50, 11, "  LightCyan ");
					ColorText--;
					SelCol = 11;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 11)
				{
					WriteStr(50, 11, "  LightGreen");
					ColorText--;
					SelCol = 10;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 10)
				{
					WriteStr(50, 11, "  LightBlue ");
					ColorText--;
					SelCol = 9;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 9)
				{
					WriteStr(50, 11, "  DarkGray  ");
					ColorText--;
					SelCol = 8;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 8)
				{
					WriteStr(50, 11, "  LightGray ");
					ColorText--;
					SelCol = 7;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 7)
				{
					WriteStr(50, 11, "    Brown   ");
					ColorText--;
					SelCol = 6;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 6)
				{
					WriteStr(50, 11, "   Magenta  ");
					ColorText--;
					SelCol = 5;
					IfColCh = true;
				}
				else if (curItem + n == 4 && isSettings && ColorText == 5)
				{
					WriteStr(50, 11, "    Red     ");
					ColorText--;
					SelCol = 4;
					IfColCh = true;
				}


				if (curItem + n == 7 && isSettings && ColorText == 4)
				{
					WriteStr(50, 14, "    Cyan    ");
					ColorText--;
					SelCol2 = 3;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 3)
				{
					WriteStr(50, 14, "    Green   ");
					ColorText--;
					SelCol2 = 2;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 2)
				{
					WriteStr(50, 14, "    Blue    ");
					ColorText--;
					SelCol2 = 1;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 1)
				{
					WriteStr(50, 14, "    White   ");
					ColorText = 15;
					SelCol2 = 15;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 15)
				{
					WriteStr(50, 14, "   Yellow   ");
					ColorText--;
					SelCol2 = 14;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 14)
				{
					WriteStr(50, 14, "LightMagenta");
					ColorText--;
					SelCol2 = 13;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 13)
				{
					WriteStr(50, 14, "  LightRed  ");
					ColorText--;
					SelCol2 = 12;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 12)
				{
					WriteStr(50, 14, "  LightCyan ");
					ColorText--;
					SelCol2 = 11;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 11)
				{
					WriteStr(50, 14, "  LightGreen");
					ColorText--;
					SelCol2 = 10;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 10)
				{
					WriteStr(50, 14, "  LightBlue ");
					ColorText--;
					SelCol2 = 9;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 9)
				{
					WriteStr(50, 14, "  DarkGray  ");
					ColorText--;
					SelCol2 = 8;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 8)
				{
					WriteStr(50, 14, "  LightGray ");
					ColorText--;
					SelCol2 = 7;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 7)
				{
					WriteStr(50, 14, "    Brown   ");
					ColorText--;
					SelCol2 = 6;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 6)
				{
					WriteStr(50, 14, "   Magenta  ");
					ColorText--;
					SelCol2 = 5;
					IfColCh = true;
				}
				else if (curItem + n == 7 && isSettings && ColorText == 5)
				{
					WriteStr(50, 14, "    Red     ");
					ColorText--;
					SelCol2 = 4;
					IfColCh = true;
				}

				if (isSettings && curItem + n == 11 && Xn == 6)
				{
					Xn = -27;
					LenG = -1;
				}
				else if (isSettings && curItem + n == 11 && Xn == -27)
				{
					Xn = 6;
					LenG = -6;
				}
				break;
			case 77:		//Right
					if (curItem + n == -2 && isSettings && CouOfSw == 2)
					{
						WriteStr(53, 5, " Hard  ");
						CouOfSw++;
						lives = 3;
						Speed = 50;
					}
					else if (curItem + n == -2 && isSettings && CouOfSw == 3)
					{
						WriteStr(53, 5, " Easy  ");
						CouOfSw = 1;
						lives = 12;
						Speed = 500;
					}
					else if (curItem + n == -2 && isSettings && CouOfSw == 1)
					{
						WriteStr(53, 5, "Normal");
						CouOfSw++;
						lives = 6;
						Speed = 100;
					}


					if (curItem + n == 7 && isSettings && ColorText == 4)
					{
						WriteStr(50, 14, "   Magenta  ");
						ColorText++;
						SelCol2 = 5;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 5)
					{
						WriteStr(50, 14, "    Brown   ");
						ColorText++;
						SelCol2 = 6;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 6)
					{
						WriteStr(50, 14, "  LightGray ");
						ColorText++;
						SelCol2 = 7;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 7)
					{
						WriteStr(50, 14, "  DarkGray  ");
						ColorText++;
						SelCol2 = 8;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 8)
					{
						WriteStr(50, 14, "  LightBlue ");
						ColorText++;
						SelCol2 = 9;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 9)
					{
						WriteStr(50, 14, "  LightGreen");
						ColorText++;
						SelCol2 = 10;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 10)
					{
						WriteStr(50, 14, "  LightCyan ");
						ColorText++;
						SelCol2 = 11;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 11)
					{
						WriteStr(50, 14, "  LightRed  ");
						ColorText++;
						SelCol2 = 12;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 12)
					{
						WriteStr(50, 14, "LightMagenta");
						ColorText++;
						SelCol2 = 13;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 13)
					{
						WriteStr(50, 14, "    Yellow  ");
						ColorText++;
						SelCol2 = 14;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 14)
					{
						WriteStr(50, 14, "    White   ");
						ColorText++;
						SelCol2 = 15;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 15)
					{
						WriteStr(50, 14, "    Blue    ");
						ColorText = 1;
						SelCol2 = 1;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 1)
					{
						WriteStr(50, 14, "    Green   ");
						ColorText++;
						SelCol2 = 2;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 2)
					{
						WriteStr(50, 14, "    Cyan    ");
						ColorText++;
						SelCol2 = 3;
						IfColCh = true;
					}
					else if (curItem + n == 7 && isSettings && ColorText == 3)
					{
						WriteStr(50, 14, "    Red     ");
						ColorText++;
						SelCol2 = 4;
						IfColCh = true;
					}

					if (curItem + n == 4 && isSettings && ColorText == 4)
					{
						WriteStr(50, 11, "   Magenta  ");
						ColorText++;
						SelCol = 5;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 5)
					{
						WriteStr(50, 11, "    Brown   ");
						ColorText++;
						SelCol = 6;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 6)
					{
						WriteStr(50, 11, "  LightGray ");
						ColorText++;
						SelCol = 7;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 7)
					{
						WriteStr(50, 11, "  DarkGray  ");
						ColorText++;
						SelCol = 8;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 8)
					{
						WriteStr(50, 11, "  LightBlue ");
						ColorText++;
						SelCol = 9;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 9)
					{
						WriteStr(50, 11, "  LightGreen");
						ColorText++;
						SelCol = 10;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 10)
					{
						WriteStr(50, 11, "  LightCyan ");
						ColorText++;
						SelCol = 11;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 11)
					{
						WriteStr(50, 11, "  LightRed  ");
						ColorText++;
						SelCol = 12;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 12)
					{
						WriteStr(50, 11, "LightMagenta");
						ColorText++;
						SelCol = 13;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 13)
					{
						WriteStr(50, 11, "    Yellow  ");
						ColorText++;
						SelCol = 14;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 14)
					{
						WriteStr(50, 11, "    Blue    ");
						ColorText = 1;
						SelCol = 1;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 1)
					{
						WriteStr(50, 11, "    Green   ");
						ColorText++;
						SelCol = 2;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 2)
					{
						WriteStr(50, 11, "    Cyan    ");
						ColorText++;
						SelCol = 3;
						IfColCh = true;
					}
					else if (curItem + n == 4 && isSettings && ColorText == 3)
					{
						WriteStr(50, 11, "    Red     ");
						ColorText++;
						SelCol = 4;
						IfColCh = true;
					}


				if (isSettings && curItem + n == 11 && Xn == -27)
				{
					Xn = 6;
					LenG = -6;
				}
				else if (isSettings && curItem + n == 11 && Xn == 6)
				{
					Xn = -27;
					LenG = -1;
				}
				break;
			}
		}
	} while (true);
}