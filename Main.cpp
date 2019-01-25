#define off
#ifndef on
#include <iostream>
#include "Menu.h"
#include "ConsoleLib.h"
using namespace std;
void main()
{
	Menu();
	SetColor(LightGray, Black);
	ShowCursor(true);
}

#else
#include <iostream>
#include <conio.h>           // getch
using namespace std;
void main()
{
	// Код клавиши Esc
	const int Esc = 27;

	// Выводим код любой нажатой клавиши
	int code;
	do
	{
		cout << "Press any key or Esc to stop..." << flush;
		code = _getch();
		cout << "\nCode of pressed key: " << code << endl;
	} while (code != Esc);
}
#endif
