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
    if (eActive == true)
    {
        ePosX -= eScrolling;
    }

}

void Enemy::eAnimation()
{
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
}

void Enemy::drawEnemy()
{
    eScrolling -= 0.7f;
    DrawTextureRec(eImage, eSource, ePosition, WHITE);
}

void Enemy::unloadEnemyTexture()
{
    UnloadTexture(eImage); // Unload enemy's spritesheet texture
}
