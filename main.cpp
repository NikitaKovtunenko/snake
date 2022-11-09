#include "const.h"
#include "field.h"
#include "food.h"
#include "game.h"
#include "snake.h"
#include <iostream>
#include <conio.h>
#include "GraphicsLib.h"





int main()
{
	srand(time(NULL));
	SNAKE snake = { {3},{0,},{0,},{down} };
	FIELD field = {{nullptr},{0},{0}};
	FOOD food = { {0},{0},{false} };
	GAME game = { {400},{true},{&snake},{&food},{&field} };

	
	StartDemo();
	std::cout << "Enter size of game field" << std::endl;
	std::cin >> field.rows >> field.columns;
	
	SetDimensions(field.rows, field.columns);
	field.ArField = create_field(&field);

	std::cout << "Enter direction!" << std::endl;


	_getch();
	switch (_getch())
	{
	case UP:snake.direction = up;
		break;
	case DOWN:snake.direction = down;
		break;
	case LEFT:snake.direction = left;
		break;
	case RIGHT:snake.direction = right;
		break;
	default:;
		break;
	}
	
	system("cls");
	init_game(&game);
	std::cout << "Press any key";
	_getch();
	system("cls");

	exec_game(&game);
	destroy_field(&field);
	FinishDemo();


	return 0;


}