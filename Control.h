
// CONTROL SETTINGS
#define J_DIFF 65
#define REVERSE_X -1
#define REVERSE_Y 1
#define J_LOW 512 - J_DIFF
#define J_HIGH 512 + J_DIFF

class Control
{
public:
  Control();
  int getJoyX();
  int getJoyY();
};
