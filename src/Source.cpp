#include "Lib.h"
#include "Menu.h"
#include "CGAME.h"

CGAME cg;

void update_position()
{
	int count_time = 0;
	while (cg.check_game_is_running())
	{
		if (!cg.check_game_is_pause())
		{
			if (count_time == 0)
				cg.updateLights();
			if (count_time == 3000)
				count_time = 0;
			else count_time += 50;
			if (!cg.check_people_is_dead())
			{
				cg.updatePeoplePos();

			}
			if (cg.check_people_is_finish())
			{
				cg.congrats();
			}
		}
		Sleep(50);
	}
}

int play()
{
	cg.draw_map();
	thread t(update_position);
	int mark = cg.play();
	if (mark == 0)
	{
		t.join();
	}
	if (mark == 1)
	{
		cg.exit();
		t.join();
		cg.get_data(true);
		mark = play();
	}
	if (mark == 2)
	{
		t.join();
		cg.level_up();
		mark = play();
	}
	return mark;
}

int menu_func()
{
	system("cls");
	resizeConsole(905, 500);
	fixConsoleWindow();
	remove_scrollbar();
	hidePtr();

	menu m;
	m.printTitle();
	return m.getChoice();
}

void game()
{
	int value;
	switch (menu_func())
	{
	case 0:
	{
		cg.get_data(false);
		value = play();
		break;
	}
	case 1:
	{
		if (cg.get_data(true))
			value = play();
		else value = 0;
		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{
		return;
	}
	}
	if (!value)
		game();
}

int main()
{
	setColor(15);

	game();

	return 0;
}