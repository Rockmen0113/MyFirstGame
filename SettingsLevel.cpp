#include <iostream>
#include <conio.h>
#include "ConsoleLib.h"
#include "Menu.h"
#include "Color.h"
using namespace std;

extern int SelCol, SelCol2;

void SettingsLevel()
{
	const int sizeChars = 49;
	const int Xpar = 18;

	extern int n2, CouOfSw, curItem2;
	extern bool isSettings;

	SetColor(SelCol, SelCol2);

	WriteChar(Xpar, 3, LeftTopD);  // Upper Corners
	WriteChars(19, 3, HorzD, sizeChars - 2);
	WriteChar(66, 3, RightTopD);

	WriteChar(Xpar, 20, LeftBottomD);  // Lower Corners
	WriteChars(19, 20, HorzD, sizeChars - 2);
	WriteChar(66, 20, RightBottomD);

	for (int i = 4; i <= 19; i++)
	{
		WriteChar(Xpar, i, VertD);  // Left Double lines
		WriteChar(66, i, VertD);  // Right Double lines
		WriteChars(Xpar + 1, i, Null, sizeChars - 2); // Fill for menu.
	}
	WriteStr(20, 5, "Difficulty"); // Buttons
	
	WriteChar(47, 5, LeftArrow);
	WriteStr(53, 5, "Normal");
	WriteChar(64, 5, RightArrow);

	WriteStr(20, 8, "Advanced Mode");

	WriteChar(52, 8, LeftArrow);
	WriteStr(54, 8, "Off");
	WriteChar(58, 8, RightArrow);

	WriteStr(20, 11, "Text Color Settings");

	WriteChar(48, 11, LeftArrow);
	WriteStr(50, 11, "    Red    ");
	WriteChar(63, 11, RightArrow);

	WriteStr(20, 14, "Background Color Settings");

	WriteChar(48, 14, LeftArrow);
	WriteStr(50, 14, "   White    ");
	WriteChar(63, 14, RightArrow);

	WriteChar(20, 17, LeftTop);
	WriteChars(21, 17, Horz, 15);
	WriteChar(36, 17, RightTop);

	WriteChar(20, 18, Vert);
	WriteStr(21, 18, "Manual settings");
	WriteChar(36, 18, Vert);

	WriteChar(20, 19, LeftBottom);
	WriteChars(21, 19, Horz, 15);
	WriteChar(36, 19, RightBottom);

	WriteChar(53, 17, LeftTop);
	WriteChars(54, 17, Horz, 10);
	WriteChar(64, 17, RightTop);

	WriteChar(53, 18, Vert);
	WriteStr(57, 18, "Back");
	WriteChar(64, 18, Vert);

	WriteChar(53, 19, LeftBottom);
	WriteChars(54, 19, Horz, 10);
	WriteChar(64, 19, RightBottom);

	if (isSettings && CouOfSw == 1) WriteStr(53, 5, " Easy  ");
	else if (isSettings && CouOfSw == 2) WriteStr(53, 5, "Normal");
	else if (isSettings && CouOfSw == 3) WriteStr(53, 5, " Hard  ");

	if (isSettings && SelCol == 1) WriteStr(50, 11, "    Blue    ");
	else if (isSettings && SelCol == 2) WriteStr(50, 11, "     Green   ");
	else if (isSettings && SelCol == 3) WriteStr(50, 11, "     Cyan    ");
	else if (isSettings && SelCol == 4) WriteStr(50, 11, "     Red     ");
	else if (isSettings && SelCol == 5) WriteStr(50, 11, "   Magenta   ");
	else if (isSettings && SelCol == 6) WriteStr(50, 11, "    Brown    ");
	else if (isSettings && SelCol == 7) WriteStr(50, 11, "  LightGray  ");
	else if (isSettings && SelCol == 8) WriteStr(50, 11, "  DarkGray   ");
	else if (isSettings && SelCol == 9) WriteStr(50, 11, "  LightBlue  ");
	else if (isSettings && SelCol == 10) WriteStr(50, 11, " LightGreen ");
	else if (isSettings && SelCol == 11) WriteStr(50, 11, " LightCyan  ");
	else if (isSettings && SelCol == 12) WriteStr(50, 11, " LightRed   ");
	else if (isSettings && SelCol == 13) WriteStr(50, 11, "LightMagenta");
	else if (isSettings && SelCol == 14) WriteStr(50, 11, "    Yellow  ");

	if (isSettings && SelCol2 == 1) WriteStr(50, 14, "    Blue    ");
	else if (isSettings && SelCol2 == 2) WriteStr(50, 14, "     Green   ");
	else if (isSettings && SelCol2 == 3) WriteStr(50, 14, "     Cyan    ");
	else if (isSettings && SelCol2 == 4) WriteStr(50, 14, "     Red     ");
	else if (isSettings && SelCol2 == 5) WriteStr(50, 14, "   Magenta   ");
	else if (isSettings && SelCol2 == 6) WriteStr(50, 14, "    Brown    ");
	else if (isSettings && SelCol2 == 7) WriteStr(50, 14, "  LightGray  ");
	else if (isSettings && SelCol2 == 8) WriteStr(50, 14, "  DarkGray   ");
	else if (isSettings && SelCol2 == 9) WriteStr(50, 14, "  LightBlue  ");
	else if (isSettings && SelCol2 == 10) WriteStr(50, 14, " LightGreen ");
	else if (isSettings && SelCol2 == 11) WriteStr(50, 14, " LightCyan  ");
	else if (isSettings && SelCol2 == 12) WriteStr(50, 14, " LightRed   ");
	else if (isSettings && SelCol2 == 13) WriteStr(50, 14, "LightMagenta");
	else if (isSettings && SelCol2 == 14) WriteStr(50, 14, "   Yellow    ");
	else if (isSettings && SelCol2 == 15) WriteStr(50, 14, "    White    ");
}