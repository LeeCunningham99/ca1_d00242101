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

int main(void)
{
    // Initialization
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Midnight Motoring"); //Name of Game 

    Texture2D background = LoadTexture("assets/Background.png");
    Texture2D player = LoadTexture("assets/playerss.png");
    Rectangle source {300.f, 300.f, player.width, (float) player.height / 3.0f};
    Vector2 position {100.f, 220.0f};
    int frame = 0;
    float runningTime{};
    const float updateTime{1.f/12.f};

    float scrollingBack = 0.0f;
    //float scrollingMid = 0.0f;

    SetTargetFPS(60);           

    //Main game loop
    while (!WindowShouldClose())
    {
        //Update
        scrollingBack -= 1.0f;
        //scrollingMid -= 0.7f;

        if (scrollingBack <= -background.width*2) scrollingBack = 0;
        //if (scrollingMid <= -midground.width*2) scrollingMid = 0;
        float deltaTime = GetFrameTime();
        BeginDrawing();

            ClearBackground(BLACK);

            // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2){ scrollingBack, 0 }, 0.0f, 0.79f, WHITE);
            DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

            // Draw midground image twice
            //DrawTextureEx(midground, (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            //DrawTextureEx(midground, (Vector2){ midground.width*2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            runningTime += deltaTime;
            if (runningTime >= updateTime)
            {
                runningTime = 0.f;
                source.x = (float) frame * source.height;
                frame++;
                if (frame > 3)
                {
                    frame = 0;
                }
            }
            
            //source.x = frame * player.height / 3;
           DrawTextureRec(player, source, position, WHITE);

            DrawText("SPEED - KM/H", 10, 10, 60, RED);
            DrawText("LAP - 1/3", screenWidth - 310, screenHeight - 890, 60, RED);

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);  // Unload background texture
    //UnloadTexture(midground);   // Unload midground texture
    UnloadTexture(player);
    
    CloseWindow();      

    return 0;
}