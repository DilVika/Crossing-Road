//This CGAME.h contains CGAME class.

#pragma once
#include "lib.h"
#include "CPEOPLE.h"
#include "CLIGHT.h"

class CGAME
{
private:
	int level;
	bool pause_state = true;
	bool is_running = false;
	int moving;

	CPEOPLE cn;
	CLIGHT lights;

public:
	CGAME() {};
	~CGAME() {};

	bool get_data(bool check);
	void draw_map();

	int play();
	bool save();
	void level_up();
	void exit();

	void updatePeoplePos();
	void updateLights();
	
	bool congrats();

	bool check_people_is_dead();
	bool check_people_is_finish();
	bool check_game_is_running();
	bool check_game_is_pause();
};