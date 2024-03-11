#pragma once
#include <raylib.h>

int targetFPS = 60;

const int screen_width = 1000;
const int screen_height = 1000;

const float center_screenX = screen_width / 2;
const float center_screenY = screen_height / 2;

const float player_width = 128;
const float player_height = 128;

const float BULLET_SPEED = 150.0f; // constant speed for bullets

Vector2 mouse_position = GetMousePosition();
Vector2 playerPOS;
