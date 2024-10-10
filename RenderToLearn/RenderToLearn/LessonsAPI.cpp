#include "LessonsAPI.h"
#include "pch.h"
#include "Core.h"

void LessonsAPI::render() {
	Core& core = Core::getInstance();
	core.clear(0, 0, 0);
	core.drawLine(XMFLOAT2(0, 0), XMFLOAT2(1280, 720), XMFLOAT4(1, 1, 1, 1));
}
