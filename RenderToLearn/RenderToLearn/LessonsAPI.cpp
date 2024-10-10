#include "LessonsAPI.h"
#include "pch.h"
#include "Core.h"

#include "Lesson1.h"

void LessonsAPI::clear(float r, float g, float b) {
	Core::getInstance().clear(r, g, b);
}

void LessonsAPI::drawLine(float x1, float y1, float x2, float y2) {
	Core::getInstance().drawLine(XMFLOAT2(x1, y1), XMFLOAT2(x2, y2), XMFLOAT4(1, 1, 1, 1));
}

void LessonsAPI::drawColoredLine(float x1, float y1, float x2, float y2, float r = 1.f, float g = 1.f, float b = 1.f, float a = 1.f) {
	Core::getInstance().drawLine(XMFLOAT2(x1, y1), XMFLOAT2(x2, y2), XMFLOAT4(1, 1, 1, 1));
}
