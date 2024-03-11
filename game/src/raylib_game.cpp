/*******************************************************************************************
*
*   raylib game template
*
*   <Game title>
*   <Game description>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>
#include "variables.h"
#include "background.h"
#include "character.h"
#include "bullet.h"

using namespace std;

SPACESHIP player;
Bullet bullet;

int main(void)
{
	player.position.x = center_screenX - 64;
	player.position.y = center_screenY - 64;
	player.speed = 10;

	player.position = { player.position.x, player.position.y };

    InitWindow(screen_width, screen_height, "Space Warriors"); // Defines a windows.
    SetTargetFPS(targetFPS); // Sets the fps to 60.
	SetTraceLogLevel(7);
	Texture2D spaceship = LoadTexture("resources/gray3.png");


	while (!WindowShouldClose())
	{

		BeginDrawing();
		draw_background();

		player.update_movement();
		player.point_cursor(player.position);

		playerPOS = player.position;

		float NextShootTime = 0.f;

		fire_bullet();

		EndDrawing();
		UnloadTexture(spaceship); // for memory leak

	}
	
	CloseWindow();

	return 0;
}
