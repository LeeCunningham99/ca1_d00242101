#include "raylib.h"

class Player
{

public:

    Vector2 position;
    Texture2D Player;
    Rectangle Source;

    void movement();
    void animation();
};
