#include "raylib.h"

class TitleScreen
{
    public:

    typedef enum TitlePage { TITLE = 0, GAMEPLAY } TitlePage;
    TitlePage currentScreen = TITLE;
    int framesCounter;
    int screenWidth;
    int screenHeight;

    void setupTitleScreen();
    void drawTitleScreen();

};
