//This Menu.h contains Menu class.

#pragma once
#include "lib.h"

class item
{//This class perform member of the menu.
private:
	int m_x, m_y;
	string data;
	string DATA;
public:
	item() {};
	~item() {};

	void setItem(int, int, string, string);
	void printItem(bool check);
};

class menu
{//This class perform menu of the game.
private:
	vector<item> m_mem;
public:
	menu();
	~menu() {};

	void printTitle();
	void choose(bool &, int &);
	void printItems(int);
	int getChoice();
};