#include <shapes/circle.h>

#include <stdio.h>
#include <stdlib.h>

float Circle_Calc_Area(const Circle* c)
{
    return PI * c->radius * c->radius;
}

void Circle_Print_Info(const Circle* c, char** buf)
{
    const char* info_str = "I am circle with r = %f";

    size_t size = snprintf(NULL, 0, info_str, c->radius);
    if (size == 0)
        return;

    *buf = malloc(size + 1);
    if (*buf == NULL)
        return;

    snprintf(*buf, size + 1, info_str, c->radius);
}

Circle* Circle_New(float r)
{
    Circle* circle = malloc(sizeof(Circle));
    if (circle == NULL)
        return NULL;

    INIT_SHAPE(circle, Circle);

    circle->radius = r;

    return circle;
}
