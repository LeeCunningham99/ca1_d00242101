#include "raylib.h"
#include "raymath.h"
#include <stdlib.h>
#include <iostream>
#include "player.hpp"
#include "menu.hpp"
#include "titleScreen.hpp"
#include "enemy.hpp"
#include "score.hpp"
#define numEnemies 1
using namespace std;
//Timer------------------------------------------------------------------------------------------------
//REFERENCE
// https://www.youtube.com/watch?v=vGlvTWUctTQ
    typedef struct
    {
        float Lifetime;
    }Timer;

    void StartTimer(Timer* timer, float Lifetime)
    {
        if (timer != NULL)
        timer->Lifetime = Lifetime;
    }

    void UpdateTimer(Timer* timer)
    {
        if (timer != NULL && timer->Lifetime > 0)
        timer->Lifetime -= GetFrameTime();
    }

    bool TimerDone (Timer* timer)
    {
        if (timer != NULL)
        return timer->Lifetime <= 0;

        return false;
    }

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
    //player.playerSize = 100;
    //player.bSpeed = {5.0f, 4.0f};
    //player.playerBoundaries();
//Player Animation------------------------------------------------------------------------------------
    player.frame = 0;
    player.runningTime={};
    player.updateTime={1.f/10.f};
//Scoring---------------------------------------------------------------------------------------------
    Score score;
    score.points = 0;
    score.fines = 0;
    //score.fines1 = false;
    bool fCollision = false;
    Rectangle boxCollisionFine = {0};
    bool pCollision = false;
    Rectangle boxCollisionPoints = {10};
    score.winImage = LoadTexture("./assets/winImage.png");
    score.loseImage = LoadTexture("./assets/loseImage.png");
    score.loseSource = {0.f, 0.f, screenWidth, screenHeight};  
    score.losePosition = {0.f, 0.f};
    score.winSource = {0.f, 0.f, screenWidth, screenHeight}; 
    score.winPosition = {0.f, 0.f};
//Enemy Setup----------------------------------------------------------------------------------------
    Enemy enemy; //Creating A Player using Player Class.
//Speeding Fine Setup
    enemy.eWidth = 1100;
    enemy.ePosY = 100;
    enemy.eHeight = 250;
    enemy.ePosX = 220;
    enemy.eImage = LoadTexture("./assets/ssenemy.png"); //Speeding Fine Image
    enemy.ePosition = {1200.f, 220.0f};
    enemy.eSource = {0.f, 0.f, enemy.eWidth / 3.0f, enemy.eHeight}; //Source of Player's Rectangle
    enemy.eSpeed = 1.0f;
    enemy.eActive = true;
//Points Setup
    enemy.ptsWidth = 1100;
    enemy.ptsPosY = 100;
    enemy.ptsHeight = 280;
    enemy.ptsPosX = 220;
    enemy.ptsImage = LoadTexture("./assets/sspoints.png"); //Points Image
    enemy.ptsPosition = {500.f, 480.0f};
    enemy.ptsSource = {0.f, 0.f, enemy.ptsWidth / 3.0f, enemy.ptsHeight}; //Source of Player's Rectangle
    enemy.ptsSpeed = 1.0f;
    enemy.ptsActive = true;
//Enemy Animation------------------------------------------------------------------------------------
//Speeding Fine Animation Setup
    enemy.eFrame = 0;
    enemy.eRunningTime={};
    enemy.eUpdateTime={1.f/10.f};
//Points Animation Setup
    enemy.ptsFrame = 0;
    enemy.ptsRunningTime={};
    enemy.ptsUpdateTime={1.f/10.f};
//Menu Setup------------------------------------------------------------------------------------------
    Menu menu;
    menu.exitWindowRequested = false;
    menu.exitWindow = false;
    menu.menuScreenWidth = screenWidth;
//Audio-----------------------------------------------------------------------------------------------
//REFERENCE
// https://www.raylib.com/examples/audio/loader.html?name=audio_music_stream
    InitAudioDevice(); //Initializes The Audio Devices
    Music music = LoadMusicStream("assets/Theme.mp3"); //Loads .mp3 file
    music.looping = true;
    PlayMusicStream(music);
    //float pitch = 1.0f;
    //float timePlayed = 0.0f;
    //bool pause = false;
//Timer-----------------------------------------------------------------------------------------------
    Timer gameTimer = { 0 };
    float gameLife = 10.0f;
//Background------------------------------------------------------------------------------------------
//REFERENCE:
// https://www.raylib.com/examples.html -> 'Background Scrolling & Parallax' Example, won't let me link it.
    Texture2D background = LoadTexture("assets/Background.png"); //Background Image
    float scrollingBack = 0.0f;
    //float scrollingMid = 0.0f;
    SetTargetFPS(60);           
