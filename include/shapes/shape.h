#pragma once

#include <stddef.h>

#define SHAPE(shape_Type) \
    Shape parent; \
    float (*shape_Type##_Calc_Area)(const shape_Type*); \
    void (*shape_Type##_Print_Info)(const shape_Type*, char**); \
    float (*Calc_Area)(const shape_Type*); \
    void (*Print_Info)(const shape_Type*); \

#define INIT_SHAPE(shape, shape_Type) \
    shape->shape_Type##_Calc_Area = shape_Type##_Calc_Area; \
    shape->shape_Type##_Print_Info = shape_Type##_Print_Info; \
    shape->parent.calc_area_offset = offsetof(shape_Type, shape_Type##_Calc_Area); \
    shape->parent.print_offset = offsetof(shape_Type, shape_Type##_Print_Info); \
    shape->parent.Calc_Area = Shape_Calc_Area; \
    shape->parent.Print_Info = Shape_Print; \
    shape->Calc_Area = (float(*)(const shape_Type*))Shape_Calc_Area; \
    shape->Print_Info = (void(*)(const shape_Type*))Shape_Print; \

typedef struct Shape Shape;
struct Shape
{
    size_t calc_area_offset;
    float (*Calc_Area)(const Shape*);

    size_t print_offset;
    void (*Print_Info)(const Shape*);
};

void Shape_Print(const Shape*);
float Shape_Calc_Area(const Shape*);
void Shape_Del(Shape*);