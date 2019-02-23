#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "PSprite.h"
class GameState;

bool Coll2PSprite(PSprite& spr1, PSprite& spr2);

bool CollBorderH(PSprite& spr);

bool CollBorderV(PSprite& spr,GameState&);

#endif // COLLISIONMANAGER_H
