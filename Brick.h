#include <string.h>

#define sizeX 119
#define RESP_PX 115
#define sizeY 7
#define jumpX 5
#define BRICK_STEP 5



class Brick
{
  public:
    Brick();
    bool Collision(int _x, int _y);

    void Out();
    void Fall();
    int GetX();
    int GetY();
    bool working = false;

  private:
    int x = RESP_PX;
    int y = 3; // not 0

    const int border_x_left = 0;
    const int border_x_right = sizeX; //128-6;
    const int border_y_up = 0;
    const int border_y_down = sizeY; //7;
};