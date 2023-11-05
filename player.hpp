#include "raylib.h"

class Player
{

public:
    Vector2 position;
    Texture2D playerImage;
    Rectangle source;
    float width;
    float height;

    //void playerSetup();
    void movement();
    //void animation();
    void unloadTexture();
};