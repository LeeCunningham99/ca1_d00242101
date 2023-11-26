#include "raylib.h"

//REFERENCE
// 

class Score
{
    public:
    int score1;
    int fines;
    int points;
    //int score2;
    Texture2D winImage;
    Texture2D loseImage;
    Rectangle winSource;
    Vector2 winPosition;
    Rectangle loseSource;
    Vector2 losePosition;

    void UpdateScore();
    void TextScore();
    void UnloadScoreTextures();
    void drawWinScreen();
    void drawLoseScreen();
};