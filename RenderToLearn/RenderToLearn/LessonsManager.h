#pragma once
#include "Lesson1.h"
#include "Lesson2.h"

class LessonsManager {
public:
	static LessonsManager& getInstance() {
		static LessonsManager instance;
		return instance;
	}

	void render();
private:
	Lesson1 lesson1;
	Lesson2 lesson2;

	LessonsManager() = default;
	~LessonsManager() = default;

	LessonsManager(LessonsManager&&) = delete;
	LessonsManager& operator= (LessonsManager&&) = delete;

	LessonsManager(LessonsManager const&) = delete;
	LessonsManager& operator= (LessonsManager const&) = delete;

	void renderLesson1();
	void renderLesson2();
};

