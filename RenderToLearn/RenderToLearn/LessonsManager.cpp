#include "LessonsManager.h"
#include "Helper.h"

void LessonsManager::render() {
	//renderLesson01();
	renderLesson02();
}

void LessonsManager::renderLesson01() {
	lesson01.render();
}

void LessonsManager::renderLesson02() {	
	static int x = Helper::getRandomInt(400, 600);
	static int y = Helper::getRandomInt(300, 400);
	static int width = Helper::getRandomInt(20, 400);
	static int height = Helper::getRandomInt(20, 300);
	lesson02.render(x, y, width, height);
}