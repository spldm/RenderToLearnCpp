#include "LessonsManager.h"

LessonsManager::LessonsManager() {
	pCore = 0;
}

void LessonsManager::render() {
	//renderLesson01();
	renderLesson02();
}

void LessonsManager::renderLesson01() {
	lesson01.render();
}

void LessonsManager::renderLesson02() {	
	helper02.render(pCore);
	lesson02.render(helper02.x, helper02.y, helper02.width, helper02.height);
}