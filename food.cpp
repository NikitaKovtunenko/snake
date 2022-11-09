#include <stdlib.h>
#include "const.h"
#include <iostream>
#include "food.h"

void init_food(FOOD* food) {

	std::cout << "Координата еды:" << food->food_x << std::endl;
	std::cout << "Флаг установки еды:" << food->food_flag << std::endl;
	std::cout << "Символ еды:" <<food_symbol << std::endl;
	system("cls");
	
}
int generate_food_x(unsigned int columns)
{
	
	int food_x = rand() % (columns-2) + 1;
	return food_x;
}

int generate_food_y(unsigned int rows)
{

	int food_y = rand() % (rows - 2) + 1;
	return food_y;
}