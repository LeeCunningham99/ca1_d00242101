#include "player.hpp"

/*
float deltaTime = GetFrameTime();
float runningTime{};
const float updateTime{1.f/10.f};
int frame = 0;
Rectangle source {0.f, 0.f, player.width / 3.0f, (float) player.height};
*/
/*
void playerSetup()
{
    //Rectangle source {0.f, 0.f, player.width / 3.0f, (float) player.height};
    Vector2 position {100.f, 220.0f};
    int frame = 0;
    float runningTime{};
    const float updateTime{1.f/10.f};
}
*/

void Player::movement()
{
if (IsKeyDown(KEY_UP) || (IsKeyDown(KEY_W)))
        {
            playerPosition.y -= 1.0f;
        }
        if (IsKeyDown(KEY_DOWN) || (IsKeyDown(KEY_S))) 
        {
            playerPosition.y += 1.0f;
        }
        if (IsKeyDown(KEY_LEFT) || (IsKeyDown(KEY_A))) 
        {
            playerPosition.x -= 0.2f;
        }
        if (IsKeyDown(KEY_RIGHT) || (IsKeyDown(KEY_D))) 
        {
            //DrawTextureRec(playerImage, Rectangle{0,0,500, 200},Vector2{playerPosition},RAYWHITE);
            playerPosition.x += 1.5f;
        }
}

void Player::movementPowerUp() //Speed for player is increased if powerUpSpeed is set to true
{
if (IsKeyDown(KEY_UP) || (IsKeyDown(KEY_W)), powerUpSpeed = true)
        {
            playerPosition.y -= 2.0f;
        }
        if (IsKeyDown(KEY_DOWN) || (IsKeyDown(KEY_S))) 
        {
            playerPosition.y += 2.0f;
        }
        if (IsKeyDown(KEY_LEFT) || (IsKeyDown(KEY_A))) 
        {
            playerPosition.x -= 0.6f;
        }
        if (IsKeyDown(KEY_RIGHT) || (IsKeyDown(KEY_D))) 
        {
            //DrawTextureRec(playerImage, Rectangle{0,0,500, 200},Vector2{playerPosition},RAYWHITE);
            playerPosition.x += 2.5f;
        }
}


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

void Player::drawPlayer()
{
    DrawTextureRec(playerImage, source, playerPosition, WHITE);
}

/*
void Player::playerBoundaries()
{
    if (posY > 0) posY = 0;
    if (posY > 900 - pHeight) posY = 900 - pHeight; 
    //if (posX < 0) posX = 0;
    //if (posX > GetScreenWidth() - width) posX = GetScreenWidth() - width; 
}
*/

void Player::unloadTexture()
{
    UnloadTexture(playerImage); // Unload player's spritesheet texture
}