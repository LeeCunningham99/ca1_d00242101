#include "player.hpp"

/*
float deltaTime = GetFrameTime();
float runningTime{};
const float updateTime{1.f/10.f};
int frame = 0;
Rectangle source {0.f, 0.f, player.width / 3.0f, (float) player.height};
*/

void Player::movement()
{
if (IsKeyDown(KEY_UP) || (IsKeyDown(KEY_W)))
        {
            position.y -= 1.0f;
        }
        if (IsKeyDown(KEY_DOWN) || (IsKeyDown(KEY_S))) 
        {
            position.y += 1.0f;
        }
        if (IsKeyDown(KEY_LEFT) || (IsKeyDown(KEY_A))) 
        {
            position.x -= 0.2f;
        }
        if (IsKeyDown(KEY_RIGHT) || (IsKeyDown(KEY_D))) 
        {
            position.x += 1.5f;
        }
}
/*
void Player::animation()
{
   

    runningTime += deltaTime;
            if (runningTime >= updateTime)
            {
                runningTime = 0.f;
                source.x = (float) frame * source.width;
                frame++;
                if (frame > 3)
                {
                    frame = 0;
                }
            }
}
*/