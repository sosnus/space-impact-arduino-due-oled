#include "Arduino.h"
#include "Hero.h"

Hero::Hero()
{
}

void Hero::Move(int _x, int _y)
{
    if(x+_x < border_x_left || x+_x > border_x_right);
    else   x += jumpX *  _x;
    
    if(y+ _y < border_y_up|| y+_y > border_y_down );
    else  y += _y;
}

int Hero::GetX()
{
    return x;
}
int Hero::GetY()
{
    return y;
}