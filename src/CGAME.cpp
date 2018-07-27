#include "CGAME.h"

bool CGAME::get_data(bool check)
{
	system("cls");
	resizeConsole(450, 600);
	hidePtr();

	is_running = true;
	pause_state = false;

	if (check)
	{
		system("cls");

		//Print requirement.
		string path;
		gotoxy(20, 18);
		cout << "Enter the path: " << endl;
		gotoxy(20, 19);
		cout << ">> ";
		getline(cin, path);
		_flushall();

		//Import data from file.
		ifstream file;
		file.open(path);

		if (!file)
		{
			system("cls");

			gotoxy(20, 18);
			cout << "File does not exist.";

			Sleep(850);

			return false;
		}
		else
		{
			cn = CPEOPLE();

			file >> level;
			return true;
		}

		file.close();
	}
	else
	{
		cn = CPEOPLE();

		level = 1;
		return true;
	}
}

void CGAME::draw_map()
{
	system("cls");
	gotoxy(24, 1);
	cout << "LEVEL " << level;

	//Initialize nescessary characters: edge of map and traffic light.
	char edge = 219;

	//Draw line and frame.
	for (int i = 3; i <= 33; ++i)
	{
		for (int j = 0; j <= 53; ++j)
		{
			if (j == 0 || j == 53)
			{//Draw edge of map with purple.
				setColor(13);
				gotoxy(j, i);
				cout << edge;
			}
			if (j < 52 && !(i % 6))
			{//Draw line with white.
				setColor(15);
				gotoxy(j + 1, i);
				cout << "_";
			}
		}
	}

	//Set color back.
	setColor(15);

	//Draw people.
	cn.drawPeople();
}

int CGAME::play()
{
	int key = -1;

	while (!cn.isDead() || cn.isFinish())
	{
		_flushall();
		if (_kbhit())
		{
			fflush(stdin);
			key = toupper(_getch());
		}
		if (key == 27)
		{//Exit game.
			is_running = false;
			return 0;
		}
		else if (key == 'P')
		{//Pause game.
			pause_state = true;

			gotoxy(15, 35);
			cout << "Press any key to continue.";

			fflush(stdin);
			moving = toupper(_getch());

			gotoxy(15, 35);
			cout << "                          ";

			pause_state = false;
		}
		else if (key == 'T')
		{//Load game.
			return 1;
		}
		else if (key == 'L')
		{//Save game.
			pause_state = true;
			is_running = save();
			if (is_running)
			{
				draw_map();
				pause_state = false;
			}
			else
			{
				return 0;
			}
		}
		else if (key == 'A' || key == 'W' || key == 'S' || key == 'D')
		{//Update position of objects.
			moving = key;
		}

		if (cn.isFinish())
		{
			is_running = false;
			return 2;
		}
	}
}

bool CGAME::save()
{
	system("cls");

	//Print requirement.
	string path;
	gotoxy(20, 18);
	cout << "Enter the path: " << endl;
	gotoxy(20, 19);
	cout << ">> ";
	getline(cin, path);
	_flushall();

	//Save game to file.
	ofstream file;
	file.open(path);
	file << level;
	file.close();
	gotoxy(24, 21);
	cout << "Saved.";
	Sleep(850);

	//Ask user to continue.
	system("cls");
	int key = 0;
	gotoxy(22, 18);
	cout << "Continue? (Y/N)";

	do
	{//Just get Y key or N key.
		if (_kbhit())
		{
			fflush(stdin);
			key = toupper(_getch());

			if (key == 'Y')
			{
				return true;
			}
			if (key == 'N')
			{
				return false;
			}
		}
	} while (key != 'Y' || key != 'N');
}

void CGAME::level_up()
{
	is_running = true;
	pause_state = false;
	level++;
	cn = CPEOPLE();
}

void CGAME::exit()
{
	is_running = false;
}

void CGAME::updatePeoplePos()
{//When moving button hit, update postive of objects.
	if (moving != ' ') {
		this->cn.erasePeople();
		this->cn.updatePos(moving);
		this->cn.drawPeople();
		moving = ' ';
	}
}

void CGAME::updateLights()
{
	lights.update_light();
}

bool CGAME::congrats()
{//Congratulations user.
	system("cls");
	pause_state = true;
	for (int i = 0; i < 3; ++i)
	{
		gotoxy(20, 19);
		setColor(3);
		cout << "congratulations!!";
		Sleep(300);
		gotoxy(20, 19);
		setColor(11);
		cout << "CONGRATULATIONS!!";
		Sleep(300);
	}
	setColor(15);
	gotoxy(25, 21);
	cout << "LEVEL UP";
	Sleep(850);
	return true;
}

bool CGAME::check_people_is_dead()
{
	return cn.isDead();
}

bool CGAME::check_people_is_finish()
{
	return cn.isFinish();;
}

bool CGAME::check_game_is_running()
{
	return is_running;
}

bool CGAME::check_game_is_pause()
{
	return pause_state;
}