//Main game loop--------------------------------------------------------------------------------------
    while (!menu.exitWindow) //Displays an Exit option when esc is pressed
    {
        titleScreen.setupTitleScreen(); //Sets up Title Screen
        player.deltaTime = GetFrameTime();
        player.movementController();
        UpdateMusicStream(music);
        enemy.eDeltaTime = GetFrameTime();
        enemy.ptsDeltaTime = GetFrameTime();
        enemy.eMovement();
        //Update background scrolling
        scrollingBack -= 1.0f;
        if (scrollingBack <= -background.width*2) scrollingBack = 0;
//World Boundaries--------------------------------------------------------------------------------------------
//REFERENCE:
// https://copyprogramming.com/howto/how-to-check-if-ball-colides-with-edge-of-window-in-c-with-raylib
        
        if ((player.playerPosition.x - 50.f) < 0) player.playerPosition.x = 50.f; //If Player's X position - it's size is less than 0 then set player's X position to = it's size.
        if ((player.playerPosition.x + 50.f) > 1600) player.playerPosition.x = 1600 - 50.f; // If Player's X postion + it's size is greater than the screenwidth then take away player's size from screenwidth.
        if ((player.playerPosition.y - 50.f) < 0) player.playerPosition.y = 50.f; //If Player's Y position - it's size is less than 0 then set player's Y position to = it's size.
        if ((player.playerPosition.y + 50.f) > 800) player.playerPosition.y = 800 - 50.f; // If Player's Y postion + it's size is greater than the screenheight then take away player's size from screenheight.
//Timer Initialisation------------------------------------------------------------------------------
//From same reference as at top of file
        StartTimer(&gameTimer, gameLife);
        UpdateTimer(&gameTimer);
        if (!TimerDone(&gameTimer))
        {
            player.powerUpSpeed = true;
        }
//Scoring--------------------------------------------------------------------------------------------
//REFERENCE:
// https://www.raylib.com/examples.html -> 'Collision Area' Example, won't let me link it.
        fCollision = CheckCollisionRecs(player.source, enemy.eSource);
        if (fCollision) boxCollisionFine = GetCollisionRec(player.source, enemy.eSource);
        
        pCollision = CheckCollisionRecs(player.source, enemy.ptsSource);
        if (pCollision) boxCollisionPoints = GetCollisionRec(player.source, enemy.ptsSource);      
//DRAWING BEGINS ----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
//Background----------------------------------------------------------------------------------------
// Draw background image twice
// NOTE: Texture is scaled twice its size
        DrawTextureEx(background, (Vector2){ scrollingBack, 0 }, 0.0f, 0.79f, WHITE);
        DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
//Player Animation--------------------------------------------------------------------------------
        player.animation();
//Player Texture Drawn------------------------------------------------------------------------------
        player.drawPlayer();
//Text---------------------------------------------------------------------------------------------- 
        //DrawText("Avoid Speeding Fines!", 10, 10, 60, RED);
        //DrawText("Points: ", screenWidth - 310, screenHeight - 890, 60, RED);
        //DrawText(TextFormat("Fines: %i", score.fines), 750, 20, 50, MAROON);
        //DrawText(TextFormat("Points: %i", score.points), 1100, 20, 50, BLUE);
//Enemy Animation-----------------------------------------------------------------------------------
        enemy.eAnimation();
        //Enemy Texture Drawn
        enemy.drawEnemy();
//Scoring-------------------------------------------------------------------------------------------
        score.UpdateScore();
        score.TextScore();
        //TEST PURPOSES
        if (IsKeyDown(KEY_F))
        {
            score.fines++;
        }
        /*
        if (IsKeyDown(KEY_F) && score.fines >= 100)
        {
            score.drawLoseScreen();
        }
        */
        if (IsKeyDown(KEY_P))
        {
            score.points++;
        }
        /*
        if (IsKeyDown(KEY_P) && score.points >= 100)
        {
            score.drawWinScreen();
        }
        */
//---------------------------------------------------------------------------------------------------------------
        if (score.points >= 100)
        {
            //Texture2D winscrteen = LoadTexture("assets/winImage.png");
            //DrawTextureEx(winscrteen, (Vector2){ 0 }, 0.0f, 0.79f, WHITE);
            score.drawLoseScreen();
            titleScreen.framesCounter++;//Count Frames
            if (titleScreen.framesCounter == 120)
            {
                //titleScreen.setupTitleScreen();
                //titleScreen.drawTitleScreen();
                menu.gameClose();
            }
        }

        if (score.fines >= 100)
        {
            //Texture2D winscrteen = LoadTexture("assets/winImage.png");
            //DrawTextureEx(winscrteen, (Vector2){ 0 }, 0.0f, 0.79f, WHITE);
            score.drawWinScreen();
            titleScreen.framesCounter++;//Count Frames
            if (titleScreen.framesCounter == 120)
            {
                //titleScreen.setupTitleScreen();
                //titleScreen.drawTitleScreen();
                menu.gameClose();
            }
        }
//-------------------------------------------------------------- 
        if (fCollision)
        {
            DrawText("SPEEDING FINE!", GetScreenWidth()/2 - MeasureText("+1 FINE!", 20)/2, screenHeight/2 - 10, 20, RED);
            DrawRectangleRec(boxCollisionFine, RED);
            score.fines ++; 
            score.fines = true;        
        }
        /*
        if (score.fines >= 100)
        {
            score.drawLoseScreen();
            titleScreen.framesCounter++;
            if (titleScreen.framesCounter > 120)
            {
                menu.gameClose();
            }     
        }
        */
       if (pCollision)
        {
            DrawText("YOU COLLECTED A BOTTLE!", GetScreenWidth()/2 - MeasureText("+1 FINE!", 20)/2, screenHeight/2 - 10, 20, GREEN);
            DrawRectangleRec(boxCollisionPoints, GREEN);
            score.points ++; 
            score.points = true;        
        }
//menu------------------------------------------------------------------------------------------------------
        menu.menuExit();
        menu.gameClose();
        titleScreen.drawTitleScreen();//Draws Titlescreen
        EndDrawing();
    }
// De-Initialization
//------------------------------------------------------------------------------------------------------
    UnloadTexture(background);  // Unload background texture
    player.unloadTexture();
    enemy.unloadEnemyTexture();
    UnloadMusicStream(music);
    titleScreen.unloadTitleTexture();
    score.UnloadScoreTextures();   
    CloseWindow();      
    return 0;
}