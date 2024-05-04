#ifndef KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_ANIMATIONS_H
#define KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_ANIMATIONS_H

#include "raylib.h"

class Animations {
public:

    int sharkFrame = 0;
    int sharkChangeFrame = 15;

    int fishFrame = 0;
    int fishChangeFrame = 200;

    int playerSharkAnimation();
    int huntsFishAnimation();
};


#endif //KOU_YZM104_CGAMEPROJECT_ANGRYSHARKS_ANIMATIONS_H
