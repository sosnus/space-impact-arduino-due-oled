#include "Arduino.h"
#include "Control.h"
#include <ISADefinitions.h>

Control::Control()
{
}

int Control::getJoyX()
{
    int j_temp = analogRead(JOY1X);
    if (j_temp < J_LOW)
        return -1 * REVERSE_X;
    else if (j_temp < J_HIGH)
        return 0;
    else
        return 1 * REVERSE_X;
}
int Control::getJoyY()
{
    int j_temp = analogRead(JOY1Y);
    if (j_temp < J_LOW)
        return 1 * REVERSE_Y;
    else if (j_temp < J_HIGH)
        return 0;
    else
        return -1 * REVERSE_Y;
}
