#pragma once
#include "APILesson01.h"

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
