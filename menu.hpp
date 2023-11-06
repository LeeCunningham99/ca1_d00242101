#include "raylib.h"

class Menu
{
    public:

    bool exitWindowRequested;
    bool exitWindow;
    int menuScreenWidth;

    void menuExit();
    void gameClose();
};
