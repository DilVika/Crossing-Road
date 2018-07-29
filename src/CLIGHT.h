#pragma once
#include "Lib.h"

class CLIGHT
{
private:
	char light = 220;
	bool state; //red is false, green is true.
	int green_color;
	int red_color;
public:
	CLIGHT() {};
	~CLIGHT() {};
	void update_light();
};