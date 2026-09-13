#include <shapes/shape.h>

#include <stdio.h>
#include <stdlib.h>

float Shape_Calc_Area(const Shape* shape)
{
    void** p_calc_area = (void*)shape + shape->calc_area_offset;
    float (*calc_area)(const Shape*) = *p_calc_area;

    return calc_area(shape);
}

void Shape_Print(const Shape* shape)
{
    void** p_print_info = (void*)shape + shape->print_offset;
    void (*print_info)(const Shape*, char** buf) = *p_print_info;

    char* buf = NULL;
    print_info(shape, &buf);

    if (buf == NULL)
    {
        printf("FAILED TO PRINT SHAPE INFO\n");
    }
    else
    {
        printf("%s\n", buf);
        free(buf);
        buf = NULL;
    }
}

void Shape_Del(Shape* self)
{
    free(self);
    self = NULL;
}
