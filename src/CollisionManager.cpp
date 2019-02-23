#include "CollisionManager.h"
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include <memory>
#include "GameState.h"

bool Coll2PSprite(PSprite& spr1, PSprite& spr2)       //Managing the collision between two PSprites
{
    auto nxt=spr1.nextMove();

    if(nxt->strictlyHigherThan(spr2) || nxt->strictlyLowerThan(spr2) || nxt->strictlyLeftOf(spr2) || nxt->strictlyRightOf(spr2))    //If they don't collide after spr1's next move
    {
        return 0;
    }

    if(spr1.strictlyHigherThan(spr2))
    {
        spr1.setPosition(spr1.getPosition().x,spr2.getPosition().y-spr1.getHeight());
    }

    else if(spr1.strictlyLowerThan(spr2))
    {
        spr1.setPosition(spr1.getPosition().x,spr2.getLowerRight().y);
    }

    if(spr1.strictlyLeftOf(spr2))
    {
        spr1.setPosition(spr2.getPosition().x-spr1.getWidth(),spr1.getPosition().y);
    }

    else if(spr1.strictlyRightOf(spr2))
    {
        spr1.setPosition(spr2.getLowerRight().x,spr1.getPosition().y);
    }

    return 1;
}

bool CollBorderH(PSprite& spr)
{
    auto nxt=spr.nextMove();

    if(nxt->getPosition().y>0 && nxt->getLowerRight().y<WIN_HEIGHT)       //If there is no collision
    {
        return 0;
    }

    if(nxt->getPosition().y<0)                                              //If there is a collision with the upper border
    {
        spr.setPosition(spr.getPosition().x,0);
    }

    else if(nxt->getLowerRight().y>WIN_HEIGHT)                            //If there is a collision with the lower border
    {
        spr.setPosition(spr.getPosition().x,WIN_HEIGHT-spr.getHeight());
    }

    return 1;
}

bool CollBorderV(PSprite& spr,GameState& gameState)        //Manages collisions between a PSPrite and vertical borders
{
    auto nxt=spr.nextMove();

    if(nxt->getPosition().x>0 && nxt->getLowerRight().x<WIN_WIDTH)
    {
        return 0;
    }

    if(nxt->getPosition().x<=0)
    {
        spr.setPosition(0,spr.getPosition().y);
        gameState.setScoreBlu(gameState.getScoreBlu()+1);
    }

    else if(nxt->getLowerRight().x>=WIN_WIDTH)
    {
        spr.setPosition(WIN_WIDTH-spr.getWidth(),spr.getPosition().y);
        gameState.setScoreRed(gameState.getScoreRed()+1);
    }


    return 1;
}
