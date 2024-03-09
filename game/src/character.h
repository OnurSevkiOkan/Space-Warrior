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

        // Hareket vektörünü hesapla
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

        // Vektörün büyüklüğünü hesapla
        float magnitude = sqrt(pow(movement.x, 2) + pow(movement.y, 2));

        // Normalize the vector
        if (magnitude != 0)
        {
            movement.x /= magnitude;
            movement.y /= magnitude;
        }

        // Hareket vektörünü hızla çarp ve pozisyonu güncelle
        position.x += movement.x * speed;
        position.y += movement.y * speed;

        DrawTexture(spaceship, position.x, position.y, WHITE);
    }
};
