#include "APILesson02.h"
#include "pch.h"
#include "Core.h"
#include "Helper.h"

Lesson02Helper::Lesson02Helper() {
	x = Helper::getRandomInt(400, 600);
	y = Helper::getRandomInt(300, 400);
	width = Helper::getRandomInt(20, 400);
	height = Helper::getRandomInt(20, 300);
}

void Lesson02Helper::render(Core* pCore) {
	if (!pCore) { return; }
	
	SpriteBatch* pSpritesBatch = pCore->getSpritesBatch();
	SpriteFont* pFont = pCore->getFont();

	pSpritesBatch->Begin();

	wchar_t buf[1000];
	wsprintf(buf, L"x = %d\ny = %d\nwidth = %d\nheight = %d", x, y, width, height);
	pFont->DrawString(pSpritesBatch, buf, XMFLOAT2(Core::FRAME_WIDTH - 150, 25), Colors::Yellow);
	pSpritesBatch->End();
}