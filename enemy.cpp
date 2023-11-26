#include "enemy.hpp"

void Enemy::eMovement()
{
    if (eActive == true)
    {
    ePosX -= 20;
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
    DrawTextureRec(eImage, eSource, ePosition, WHITE);
}

void Enemy::unloadEnemyTexture()
{
    UnloadTexture(eImage); // Unload enemy's spritesheet texture
}
