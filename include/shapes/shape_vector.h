#pragma once
#include <stddef.h>

#include "shape.h"

typedef struct Vector Vector;
struct Vector
{
    size_t size;
    size_t capacity;

    Shape** data;
};

int Vector_Add_Shape(Vector*, Shape*);
void Vector_Clear_Shapes(Vector*);