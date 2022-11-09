#include "snake.h"
#include "const.h"
#include <conio.h>





void init_snake(SNAKE *snake) // начальная установка координат змейки в массив
{

	if (snake->snake_size > 1)
	{
		
		if (snake->direction == left)
		{
			for (size_t i = 0; i < snake->snake_size; i++)
			{
				snake->snake_x[i] = i + 1;
				snake->snake_y[i] = 1;
			}

		}else if (snake->direction == right)
			{
			for (size_t i = 0; i < snake->snake_size; i++)
			{
				snake->snake_x[i] = snake->snake_size - i;
				snake->snake_y[i] = 1;
			}

		}
		else if (snake->direction == up)
		{
			for (size_t i = 0; i < snake->snake_size; i++)
			{
				snake->snake_x[i] = 1;
				snake->snake_y[i] = i+1;
			}
		}
		else if (snake->direction == down)
		{
			for (size_t i = 0; i < snake->snake_size; i++)
			{
				snake->snake_x[i] = 1;
				snake->snake_y[i] = snake->snake_size - i;
			}
		}
		
	}
	else
	{
		snake->snake_x[0] = 1;
	}
	
}

void move_snake(SNAKE* snake) // перестановка элементов хвоста 
{
	for (int i = snake->snake_size; i > 0; i--)
	{
		snake->snake_x[i] = snake->snake_x[i - 1];
		snake->snake_y[i] = snake->snake_y[i - 1];
	}
	

	if (snake->direction == left)  // выбор направления движения 
	{
		snake->snake_x[0] -= 1;
		
	}
	else if (snake->direction == right)
	{
		
		snake->snake_x[0] += 1;
		
	}
	else if (snake->direction == up)
	{
		snake->snake_y[0] -= 1;
	}
	else if (snake->direction == down)
	{
		snake->snake_y[0] += 1;
	}

}