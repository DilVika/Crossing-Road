#include "menu.h"

void item::setItem(int x, int y, string data, string Data)
{//Set value for item.
	this->m_x = x;
	this->m_y = y;
	this->data = data;
	this->DATA = Data;
}

void item::printItem(bool check)
{//Perform item.
	char head = 175;
	if (check) {
		gotoxy(this->m_x - 3, this->m_y);
		cout << head << " " << this->DATA << " ";
	}
	else {
		gotoxy(this->m_x - 3, this->m_y);
		cout << "   " << this->data;
	}
}

menu::menu()
{//Initialize member of menu.
	item item1;
	item item2;
	item item3;
	item item4;

	item1.setItem(51, 22, "new game", "NEW GAME");
	this->m_mem.push_back(item1);

	item2.setItem(51, 24, "load game", "LOAD GAME");
	this->m_mem.push_back(item2);

	item3.setItem(51, 26, "settings", "SETTINGS");
	this->m_mem.push_back(item3);

	item4.setItem(51, 28, "exit", "EXIT");
	this->m_mem.push_back(item4);
}

void menu::printTitle()
{//Print title of the game.
	ifstream file;
	file.open("title.txt");

	string line;

	while (!file.eof()) {
		fflush(stdin);
		file.ignore(0);
		getline(file, line);
		cout << line << endl;
	}
	file.close();
}

void menu::choose(bool &choice, int &dir)
{//Perform the selectd item.
	while (true) {
		int key;
		if (_kbhit()) {
			key = _getch();
			if (key == 72)
			{//Press up.
				this->m_mem[dir].printItem(false);
				if (dir == 0)
					dir = 3;
				else
					--dir;
				this->m_mem[dir].printItem(true);
			}
			if (key == 80)
			{//Press down.
				this->m_mem[dir].printItem(false);
				if (dir == 3)
					dir = 0;
				else
					++dir;
				this->m_mem[dir].printItem(true);
			}
			if (key == 13)
			{//Press enter.
				choice = true;
				break;
			}
		}
	}
}

void menu::printItems(int dir)
{//Perform members to console.
	for (int i = 0; i < 4; ++i) {
		if (i == dir)
			this->m_mem[i].printItem(true);
		else
			this->m_mem[i].printItem(false);
	}
}

int menu::getChoice()
{
	//Check user have chosen yet.
	bool choose = false;

	//Save the choice.
	int dir = 0;

	gotoxy(0, 31);

	while (true)
	{//Loop the menu's choice.
	 //Print choices.
		this->printItems(dir);

		//User's choice.
		this->choose(choose, dir);

		if (choose)
			break;
	}
	return dir;
}