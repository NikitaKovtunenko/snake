#pragma once

#include "snake.h"
struct GAME
{
	int timeout;
	bool game_on;
	SNAKE *c_snake;
	FOOD *c_food;
	FIELD *c_field;
};
void init_game(GAME*);
void set_snake(GAME*);
bool check_eating(GAME*);
void set_food(GAME*);
void check_game(GAME*);
void check_snake(GAME*);
void clear_snake(GAME*);
void handle_cmd(GAME*);
void next_step(GAME*);
void exec_game(GAME*);
