#include "raylib.h"

class Player
{

public:
    Vector2 playerPosition;
    Texture2D playerImage;
    Rectangle source;
    float width;
    float height;

    //void playerSetup();
    void movement();
    //void animation();
    void unloadTexture();
};