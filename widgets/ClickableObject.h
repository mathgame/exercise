#ifndef CLICKABLE_OBJECT_H
#define CLICKABLE_OBJECT_H

class Point;

class ClickableObject
{
public:
    ClickableObject() {}

    virtual void OnMousePressed(Point mousePos);
    virtual void OnMouseReleased(Point mousePos);

protected:

};

#endif //CLICKABLE_OBJECT_H
