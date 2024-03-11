#pragma once
#include <raylib.h>
#include "variables.h"

#define MAX_BULLETS 20

class Bullet {
public:
    Vector2 bullet_position;
    Vector2 bullet_velocity;
    bool active;

    Bullet() : bullet_position({ 0 }), bullet_velocity({ 0,0 }), active(false) {}

    void update() {
        if (active) {
			bullet_position.x += bullet_velocity.x * GetFrameTime();
			bullet_position.y += bullet_velocity.y * GetFrameTime();

            // Deactivate bullet if it goes off-screen
            if (bullet_position.x > GetScreenWidth() || bullet_position.x < 0 ||
				bullet_position.y > GetScreenHeight() || bullet_position.y < 0) {
                active = false;
            }
        }
    }

    void draw() {
		Texture2D bullet_texture = LoadTexture("resources/blue_laser.png");
        if (active) {
            //DrawCircleV(bullet_position, 20, RED);

			float point_x = GetMouseX() - bullet_position.x;
			float point_y = GetMouseY() - bullet_position.y;

			const float rotation = atan2(point_y, point_x) * RAD2DEG; // Corrected atan2 calculation

			DrawTexturePro(bullet_texture, Rectangle{ 0, 0, (float)bullet_texture.width, (float)bullet_texture.height },
                       Rectangle{ bullet_position.x, bullet_position.y, 100, 100 }, // Adjust the size as needed
                       Vector2{ 50, 72 }, 0, WHITE);

			// Unload the texture
		}
    }
};
Bullet bullets[MAX_BULLETS];

void fire_bullet()
{
	for (int i = 0; i < MAX_BULLETS; i++) {
		bullets[i].update(); // Deactivetes the fire bullets function if amount of bullet is higher than maximum
	}
	static float shootCooldown = 0.0f; // Cooldown timer
	const float shootDelay = 0.3f; // Delay between shots in seconds

	// Update cooldown timer
	shootCooldown -= GetFrameTime();
	if (shootCooldown < 0.0f)
		shootCooldown = 0.0f;


	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && shootCooldown <= 0.0f) {
		for (int i = 0; i < MAX_BULLETS; i++) { // Limits the bullet amount with MAX_BULLETS
			if (!bullets[i].active) {
				bullets[i].bullet_position = { playerPOS.x,playerPOS.y }; // bullet start from player's position
				Vector2 cursorPos = GetMousePosition(); // Gets cursor position
				Vector2 direction = { cursorPos.x - bullets[i].bullet_position.x, cursorPos.y - bullets[i].bullet_position.y }; // Gets the direction for bullet with magnitudes;

				float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y); // Gets magnitude of direction vector and then normalize it

				if (magnitude != 0) {
					direction.x /= magnitude; // normalizes the vector's x component
					direction.y /= magnitude; // normalizes the vector's y component
				}

				// if you don't normalize the vector, ur bullets gets faster when u click further than player

				bullets[i].bullet_velocity = { direction.x * BULLET_SPEED, direction.y * BULLET_SPEED }; // Direction.x and direction.y is the unit vectors.
				bullets[i].active = true;

				shootCooldown = shootDelay;

				break;
			}
		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullets[i].draw(); // Creates the bullets
	}
}