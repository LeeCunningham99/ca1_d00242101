#include "raylib.h"

class Player
{

public:
    Vector2 playerPosition;
    Texture2D playerImage;
    Rectangle source;
    float pWidth;
    float pHeight;
    int posY;
    int posX;
    float pSpeed;
    int playerSize;

    int frame;
    float runningTime;
    //const float updateTime;
    float updateTime;
    float deltaTime;

    //powerup related paramaters
    bool powerUpSpeed = false;
    float currentTime;
    float powerTime;

    //void playerSetup();
    void movement();
    void animation();
    void unloadTexture();
    void drawPlayer();
    void playerBoundaries();
    void movementPowerUp();
    void powerUpStart();
    void movementController();
};