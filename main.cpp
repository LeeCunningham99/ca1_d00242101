/*******************************************************************************************
*
*   raylib [textures] example - Background scrolling
*
*   Example originally created with raylib 2.0, last time updated with raylib 2.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include <iostream>
#include "raylib.h"
#include "player.hpp"
//////////////////TRY TO GET PLAYER & ANIMATION STRUCTS WORKING///////////////////////
/*
struct Player 
{
    Vector2 position;
    //float speed;
    Texture2D texture;
    Rectangle sourceRec;
    float width;
    float height;
    int frame;
    float runningTime;
    const float updateTime;
};
*/

/*
struct Player Input (struct Player player)
{
    Vector2 position {100.f, 220.0f}; // Player start position
        // Keybinds
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
        return player;
}
*/
using namespace std;
int main(void)
{
    // Initialization
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Midnight Motoring"); //Name of Game 
    //Player
    Player player; //Creating A Player using Player Class.
    player.playerImage = LoadTexture("assets/ssplayer.png"); //Player Image
    //Source Of Spritesheet
    Rectangle source {0.f, 0.f, player.width / 3.0f, (float) player.height};
    Vector2 position {100.f, 220.0f};
    int frame = 0;
    float runningTime{};
    const float updateTime{1.f/10.f};

    //Audio
    InitAudioDevice(); //Initializes The Audio Devices
    Music music = LoadMusicStream("assets/Theme.mp3");
    music.looping = true;
    float pitch = 1.0f;
    PlayMusicStream(music);
    float timePlayed = 0.0f;
    bool pause = false;

    player.movement();

/*
struct Player player;
    player.texture = LoadTexture("assets/ssplayer.png");
    player.sourceRec = {0.f, 0.f, player.width / 3.0f, (float) player.height};
    player.position = {100.f, 220.0f};
    player.frame = 0;
    player.runningTime = 0.0f;
    player.updateTime = 1.0f/10.0f;

*/
    //Background
    Texture2D background = LoadTexture("assets/Background.png"); //Background Image
    float scrollingBack = 0.0f;
    //float scrollingMid = 0.0f;

    SetTargetFPS(60);           

    //Main game loop
    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        //Update
        scrollingBack -= 1.0f;
        //scrollingMid -= 0.7f;

        if (scrollingBack <= -background.width*2) scrollingBack = 0;
        //if (scrollingMid <= -midground.width*2) scrollingMid = 0;
        float deltaTime = GetFrameTime(); //Time inbetween frame updates
        //Movement for player. Arrow keys or WASD keys work
        /*
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
        */
        BeginDrawing();

            ClearBackground(BLACK);

            // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2){ scrollingBack, 0 }, 0.0f, 0.79f, WHITE);
            DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

            // Draw midground image twice
            //DrawTextureEx(midground, (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            //DrawTextureEx(midground, (Vector2){ midground.width*2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            
          //Animation
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

           DrawTextureRec(player.playerImage, source, position, WHITE);
          //Text 
            DrawText("SPEED - KM/H", 10, 10, 60, RED);
            DrawText("LAP - 1/3", screenWidth - 310, screenHeight - 890, 60, RED);

        EndDrawing();

/////////////////////////////Enemy AI////////////////////////////////////////////
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);  // Unload background texture
    //UnloadTexture(midground);   // Unload midground texture
    //UnloadTexture(playerImage); // Unload player's spritesheet texture
    player.unloadTexture();
    UnloadMusicStream(music);
    
    CloseWindow();      
    return 0;
}