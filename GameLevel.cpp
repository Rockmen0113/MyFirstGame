#include <iostream>
#include <conio.h>
#include "Menu.h"
#include "ConsoleLib.h"
#include "Color.h"
using namespace std;

void GameLevel()
{
	const int sizeChars = 18;
	const int Xpar = 0;

	extern int SelCol, SelCol2;

	SetColor(SelCol, SelCol2);

	for (int i = 0; i <= 24; i++)
	{
		WriteChars(Xpar, i, Null, sizeChars); // Fill.
		WriteChars(Xpar + 62, i, Null, sizeChars);

		WriteChar(18, i, Vert); // Left lines

		WriteChar(62, i, Vert); // Right lines

	}
	
	WriteChar(65, 10, LeftTopD);  // Upper Double Corners
	WriteChars(66, 10, HorzD, 11);
	WriteChar(77, 10, RightTopD);

	WriteChar(2, 19, LeftTopD);
	WriteChars(3, 19, HorzD, 12);
	WriteChar(15, 19, RightTopD);

	for (int i = 20; i <= 22; i++)
	{
		WriteChar(2, i, VertD);
		WriteChar(15, i, VertD);
	}

	WriteChar(2, 23, LeftBottomD);
	WriteChars(3, 23, HorzD, 12);
	WriteChar(15, 23, RightBottomD);
	for (int i = 11;i <= 21; i++)
	{
		WriteChar(65, i, VertD);  // Left Double lines
		WriteChar(77, i, VertD);  // Right Double lines
	}
	WriteChar(65, 21, LeftBottomD);  // Lower Corners
	WriteChars(66, 21, HorzD, 11);
	WriteChar(77, 21, RightBottomD);
	
	SetColor(Red, Black);

	for (int i = 11;i <= 20; i++) WriteChars(66, i, Null, 11);
	for (int i = 0; i <= 24; i++) WriteChars(19, i, Null, 43);

	SetColor(SelCol, SelCol2);
}