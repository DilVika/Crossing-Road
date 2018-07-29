#pragma once

#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>

#define SLOW 290
#define WIDTH 50
#define LEVEL 13

using namespace std;
void gotoxy(int column, int line);
void fixConsoleWindow();
void resizeConsole(int width, int height);
void remove_scrollbar();
void hidePtr();
void setColor(int color);