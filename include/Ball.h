#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED


/**
  *This class inherits from the class
  *PSprite and defines the method motion
  *that indicates how the Ball moves
*/

#include <string>
#include <memory>
#include "PSprite.h"

class Ball:public PSprite
{
    public:
        Ball(const std::string&,float,float);

        void motion(std::vector<std::shared_ptr<PSprite>> ,bool&);
};

#endif // BALL_H_INCLUDED
