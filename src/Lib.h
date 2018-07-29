//This lib.h contains system libraries and system functions.

#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
#include <thread>

using namespace std;

void gotoxy(int column, int line);
void fixConsoleWindow();
void resizeConsole(int width, int height);
void remove_scrollbar();
void hidePtr();
void setColor(int color);