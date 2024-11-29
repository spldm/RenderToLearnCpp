#pragma once
#include "Lesson01.h"
#include "Lesson02.h"

#include "APILesson01.h"
#include "APILesson02.h"

class Core;

class LessonsManager {
public:
	static LessonsManager& getInstance() {
		static LessonsManager instance;
		return instance;
	}

	void setCore(Core* pCore) { this->pCore = pCore; }
	void render();
private:
	Core* pCore;

	Lesson01 lesson01;
	Lesson02 lesson02;

	Lesson02Helper helper02;

	LessonsManager();
	~LessonsManager() = default;

	LessonsManager(LessonsManager&&) = delete;
	LessonsManager& operator= (LessonsManager&&) = delete;

	LessonsManager(LessonsManager const&) = delete;
	LessonsManager& operator= (LessonsManager const&) = delete;

	void renderLesson01();
	void renderLesson02();
};

