//This CPEOPLE.h contain CPEOPLE class.

#pragma once
#include "lib.h"

class CPEOPLE
{
private:
	int m_x, m_y;
	bool m_state;
public:
	CPEOPLE();
	~CPEOPLE();
	CPEOPLE& operator=(CPEOPLE cn);
	int tellX() {
		return m_x;
	}
	int tellY() {
		return m_y;
	}
	void drawPeople();
	void erasePeople();
	void updatePos(int key);
	void updateState();
	bool isDead();
	bool isFinish();
};