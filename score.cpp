#include "score.hpp"

void Score::UpdateScore()
{
    
}

void Score::TextScore()
{
    //DrawText("SCORE: /n: ", 10, 10, 60, RED);
    DrawText(TextFormat("Fines: %i", fines), 20, 10, 50, MAROON);
    DrawText(TextFormat("Points: %i", points), 20, 60, 50, BLUE);
}

void Score::UnloadScoreTextures()
{
    UnloadTexture(loseImage);
    UnloadTexture(winImage);
}

void Score::drawLoseScreen()
{
    DrawTextureRec(winImage, winSource, winPosition, WHITE);
}

void Score::drawWinScreen()
{
    DrawTextureRec(loseImage, loseSource, losePosition, WHITE);
}