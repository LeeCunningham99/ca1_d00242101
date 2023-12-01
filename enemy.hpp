#include "raylib.h"

class Enemy
{

public:
    Vector2 ePosition;
    Texture2D eImage;
    Rectangle eSource;
    float eWidth;
    float eHeight;
    int ePosY;
    int ePosX;
    float eSpeed;
    int eSize;
    bool eActive;
    float eScrolling = 0.0f;

//Enemy Animation
    int eFrame;
    float eRunningTime;
    float eUpdateTime;
    float eDeltaTime;

    //void playerSetup();
    void eMovement();
    void eAnimation();
    void unloadEnemyTexture();
    void drawEnemy();
    void addScore();
};