#include <iostream>
#include <conio.h>
#include "ConsoleLib.h"
#include "Menu.h"

using namespace std;

void ManualSettingsLevel()
{
	const int sizeChars = 49;
	const int Xpar = 18;

	extern int lives,Speed;

	WriteChar(Xpar, 3, LeftTopD);  // Upper Corners
	WriteChars(19, 3, HorzD, sizeChars - 2);
	WriteChar(66, 3, RightTopD);

	WriteChar(Xpar, 20, LeftBottomD);  // Lower Corners
	WriteChars(19, 20, HorzD, sizeChars - 2);
	WriteChar(66, 20, RightBottomD);

	WriteChar(Xpar, 4, VertD);  // Left Double lines
	WriteChar(Xpar, 5, VertD);
	WriteChar(Xpar, 6, VertD);
	WriteChar(Xpar, 7, VertD);
	WriteChar(Xpar, 8, VertD);
	WriteChar(Xpar, 9, VertD);
	WriteChar(Xpar, 10, VertD);
	WriteChar(Xpar, 11, VertD);
	WriteChar(Xpar, 12, VertD);
	WriteChar(Xpar, 13, VertD);
	WriteChar(Xpar, 14, VertD);
	WriteChar(Xpar, 15, VertD);
	WriteChar(Xpar, 16, VertD);
	WriteChar(Xpar, 17, VertD);
	WriteChar(Xpar, 18, VertD);
	WriteChar(Xpar, 19, VertD);

	WriteChar(66, 4, VertD);  // Right Double lines
	WriteChar(66, 5, VertD);
	WriteChar(66, 6, VertD);
	WriteChar(66, 7, VertD);
	WriteChar(66, 8, VertD);
	WriteChar(66, 9, VertD);
	WriteChar(66, 10, VertD);
	WriteChar(66, 11, VertD);
	WriteChar(66, 12, VertD);
	WriteChar(66, 13, VertD);
	WriteChar(66, 14, VertD);
	WriteChar(66, 15, VertD);
	WriteChar(66, 16, VertD);
	WriteChar(66, 17, VertD);
	WriteChar(66, 18, VertD);
	WriteChar(66, 19, VertD);

	WriteChars(Xpar + 1, 4, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 5, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 6, Null, sizeChars - 2);  // Fill for menu.
	WriteChars(Xpar + 1, 7, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 8, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 9, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 10, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 11, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 12, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 13, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 14, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 15, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 16, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 17, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 18, Null, sizeChars - 2);
	WriteChars(Xpar + 1, 19, Null, sizeChars - 2);

	WriteStr(20, 5, "Lives: ");

	WriteChar(47, 5, LeftArrow);
	GotoXY(53, 5);
	cout << lives;
	WriteChar(64, 5, RightArrow);

	WriteStr(20, 8, "Small Symbols: ");

	WriteChar(53, 8, LeftArrow);
	WriteStr(55, 8, "On");
	WriteChar(58, 8, RightArrow);

	WriteStr(20, 11, "Speed: ");

	WriteChar(48, 11, LeftArrow);
	GotoXY(50, 11);
	cout << Speed;
	WriteChar(63, 11, RightArrow);

	WriteStr(20, 14, "Points to Win: ");

	WriteChar(48, 14, LeftArrow);
	WriteStr(50, 14, "999");
	WriteChar(63, 14, RightArrow);

	WriteChar(53, 17, LeftTop);
	WriteChars(54, 17, Horz, 10);
	WriteChar(64, 17, RightTop);

	WriteChar(53, 18, Vert);
	WriteStr(57, 18, "Back");
	WriteChar(64, 18, Vert);

	WriteChar(53, 19, LeftBottom);
	WriteChars(54, 19, Horz, 10);
	WriteChar(64, 19, RightBottom);
}