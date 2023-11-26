#include "score.hpp"

void Score::UpdateScore()
{
    
}

void Score::TextScore()
{
    DrawText("SCORE: /n: ", 10, 10, 60, RED);
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