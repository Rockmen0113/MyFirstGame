#ifndef __Menu_G__
#define __Menu_G__

const unsigned char Null = ' ';
const unsigned char LeftArrow = 17;
const unsigned char RightArrow = 16;
const unsigned char LeftTop = 218;
const unsigned char Horz = 196;
const unsigned char Vert = 179;
const unsigned char RightTop = 191;
const unsigned char LeftBottom = 192;
const unsigned char RightBottom = 217;

const unsigned char LeftTopD = 201;
const unsigned char HorzD = 205;
const unsigned char VertD = 186;
const unsigned char RightTopD = 187;
const unsigned char LeftBottomD = 200;
const unsigned char RightBottomD = 188;

void MenuLevel();
void SettingsLevel();
void ManualSettingsLevel();

void PauseMenuLevel();

bool Menu();

#endif