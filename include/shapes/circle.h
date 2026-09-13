#pragma once

#include "shape.h"

#define PI 3.14159265358979323846f

typedef struct Circle Circle;
struct Circle
{
    SHAPE(Circle);

    float radius;
};

Circle* Circle_New(float);