#include "const.h"
#include "food.h"
#include <iostream>
#include <conio.h> 
#include <cstdlib>
#include "field.h"
#include "game.h"
#include <ctime>
#include<windows.h>
//#define AUTOMATIC

void init_game(GAME* game)
{
	init_field(game->c_field);
	init_snake(game->c_snake);
	init_food(game->c_food);
	set_snake(game);
	print_field(game->c_field);
	
}

void set_snake(GAME* game) // установка змейки в масив field
{
	for (int i = 0; i < game->c_snake->snake_size; i++) 
	{
		if (game->c_snake->direction== up || game->c_snake->direction == down)
		{
			if (i == 0)
			{
				game->c_field->ArField[game->c_snake->snake_y[i]][game->c_snake->snake_x[i]] = head_symbol;
			}
			else {
				game->c_field->ArField[game->c_snake->snake_y[i]][game->c_snake->snake_x[i]] = tail_symbol;
			}

			
		}
		else if (game->c_snake->direction == left || game->c_snake->direction == right)
		{
			if (i == 0)
			{
				game->c_field->ArField[game->c_snake->snake_y[i]][game->c_snake->snake_x[i]] = head_symbol;
			}
			else
			{
				game->c_field->ArField[game->c_snake->snake_y[i]][game->c_snake->snake_x[i]] = tail_symbol;
			}

		}

	}
}

bool check_eating(GAME* game) //проверка съела змейка еду или нет 
{

	if (game->c_field->ArField[game->c_snake->snake_y[0]][game->c_snake->snake_x[0]] == game->c_field->ArField[game->c_food->food_y][game->c_food->food_x])
	{
		game->c_snake->snake_size++;
		game->c_snake->snake_x[game->c_snake->snake_size-1] = game->c_snake->snake_x[game->c_snake->snake_size - 2] + 1;
		game->c_food->food_x = 0;
		return false;
	}
	
	else
	{
		return true;
	}
	
}
   void set_food(GAME* game) //установка еды 
{   
	

	while (!game->c_food->food_flag)
	{
		unsigned int x_or_y = rand() % 2;
		if (x_or_y)
		{
			game->c_food->food_x = generate_food_x(game->c_field->columns);
		}
		else
		{
			game->c_food->food_y = generate_food_y(game->c_field->rows);
		}

		if (game->c_field->ArField[game->c_food->food_y][game->c_food->food_x] == 0)
		{
			game->c_food->food_flag = true;
			game->c_field->ArField[game->c_food->food_y][game->c_food->food_x] = food_symbol;
			break;
			
		}
	}
	
}
void check_game(GAME* game) // проверки змейки
{   

	if (game->c_field->ArField[game->c_snake->snake_y[0]][game->c_snake->snake_x[0]] == tail_symbol) // проверка не укусила ли себя змея 
	{
		game->game_on = false;
		std::cout << "The snake bit itself!"<<std::endl;
	}
	

	if (game->c_snake->snake_x[L - 1] && game->c_snake->snake_y[L-1]) // проверка на макс. длинну змейки 
	{
		game->game_on = false;
	}

	if (_kbhit())
	{
		
		if(_getch()==ESC){
		
		 std::cout << "Goodbye!";
	     game->game_on = false;
		
		}
		
	}
	
}
void check_snake(GAME* game)
{
	if (game->c_snake->snake_x[0] < 1)
	{
		game->c_snake->snake_x[0] = game->c_field->columns - 2;

	}else if (game->c_snake->snake_x[0] > game->c_field->columns - 2)
	{
		game->c_snake->snake_x[0] = 1;
	}
	else if (game->c_snake->snake_y[0] < 0)
	{
		game->c_snake->snake_y[0] = game->c_field->rows - 1;
	}
	else if (game->c_snake->snake_y[0] > game->c_field->rows - 1)
	{
		game->c_snake->snake_y[0] = 0;
	}

	
}
void clear_snake(GAME* game)//очистка массива field
{
	for (size_t i = 0; i < game->c_snake->snake_size; i++)
	{
		
	 for (size_t j = 0; j < game->c_snake->snake_size; j++)
	 {
		 game->c_field->ArField[game->c_snake->snake_y[i]][game->c_snake->snake_x[j]] = 0;
	 }
		
			
	}
}
void handle_cmd(GAME* game)
{	
	if (_getch() == ESC)
	{
	  std::cout << "Goodbye!";
	  game->game_on = false;
	}
	else
	{
		switch (_getch())
		{
		case UP:
			if(game->c_snake->direction != down)
				game->c_snake->direction = up;
			break;
		case DOWN:if(game->c_snake->direction != up)
			game->c_snake->direction = down;
			break;
		case LEFT:if (game->c_snake->direction != right)
			game->c_snake->direction = left;
			break;
		case RIGHT:if (game->c_snake->direction != left)
			game->c_snake->direction = right;
			break;
		default:;
			break;
		}
	}
	
}

void next_step(GAME* game)
{
	
		set_food(game);
		clear_snake(game);
		game->c_food->food_flag = check_eating(game);
		move_snake(game->c_snake);
		check_snake(game);
		set_snake(game);
		print_field(game->c_field);
		check_game(game);


}

void exec_game(GAME* game)
{


	while (game->game_on)
	{
		next_step(game);

#ifdef AUTOMATIC   //выбор режима игры
		Sleep(game->timeout);

		if (_kbhit())
		{
			handle_cmd(game);
		}

#else
		handle_cmd(game);

#endif

	}
}
