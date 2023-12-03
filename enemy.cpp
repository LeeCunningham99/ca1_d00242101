#include "enemy.hpp"

void Enemy::eMovement()
{
    /*
    if (eActive == true)
    {
    ePosX -= 20.0f;
    }
    */
    //eScrolling -= 0.7f;
    //if (eScrolling <= -eImage.width*0) eScrolling = 0;
//Speeding Fine's Movement
    if (eActive == true)
    {
        ePosition.x -= eSpeed;
    }
//Points Movement
    if (ptsActive == true)
    {
        ptsPosition.x -= ptsSpeed;
    }
}

void Enemy::eAnimation()
{
//Speeding Fine Animation
    eRunningTime += eDeltaTime;
            if (eRunningTime >= eUpdateTime)
            {
                eRunningTime = 0.f;
                eSource.x = (float) eFrame * eSource.width;
                eFrame++;
                if (eFrame > 50)
                {
                    eFrame = 0;
                }
            }
//Points Animation
    ptsRunningTime += ptsDeltaTime;
            if (ptsRunningTime >= ptsUpdateTime)
            {
                ptsRunningTime = 0.f;
                ptsSource.x = (float) ptsFrame * ptsSource.width;
                ptsFrame++;
                if (ptsFrame > 50)
                {
                    ptsFrame = 0;
                }
            }
}

void Enemy::drawEnemy()
{
    //eScrolling -= 0.7f;
    DrawTextureRec(eImage, eSource, ePosition, WHITE);
    DrawTextureRec(ptsImage, ptsSource, ptsPosition, WHITE);
}

void Enemy::unloadEnemyTexture()
{
    UnloadTexture(eImage); // Unload Speeding Fine's spritesheet texture
    UnloadTexture(ptsImage); // Unload Points's spritesheet texture
}
