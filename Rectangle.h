#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED


class Rectangle{
public:
    Rectangle() {}

    Rectangle(int x, int y, int dx, int dy)
    {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
    }

    static bool isOverlap(Rectangle*, Rectangle*);

    int dx, dy;
    int x, y;
};



#endif // RECT_H_INCLUDED
