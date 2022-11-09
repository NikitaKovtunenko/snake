
#include "const.h"
#include "field.h"

#include <iostream>
#include "winconsole.h"





int** create_field(const FIELD* field) // создание массива field
{
	int* pr = new int[field->rows * field->columns];
	int** ppr = new int* [field->rows];
	for (size_t i = 0; i < field->columns; i++)
	{
		ppr[i] = pr + i * field->columns;
	}
	return ppr;
}

void destroy_field(FIELD* field)
{
	delete[] field->ArField[0];
	delete[] field->ArField;
}


void print_field(FIELD * field)  // вывод на экран поля игры
{

	setCursorPosition(0, 0);


	DrawBalls(*field->ArField, field->rows,field->columns);


}



void init_field(FIELD* field) // установка массива field граница поля
{
	
	for (size_t i = 0; i < field->rows; i++)
	{
		
			
	    field->ArField[i][0] = border_symbol;
		field->ArField[i][field->columns - 1] = border_symbol;
			
		
	}

	clear_field(field);
}

void clear_field(FIELD* field)
{
	for (size_t i = 0; i < field->rows; i++)//очистка массива field
	{

		for (size_t j = 1; j < field->columns- 1; j++)
		{
			field->ArField[i][j] = EMPTY;
		}

	}
}
