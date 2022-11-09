#pragma once

struct FIELD
{
	int** ArField;
	unsigned int rows;
	unsigned int columns;
};

void print_field(FIELD*);
void init_field(FIELD*);
void clear_field(FIELD*);
int** create_field(const FIELD*);
void destroy_field(FIELD*);