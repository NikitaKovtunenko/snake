#pragma once
#include <windows.h>
enum Colors {
	EMPTY = 0, RED = RGB(0xff, 0, 0), GREEN = RGB(0, 0xff, 0), BLUE = RGB(0, 0, 0xff), YELLOW = RGB(0xff, 0xff, 0)
};
//const size_t rows = 10, columns = 10;
//Прототипы функций, предоставляемых объектной библиотекой

//Запуск процесса (исполняемый файл demo.exe должен находиться) или в папке проекта, или там же, где functions.exe
void StartDemo();

//Задание размерностей двухмерного массива
void SetDimensions(int rows, int columns);

//задание цвета
//void SetColor(Colors color);

//Отрисовка шариков
void DrawBalls(int* p, int rows, int columns);

//Завершение процесса
void FinishDemo();

//Пауза
void pause(int ms);

