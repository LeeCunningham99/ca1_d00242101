#include "raylib.h"

class TitleScreen
{
    public:

    typedef enum TitlePage { LOGO = 0, TITLE, GAMEPLAY, ENDING } TitlePage;
    TitlePage currentScreen = LOGO;
    int framesCounter;
    int screenWidth;
    int screenHeight;

    void setupTitleScreen();
    void drawTitleScreen();

};
