#pragma once
#include "Lesson01.h"
#include "Lesson02.h"

class LessonsManager {
public:
	static LessonsManager& getInstance() {
		static LessonsManager instance;
		return instance;
	}

	void render();
private:
	Lesson01 lesson01;
	Lesson02 lesson02;

	LessonsManager() = default;
	~LessonsManager() = default;

	LessonsManager(LessonsManager&&) = delete;
	LessonsManager& operator= (LessonsManager&&) = delete;

	LessonsManager(LessonsManager const&) = delete;
	LessonsManager& operator= (LessonsManager const&) = delete;

	void renderLesson01();
	void renderLesson02();
};

