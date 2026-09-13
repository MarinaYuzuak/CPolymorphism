#pragma once

#include "shape.h"

typedef struct Rectangle Rectangle;
struct Rectangle
{
    SHAPE(Rectangle);

    float height;
    float width;
};

Rectangle* Rectangle_New(float, float);