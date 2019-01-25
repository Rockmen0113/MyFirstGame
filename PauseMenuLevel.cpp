#include <iostream>
#include <conio.h>
#include "Menu.h"
#include "ConsoleLib.h"
using namespace std;

void PauseMenuLevel()
{
	const int sizeChars = 31;
	const int Xpar = 25;

	WriteChar(Xpar, 3, LeftTopD);  // Upper Corners
	WriteChars(26, 3, HorzD, sizeChars - 2);
	WriteChar(55, 3, RightTopD);

	WriteChar(Xpar, 17, LeftBottomD);  // Lower Corners
	WriteChars(26, 17, HorzD, sizeChars - 2);
	WriteChar(55, 17, RightBottomD);

	for (int i = 4; i <= 16; i++)
	{
		WriteChar(Xpar, i, VertD); // Left Double lines
		WriteChar(55, i, VertD); // Right Double lines
		WriteChars(Xpar + 1, i, Null, sizeChars - 2);  // Fill for menu.
	}

	WriteChar(30, 4, LeftTop); // Buttons
	WriteChars(31, 4, Horz, 21);
	WriteChar(51, 4, RightTop);

	WriteChar(30, 5, Vert);
	WriteStr(31, 5, "      Continue  ");
	WriteChar(51, 5, Vert);

	WriteChar(30, 6, LeftBottom);
	WriteChars(31, 6, Horz, 21);
	WriteChar(51, 6, RightBottom);

	WriteChar(30, 7, LeftTop); 
	WriteChars(31, 7, Horz, 21);
	WriteChar(51, 7, RightTop);

	WriteChar(30, 8, Vert);
	WriteStr(31, 8, "   Start New Game.  ");
	WriteChar(51, 8, Vert);

	WriteChar(30, 9, LeftBottom);
	WriteChars(31, 9, Horz, 21);
	WriteChar(51, 9, RightBottom);

	WriteChar(30, 10, LeftTop);
	WriteChars(31, 10, Horz, 21);
	WriteChar(51, 10, RightTop);

	WriteChar(30, 11, Vert);
	WriteStr(31, 11, "      Settings.    ");
	WriteChar(51, 11, Vert);

	WriteChar(30, 12, LeftBottom);
	WriteChars(31, 12, Horz, 21);
	WriteChar(51, 12, RightBottom);

	WriteChar(30, 13, LeftTop);
	WriteChars(31, 13, Horz, 21);
	WriteChar(51, 13, RightTop);

	WriteChar(30, 14, Vert);
	WriteStr(31, 14, "      Exit game.    ");
	WriteChar(51, 14, Vert);

	WriteChar(30, 15, LeftBottom);
	WriteChars(31, 15, Horz, 21);
	WriteChar(51, 15, RightBottom);
}