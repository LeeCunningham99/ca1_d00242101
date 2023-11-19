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
            playerPosition.y -= pSpeed;
        }
        if (IsKeyDown(KEY_DOWN) || (IsKeyDown(KEY_S))) 
        {
            playerPosition.y += pSpeed;
        }
        if (IsKeyDown(KEY_LEFT) || (IsKeyDown(KEY_A))) 
        {
            playerPosition.x -= pSpeed + 1.5f;
        }
        if (IsKeyDown(KEY_RIGHT) || (IsKeyDown(KEY_D))) 
        {
            //DrawTextureRec(playerImage, Rectangle{0,0,500, 200},Vector2{playerPosition},RAYWHITE);
            playerPosition.x += pSpeed + 0.5f;
        }
}

void Player::movementPowerUp() //Speed for player is increased if powerUpSpeed is set to true
{
if (IsKeyDown(KEY_UP) || (IsKeyDown(KEY_W)))
        {
            playerPosition.y -= pSpeed + 1.0f;
        }
        if (IsKeyDown(KEY_DOWN) || (IsKeyDown(KEY_S))) 
        {
            playerPosition.y += pSpeed + 0.8f;
        }
        if (IsKeyDown(KEY_LEFT) || (IsKeyDown(KEY_A))) 
        {
            playerPosition.x -= pSpeed -0.2f;
        }
        if (IsKeyDown(KEY_RIGHT) || (IsKeyDown(KEY_D))) 
        {
            //DrawTextureRec(playerImage, Rectangle{0,0,500, 200},Vector2{playerPosition},RAYWHITE);
            playerPosition.x += pSpeed + 1.5f;
        }
}

void Player::movementController()
{
    if (powerUpSpeed == true)
    {
        movementPowerUp();
        
    }
    else //if (powerUpSpeed == false)
    {   
        movement();  
    }
}

void Player::powerUpStart()
{
    //TO - DO:
    //AFTER SAY 10 SECONDS HAVE SPEED OF PLAYER INCREASE FOR 10 SECONDS THEN DECREASE AGAIN, MAYBE HAVE THIS ON A LOOP
    //REMEMBER TO SET BOOLEAN TO TRUE!!!

/*
//stack overflow
    int i;
    int count = 1;
    for (;;)
    {
        for (i = 0 ; i < powerTime ; i++)
        {
            usleep(1000 * 1000);
            powerUpSpeed = true;
        }
        return 0;
    }
    */
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