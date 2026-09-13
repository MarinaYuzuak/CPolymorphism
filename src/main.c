#include <shapes/circle.h>
#include <shapes/rectangle.h>
#include <shapes/shape_vector.h>

int main(void)
{
    Circle* c = Circle_New(15.f);
    Circle* c1 = Circle_New(20.f);

    Rectangle* r1 = Rectangle_New(5.f, 5.f);
    Rectangle* r2 = Rectangle_New(10.f, 5.f);

    Vector v = {.size = 0, .capacity = 0};
    Vector_Add_Shape(&v, (Shape*)c);
    Vector_Add_Shape(&v, (Shape*)r1);
    Vector_Add_Shape(&v, (Shape*)c1);
    Vector_Add_Shape(&v, (Shape*)r2);

    for (size_t i = 0; i < v.size; ++i)
    {
        const Shape* s = v.data[i];
        s->Print_Info(s);
    }

    Vector_Clear_Shapes(&v);

    return 0;
}