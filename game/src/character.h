#include <raylib.h>
#include "variables.h"
#include <cmath> // sqrt and pow 

class SPACESHIP
{
public:
    float width, height;
    int speed;

    Vector2 position;

    void update_movement()
    {
        Texture2D spaceship = LoadTexture("resources/gray3.png");

        Vector2 movement = { 0, 0 };
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        {
            movement.x += speed;
        }
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        {
            movement.x -= speed;
        }
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            movement.y -= speed;
        }
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            movement.y += speed;
        }

        float magnitude = sqrt(pow(movement.x, 2) + pow(movement.y, 2));

        // Normalize the vector
        if (magnitude != 0)
        {
            movement.x /= magnitude;
            movement.y /= magnitude;
        }

        position.x += movement.x * speed;
        position.y += movement.y * speed;
    }

    void point_cursor(Vector2 position)
    {
        Texture2D spaceship = LoadTexture("resources/gray3.png");

        float point_x = GetMouseX() - position.x;
        float point_y = GetMouseY() - position.y;
        float rotation = atan2(point_y, point_x) * 57.29578f; // Corrected atan2 calculation

        DrawTexturePro(spaceship,
            Rectangle{ 0, 0, (float)spaceship.width, (float)spaceship.height },
            { position.x, position.y, (float)spaceship.width , (float)spaceship.height },
            { player_width / 2, player_height / 2 },
            rotation+90,
            WHITE);
    }
};
