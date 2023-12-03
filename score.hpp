#include "raylib.h"

class Score
{
    public:

    int score1;
    int fines;
    //bool fines1 = false;
    int points;
    //int score2;
    Texture2D winImage;
    Texture2D loseImage;
    Rectangle winSource;
    Vector2 winPosition;
    Rectangle loseSource;
    Vector2 losePosition;

    //Points Entity Setup
    Vector2 ptsPos;
    Texture2D ptsImage;
    Rectangle ptsSource;
    float ptsWidth;
    float ptsHeight;
    int ptsPosX;
    int ptsPosY;
    float ptsSpeed;
    int ptsSize;
    float ptsScrolling = 0.0f;

    void UpdateScore();
    void TextScore();
    void UnloadScoreTextures();
    void drawWinScreen();
    void drawLoseScreen();
};