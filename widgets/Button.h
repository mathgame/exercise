#ifndef BUTTON_H
#define BUTTON_H

class Point;

class Button
{
public:
    void Init();

    void OnMouseButtonPressed(Point mousePos);
};

#endif //BUTTON_H
