#include "CPEOPLE.h"

CPEOPLE::CPEOPLE()
{//Initialize default state and default position.
	this->m_state = true;
	this->m_x = 28;
	this->m_y = 32;
}

CPEOPLE::~CPEOPLE()
{//Destroy object.
}

CPEOPLE& CPEOPLE::operator=(CPEOPLE cn)
{//Initialize this with date imported.
	this->m_state = cn.m_state;
	this->m_x = cn.m_x;
	this->m_y = cn.m_y;
	return *this;
}

void CPEOPLE::drawPeople()
{//Draw new position of people.
	char head = 220, body = 94;
	gotoxy(this->m_x, this->m_y);
	cout << head;
	gotoxy(this->m_x, this->m_y + 1);
	cout << body;
}
void CPEOPLE::erasePeople()
{//Erase old position of people.
	char light = 220;
	gotoxy(this->m_x, this->m_y);
	if ((this->m_x == 52 && this->m_y == 18)
		|| (this->m_x == 1 && this->m_y == 24))
	{//If current head's position matchs traffic red light position.
		setColor(4);
		cout << light;
	}
	else if ((this->m_x == 52 && this->m_y == 19)
		|| (this->m_x == 1 && this->m_y == 25))
	{//If current head's position matchs traffic green light position.
		setColor(2);
		cout << light;
	}
	else if (!(this->m_y % 6))
		//If body's position matchs line.
		cout << "_";
	else
		cout << " ";
	gotoxy(this->m_x, this->m_y + 1);
	if ((this->m_x == 52 && this->m_y + 1 == 18)
		|| (this->m_x == 1 && this->m_y + 1 == 24))
	{//If current body's position matchs traffic red light position.
		setColor(4);
		cout << light;
	}
	else if ((this->m_x == 52 && this->m_y + 1 == 19)
		|| (this->m_x == 1 && this->m_y + 1 == 25))
	{//If current body's position matchs traffic green light position.
		setColor(2);
		cout << light;
	}
	else if (!((this->m_y + 1) % 6))
		//If body's position matchs line.
		cout << "_";
	else
		cout << " ";

	//Set color back.
	setColor(15);
}

void CPEOPLE::updatePos(int key)
{//Update people's position with key imported.
	switch (key)
	{
	case 87:
	{//Press W.
		if (this->m_y > 3)
			--this->m_y;
		break;
	}
	case 83:
	{//Press S.
		if (this->m_y < 32)
			++this->m_y;
		break;
	}
	case 65:
	{//Press A.
		if (this->m_x > 1)
			--this->m_x;
		break;
	}
	case 68:
	{//Press D.
		if (this->m_x < 52)
			++this->m_x;
		break;
	}
	}
}

void CPEOPLE::updateState()
{//If people impacted, update people's state.
	this->m_state = false;
}

bool CPEOPLE::isDead()
{//Return true if people died.
	return this->m_state == false;
}

bool CPEOPLE::isFinish()
{//Return true if people finish a level.
	if (this->m_y <= 5)
		return true;
	else
		return false;
}