#pragma once
#include "GraphicsLib.h"

static const int L = 20;
static Colors tail_symbol = GREEN;
static Colors head_symbol = RED;
static Colors field_symbol = BLUE;
static Colors border_symbol = BLUE;
static Colors food_symbol = YELLOW;

enum DIRECTION { left, right, up, down };

enum KEYS { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27 };
