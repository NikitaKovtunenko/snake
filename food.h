#pragma once

struct FOOD
{
	int food_x;
	int food_y;
	bool food_flag;
};

void init_food(FOOD*);
int generate_food_x(unsigned int);
int generate_food_y(unsigned int);