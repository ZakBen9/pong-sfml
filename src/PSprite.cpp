#include "PSprite.h"

using namespace sf;
using namespace std;

PSprite::PSprite(const std::string& filename,const float& x, const float& y):Sprite(),directionX(0),directionY(0)
{
    texture.loadFromFile(filename);                 //Loading the texture

    setTexture(texture);                            //Setting the sprite
    setPosition(x,y);

    width=texture.getSize().x;                      //Setting width and height
    height=texture.getSize().y;
}

const float& PSprite::getDirectionX() const
{
    return directionX;
}

const float& PSprite::getDirectionY() const
{
    return directionY;
}

const Vector2f& PSprite::getLowerRight() const
{
    return lowerRight;
}

const float& PSprite::getWidth() const
{
    return width;
}

const float& PSprite::getHeight() const
{
    return height;
}


void PSprite::setPosition(float x,float y)
{
    Sprite::setPosition(x,y);
    setLowerRight();                    //We set the lower right corner each time we change the position
}
void PSprite::setDirectionX(const float& dirX)
{
    directionX=dirX;
}

void PSprite::setDirectionY(const float& dirY)
{
    directionY=dirY;
}

void PSprite::setLowerRight()
{
    lowerRight.x=getPosition().x+width;
    lowerRight.y=getPosition().y+height;
}


bool PSprite::strictlyHigherThan(PSprite& spr)
{
    return lowerRight.y<spr.getPosition().y;            //If the lowest point of this is higher than spr's highest
}

bool PSprite::strictlyLowerThan(PSprite& spr)
{
    return spr.strictlyHigherThan(*this);               //If spr is strictly higher than this
}

bool PSprite::strictlyLeftOf(PSprite& spr)
{
    return lowerRight.x<spr.getPosition().x;            //If the rightest point of this is on spr's leftest left
}

bool PSprite::strictlyRightOf(PSprite& spr)
{
    return spr.strictlyLeftOf(*this);                   //If spr is strictly on the left of this
}


shared_ptr<PSprite> PSprite::nextMove()                            //Returns a pointer on this' position after its next move
{
    auto next=make_shared<PSprite>(*this);

    next->setPosition(getPosition().x+directionX,getPosition().y+directionY);

    return next;
}
