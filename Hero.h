#define sizeX   119
#define sizeY   7
#define jumpX   5

class Hero
{
  public:
    Hero();
    void Move(int _x, int _y);
    int GetX();
    int GetY();
    int life = 3;

  private:
    int x = 0;
    int y = 0;

    const int border_x_left = 0;
    const int border_x_right = sizeX; //128-6;
    const int border_y_up = 0;
    const int border_y_down = sizeY; //7;
};