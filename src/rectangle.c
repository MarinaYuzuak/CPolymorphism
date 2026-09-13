#include <shapes/rectangle.h>

#include <stdlib.h>
#include <stdio.h>

float Rectangle_Calc_Area(const Rectangle* self)
{
    return self->height * self->width;
}

void Rectangle_Print_Info(const Rectangle* self, char** buf)
{
    const char* info_str = "I am rectangle with w = %f and h = %f";

    size_t size = snprintf(NULL, 0, info_str, self->width, self->height);
    if (size == 0)
        return;

    *buf = malloc(size + 1);
    if (*buf == NULL)
        return;

    snprintf(*buf, size + 1, info_str, self->width, self->height);
}

Rectangle* Rectangle_New(float width, float height)
{
    Rectangle* rect = malloc(sizeof(Rectangle));
    if (rect == NULL)
        return NULL;

    INIT_SHAPE(rect, Rectangle);

    rect->width = width;
    rect->height = height;

    return rect;
}
