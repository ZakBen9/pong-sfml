#include "Bar.h"
#include "PSprite.h"
#include "CollisionManager.h"

using namespace sf;
using namespace std;

Bar::Bar(const string& filename,float x,float y):PSprite(filename,x,y)
{


}

void Bar::motion()
{
    if(!CollBorderH(*this))       //If a bar collides with a horizontal border it can't move in its direction
    {
        move(0,directionY);
        setLowerRight();
        directionY=0;
    }
}
