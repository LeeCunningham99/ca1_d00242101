#include "raylib.h"

class TitleScreen
{
    public:

    typedef enum TitlePage { TITLE = 0, GAMEPLAY } TitlePage;
    TitlePage currentScreen = TITLE;
    int framesCounter;
    int screenWidth;
    int screenHeight;
    Texture2D titleImage;
    Rectangle titleSource;
    Vector2 titlePosition;

    void setupTitleScreen();
    void drawTitleScreen();
    void unloadTitleTexture();
};
