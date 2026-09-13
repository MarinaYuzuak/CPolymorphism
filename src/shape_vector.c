#include <shapes/shape_vector.h>
#include <stdlib.h>

int Vector_Add_Shape(Vector* self, Shape* shape)
{
    if (self->size >= self->capacity)
    {
        self->capacity = self->size == 0 ? 4 : 2 * self->size;

        void* data_p = realloc(self->data, self->capacity * sizeof(Shape*));
        if (data_p == NULL)
            return -1;

        self->data = data_p;
    }

    self->data[self->size++] = shape;
    return 0;
}

void Vector_Clear_Shapes(Vector* self)
{
    if (self->data == NULL)
        return;

    free(self->data);
    self->data = NULL;
}