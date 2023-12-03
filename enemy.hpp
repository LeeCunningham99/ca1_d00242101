#include "raylib.h"

class Enemy
{

public:
//Speeding Fine -> Setup
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
//Points -> Setup
    Vector2 ptsPosition;
    Texture2D ptsImage;
    Rectangle ptsSource;
    float ptsWidth;
    float ptsHeight;
    int ptsPosY;
    int ptsPosX;
    float ptsSpeed;
    int ptsSize;
    bool ptsActive;
    float ptsScrolling = 0.0f;
//Speeding Fine Animation -> Setup
    int eFrame;
    float eRunningTime;
    float eUpdateTime;
    float eDeltaTime;
//Points Animation -> Setup
    int ptsFrame;
    float ptsRunningTime;
    float ptsUpdateTime;
    float ptsDeltaTime;
    //void playerSetup();
    void eMovement();
    void eAnimation();
    void unloadEnemyTexture();
    void drawEnemy();
    void addScore();
};
