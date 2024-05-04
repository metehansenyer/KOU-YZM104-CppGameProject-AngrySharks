#include "Utilities.h"

float Utilities::GetResizedScreenHeight(float gameScreenWidth, float gameScreenHeight, float screenWidth) {
    float value = (gameScreenHeight*screenWidth)/gameScreenWidth;
    return value;
}
