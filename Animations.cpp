#include "Animations.h"

int Animations::playerSharkAnimation() {
    int value;

    sharkFrame++;

    if (sharkFrame > sharkChangeFrame*2) {
        sharkFrame = 0;
    };

    float control = (float)sharkFrame / (float)sharkChangeFrame;

    if (control > 1 ) {
        value = 1;
    } else {
        value = 0;
    }

    return value;
}

int Animations::huntsFishAnimation() {
    int value;

    fishFrame++;

    if (fishFrame > fishChangeFrame*2) {
        fishFrame = 0;
    };

    float control = (float)fishFrame / (float)fishChangeFrame;

    if (control > 1 ) {
        value = 1;
    } else {
        value = 0;
    }

    return value;
}
