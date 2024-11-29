#pragma once

// Learning:
// How to clear screen?
// How to render lines?
// What is color?

// Lesson 1.1: basic rendering
// 1. Clearing screen
// 2. Render line from one position to another
// 3. Render horizontal line
// 4. Render vertical line
// 5. Render crossed lines in the center of the screen
// 6. Render square
// Homework: Render something difficult like house
// 
// Lesson 1.2 basic int and float variables
// 1. Render line from position in (x, y) to (x + 100, y), x and y set in student code.
// 2. Render some lines with offsets for x and y.
// 3. Render square. Left-top position is x, y, size = width. Variables set in student code.
// 4. Moving squares by changing x, y, width. Render some squares. Render some concentric squares.
// 5. Render some squares with some multiplier for width.
// Homework: render 20 concentric rectangles using copy-paste

namespace APILesson01 {
	void clear(float r, float g, float b);
	void drawLine(float x1, float y1, float x2, float y2);
	void drawColoredLine(float x1, float y1, float x2, float y2, float r, float g, float b, float a);
};

using namespace APILesson01;