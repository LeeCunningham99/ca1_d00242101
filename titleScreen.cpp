#include "titleScreen.hpp"

void TitleScreen::setupTitleScreen()
{
    switch(currentScreen)
    {
        /*
    case LOGO:
        {
            framesCounter++;//Count Frames

            if (framesCounter > 120)
            {
                currentScreen = TITLE; //All of this means after 2 seconds it will go from logo screen to title screen.
            }
        } break;
        */

        case TITLE:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = GAMEPLAY;
            }
        } break;
        
        case GAMEPLAY:
        {
            /*
            if (IsKeyPressed(KEY_TAB))
            {
                currentScreen = ENDING;
            }
            */
        } break;
        /*
        case ENDING:
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = TITLE;
            }
        }
        */
    }
}

void TitleScreen::drawTitleScreen()
{
    switch(currentScreen)
            {
                /*
                case LOGO:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                    DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

                } break;
                */
                case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

                } break;

                case GAMEPLAY:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    //DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    //DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    //DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break;
                /*
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                */
                default: break;
            }
}
