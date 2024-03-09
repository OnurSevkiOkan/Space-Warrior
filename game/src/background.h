#pragma once
#include <raylib.h>
#include "variables.h"

void draw_background()
{
	Texture2D bg = LoadTexture("resources/space.png");
	DrawTexture(bg, screen_width / 2 -500, screen_height / 2 - 500, WHITE);
}