#pragma once
#include "const.h"
struct SNAKE
{
	int snake_size;
	int snake_x[L];
	int snake_y[L];
	DIRECTION direction;
};

void init_snake(SNAKE*);
void move_snake(SNAKE*);
