#include "Arduino.h"
#include "Brick.h"

Brick::Brick()
{
}

void Brick::Out()
{
    working = false;
    x = RESP_PX;              // end of screen line
    y = random(0, sizeY); // random
}

bool Brick::Collision(int _x, int _y)
{
    if (_x == x && _y == y)
        return true;
    else
        return false;
}

void Brick::Fall()
{
    x -= BRICK_STEP;
    if (x < border_x_left)
        this->Out();
}

int Brick::GetX()
{
    return x;
}
int Brick::GetY()
{
    return y;
}