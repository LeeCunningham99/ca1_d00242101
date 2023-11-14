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

    int frame;
    float runningTime;
    //const float updateTime;
    float updateTime;
    float deltaTime;

    //void playerSetup();
    void movement();
    void animation();
    void unloadTexture();
    void drawPlayer();
    void playerBoundaries();
};