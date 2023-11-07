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
#include "raylib.h"
#include <iostream>
#include "player.hpp"
#include "menu.hpp"
#include "titleScreen.hpp"

using namespace std;
int main()
{
    //Initialization--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "Midnight Motoring"); //Name of Game 

    //TitleScreen Setup-----------------------------------------------------------------------------------
    TitleScreen titleScreen;
    titleScreen.framesCounter = 0;
    titleScreen.screenHeight = 2400;
    titleScreen.screenWidth = 1800;
    titleScreen.titleImage = LoadTexture("./assets/ssplayer.png"); //Titlescreen Image
    titleScreen.titlePosition = {0.f, 0.f};
    titleScreen.titleSource = {0.f, 0.f, screenWidth, screenHeight};

    //Player Setup----------------------------------------------------------------------------------------
    Player player; //Creating A Player using Player Class.
    player.width = 1100;
    player.height = 250;
    player.playerImage = LoadTexture("./assets/ssplayer.png"); //Player Image
    player.playerPosition = {100.f, 220.0f};
    player.source = {0.f, 0.f, player.width / 3.0f, player.height}; //Source of Player's Rectangle

    //Player Animation------------------------------------------------------------------------------------
    player.frame = 0;
    player.runningTime={};
    player.updateTime={1.f/10.f};

    //Menu Setup------------------------------------------------------------------------------------------
    Menu menu;
    menu.exitWindowRequested = false;
    menu.exitWindow = false;
    menu.menuScreenWidth = screenWidth;

    //Audio------------------------------------------------------------------------------------------------
    InitAudioDevice(); //Initializes The Audio Devices
    Music music = LoadMusicStream("assets/Theme.mp3"); //Loads .mp3 file
    music.looping = true;
    PlayMusicStream(music);
    //float pitch = 1.0f;
    //float timePlayed = 0.0f;
    //bool pause = false;
    
    //Background
    Texture2D background = LoadTexture("assets/Background.png"); //Background Image
    float scrollingBack = 0.0f;
    //float scrollingMid = 0.0f;
    SetTargetFPS(60);           
    //Main game loop---------------------------------------------------------------

    while (!menu.exitWindow) //Displays an Exit option when esc is pressed
    {
        titleScreen.setupTitleScreen(); //Sets up Title Screen

        player.deltaTime = GetFrameTime();
        player.movement();
        UpdateMusicStream(music);
        //Update
        scrollingBack -= 1.0f;
        if (scrollingBack <= -background.width*2) scrollingBack = 0;

        BeginDrawing();
        ClearBackground(BLACK);

        //Background--------------------------------------------------------------------------------------------------------------------------------------
            // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2){ scrollingBack, 0 }, 0.0f, 0.79f, WHITE);
            DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
            
          //Player Animation----------------------------------------------------------------------------------------------------------------------------
          player.animation();
         
        //Player Texture Drawn--------------------------------------------------------------------------------------------------------------------------
        player.drawPlayer();
        //Text 
            DrawText("SPEED - KM/H", 10, 10, 60, RED);
            DrawText("Points: ", screenWidth - 310, screenHeight - 890, 60, RED);

//menu--------------------------------------------------------------------------------------------------------------------------------------------
        menu.menuExit();
        menu.gameClose();

        titleScreen.drawTitleScreen();//Draws Titlescreen

        EndDrawing();
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);  // Unload background texture
    player.unloadTexture();
    UnloadMusicStream(music);
    titleScreen.unloadTitleTexture();
    
    CloseWindow();      
    return 0;
}