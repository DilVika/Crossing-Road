#include "CLIGHT.h"

void CLIGHT::update_light()
{
	if (state)
	{
		red_color = 4;
		green_color = 10;
		state = false;
	}
	else
	{
		red_color = 12;
		green_color = 2;
		state = true;
	}

	//Draw red light.
	setColor(red_color);
	gotoxy(52, 18);
	cout << light;
	gotoxy(1, 24);
	cout << light;

	//Draw green line.
	setColor(green_color);
	gotoxy(52, 19);
	cout << light;
	gotoxy(1, 25);
	cout << light;

	//Set color back.
	setColor(15);
}