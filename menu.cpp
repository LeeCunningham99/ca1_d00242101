#include "menu.hpp"

//REFERENCES
// https://www.raylib.com/examples/core/loader.html?name=core_window_should_close

//bool exitApplication = false;
//bool exitWindow = false;

void Menu::menuExit()
{   
    if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true; //If excape key is pressed bring up option for closing down game.   
        if (exitWindowRequested)
        {
            //Use the Y key or N key to either close the window or return to playing  
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
}
    }

void Menu::gameClose()
{
    if (exitWindowRequested)
            {
                DrawRectangle(0, 100, menuScreenWidth, 200, BLACK);
                DrawText("QUIT GAME? [Y/N]", 40, 180, 30, WHITE);
            }
            else DrawText("TRY TO WIN", 120, 200, 20, LIGHTGRAY);

}
