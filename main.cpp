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
    titleScreen.titleImage = LoadTexture("./assets/titlescreen.png"); //Titlescreen Image
    titleScreen.titlePosition = {0.f, 0.f};
    titleScreen.titleSource = {0.f, 0.f, screenWidth, screenHeight};

    //Player Setup----------------------------------------------------------------------------------------
    Player player; //Creating A Player using Player Class.
    player.pWidth = 1100;
    player.posY = 100;
    player.pHeight = 250;
    player.posX = 220;
    player.playerImage = LoadTexture("./assets/ssplayer.png"); //Player Image
    player.playerPosition = {100.f, 220.0f};
    player.source = {0.f, 0.f, player.pWidth / 3.0f, player.pHeight}; //Source of Player's Rectangle
    player.pSpeed = 1.0f;
    player.powerTime = 10;
    player.currentTime = 0;
    Vector2 newPos = player.playerPosition; 
    //player.playerSize = 100;
    //player.bSpeed = {5.0f, 4.0f};
    //player.playerBoundaries();
    
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
    //PlayMusicStream(music);
    //float pitch = 1.0f;
    //float timePlayed = 0.0f;
    //bool pause = false;
    
    //Boundaries



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
        //player.movement();
        player.movementController();
        UpdateMusicStream(music);
        //Update
        scrollingBack -= 1.0f;
        if (scrollingBack <= -background.width*2) scrollingBack = 0;

        //World Boundaries
        //REFERENCE:
        // https://copyprogramming.com/howto/how-to-check-if-ball-colides-with-edge-of-window-in-c-with-raylib
        
        if ((player.playerPosition.x - 50.f) < 0) player.playerPosition.x = 50.f; //If Player's X position - it's size is less than 0 then set player's X position to = it's size.
        if ((player.playerPosition.x + 50.f) > 1600) player.playerPosition.x = 1600 - 50.f; // If Player's X postion + it's size is greater than the screenwidth then take away player's size from screenwidth.
        if ((player.playerPosition.y - 50.f) < 0) player.playerPosition.y = 50.f; //If Player's Y position - it's size is less than 0 then set player's Y position to = it's size.
        if ((player.playerPosition.y + 50.f) > 800) player.playerPosition.y = 800 - 50.f; // If Player's Y postion + it's size is greater than the screenheight then take away player's size from screenheight.

        BeginDrawing();
        ClearBackground(BLACK);

        


        //PowerUp Speed
        //player.movementPowerUp();

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