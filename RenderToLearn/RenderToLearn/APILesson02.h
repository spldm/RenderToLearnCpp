#pragma once
#include "APILesson01.h"

// Lesson 2.1 Creating functions, bool, if
// 1. Render rectangle using left-top position (x, y), width and height
// 2. Create function renderSquare using left-top position(x, y) and width
// 3. Create function renderSquareFromCenter using center position(x, y) and width
// 4. Create function renderSquareNew using left-top position(x, y), width, and bool: if true, then from center not from left top
// 5. Rename renderSquareNew to renderSquare, explain that function name contains list of parameters, remove other square rendering functions
// 6. Create function renderRectangle using left-top position(x, y) and width
// 7. Add the same bool parameter for renderRectangle
// 8. Rewrite renderSquare using renderRectangle.
// 9. Rename renderSquare to renderRectangle

// Lesson 2.1 Creating functions.
// 1. Create function renderSquare with parameters x(left point), y(top point), width
// 2. Create function renderRectangle with parameters x, y, width, height
// 3. Create function renderSquareCentered with x, y - center, width
// 4. Rewrite renderSquare and renderSquareCentered using renderRectangle.
// 4. Rename renderSquare to renderRectangle

// Homework: create function which render two concentric rectangles, parameters: 
//	  int x, int y, int width(size for the first square), float multipler(multiplier for size for the second square)
//	  Render three pairs of concentric rectangles using this function with same distances between them and screen edges
// 
// Lesson 2.2
// 1. Loop for

class Core;

class Lesson02Helper {
public:
	int x;
	int y;
	int width;
	int height;
	Lesson02Helper();
	void render(Core* pCore);
};
