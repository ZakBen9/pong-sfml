#include "Ball.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include "CollisionManager.h"
#include "Constants.h"
#include "GameState.h"

using namespace sf;
using namespace std;

Ball::Ball(const string& filename,float x, float y):PSprite(filename,x,y)
{

}

void Ball::motion(vector<shared_ptr<PSprite>> sprites,GameState& gamestate)
{
    for(int i=0;i<sprites.size();i++)                           //sprites contains pointers on all the sprites on screen, in this case the 2 bars
    {
        if(Coll2PSprite(*this,*sprites[i]))           //If a ball collides with a PSprite it changes directionX
        {
            directionX*=-1;
            directionY=rand()%BALL_SPEED_MAX_Y;
        }
    }

    if(CollBorderH(*this))                //If a ball collides with a horizontal border it changes directionY
    {
        directionY=directionY*-1;
    }

    move(directionX,directionY);                    //Making the next movement


    if(CollBorderV(*this,gamestate))                //If the ball collides with a vertical border we reset the game
    {
        setPosition(WIN_WIDTH/2,WIN_HEIGHT/2);
        directionY=0;

        sprites[0]->setPosition(WIN_WIDTH-BAR_FROM_BORDERS,WIN_HEIGHT/2);
        sprites[1]->setPosition(BAR_FROM_BORDERS,WIN_HEIGHT/2);

        gamestate.setPaused();
    }

    setLowerRight();
}


