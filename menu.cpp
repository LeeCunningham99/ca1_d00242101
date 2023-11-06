#include "menu.h"

bool exitApplication = false;
bool exitWindow = false;

void Menu::menuExit()
{
    while (!exitWindow)
    {
    if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitApplication = true; //If excape key is pressed bring up option for closing down game.   
        if (exitApplication)
        {
            //Use the Y key or N key to either close the window or return to playing  
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitApplication = false;
}
    }
}

void Menu::gameClose()
{
    if (exitApplication)
            {
                DrawRectangle(0, 100, 600, 200, BLACK);
                DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
            }
            else DrawText("Try to close the window to get confirmation message!", 120, 200, 20, LIGHTGRAY);

}
