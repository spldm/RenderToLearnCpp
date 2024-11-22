#include "Lesson02.h"
#include "APILesson01.h"
using namespace APILesson01;
// Learning:
// Basic math: plus, minus, multiply, divide
// 
// Problems:
// 1. Render square with the center in point x, y and the size equals to "width"
// 2. Render in addition to the first square, another square to the left of the first 
// with size equals to half of the first square and with the same center
// 2. Render in addition to the first square, another square to the right of the first 
// with size equals double size of the first square and with the same center
// 4. Align all squares to the bottom edge.


void Lesson02::render(int x, int y, int width, int height) {
	drawLine(x, y, x + width, y + height);
}