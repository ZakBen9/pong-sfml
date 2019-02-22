#ifndef BAR_H
#define BAR_H

/**
   * This class Bar inherits from the class
   * PSprite and defines the method motion
   * which indicates how the bars move.
*/

#include <string>
#include "PSprite.h"

class Bar:public PSprite
{
    public:
        Bar(const std::string&,float,float);
        void motion();
};

#endif // BAR_H
