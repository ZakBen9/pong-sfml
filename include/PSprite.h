#ifndef PSPRITE_H
#define PSPRITE_H

/**
    *This class inherits the class
    *Sprite, and defines some
    *attributes to keep track of
    *a Sprite's geometry.
*/

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

class PSprite : public sf::Sprite
{
    public:
        PSprite(const std::string&, const float& x, const float& y);

        const float& getDirectionX() const;
        const float& getDirectionY() const;
        const sf::Vector2f& getLowerRight() const;                    //Getters
        const float& getWidth() const;
        const float& getHeight() const;

        void setPosition(float,float);
        void setDirectionX(const float&);
        void setDirectionY(const float&);                       //Setters
        void setLowerRight();

        bool strictlyHigherThan(PSprite&);
        bool strictlyLowerThan(PSprite&);
        bool strictlyLeftOf(PSprite&);                          //Relative position verification
        bool strictlyRightOf(PSprite&);


        std::shared_ptr<PSprite> nextMove();                                    //Returns a ptr on the sprite after its next movement

    protected:
        sf::Texture texture;                      //The sprite's texture
        float directionX;                         //The direction on X axis
        float directionY;                         //The direction on Y axis
        float width;                              //The sprite's width
        float height;                             //The Sprite's height
        sf::Vector2f lowerRight;                  //Lower right corner's coordinates

};

#endif // PSPRITE_H
