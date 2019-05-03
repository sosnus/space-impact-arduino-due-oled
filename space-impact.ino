#include <ISALedControl.h>
#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>
#include <ISAOLED.h>
#include <ISALedControl.h>

#include "Control.h"
#include "Hero.h"
#include "Brick.h"

#define MAX_BRICKS 6
#define LEVEL 4

ISAOLED oled;
ISALiquidCrystal lcd;
ISALedControl lc;

Control control;
Hero hero;
Brick brick1[MAX_BRICKS];

int score = 0;

void gameDelay(void)
{
  int pot = analogRead(POT) + 1;
  while (pot > 0)
  {
    delay(1);
    pot--;
  }
}

void setup()
{
  oled.begin();
  lcd.begin();
  lc.init();
  oled.clear();
  oled.gotoXY(0, 0);
  oled.print("Space-impact 2019");
  oled.gotoXY(0, 1);
  oled.print("Stanislaw Pulawski");
  oled.gotoXY(0, 2);
  oled.print("t: @StaPulawski");
  oled.renderAll();

  //GAME INIT
  delay(1000);
  lc.setLed(0, 2, true);
  lc.setLed(0, 1, true);
  lc.setLed(0, 0, true);
  oled.clear();
  score = 0;
}

void gameOver()
{
  oled.clear();
  oled.gotoXY(0, 0);
  oled.print("GAME OVER");
  oled.gotoXY(0, 1);
  oled.print("SCORE: ");
  oled.print(score);
  oled.gotoXY(0, 2);
  oled.print("Space-impact");
  oled.gotoXY(0, 3);
  oled.print("Stanislaw Pulawski 2019");
  oled.gotoXY(0, 4);
  oled.print("twitter.com/stapulawski");
  oled.renderAll();
}

void loop()
{
  // GAME SETUP 1. Hero move, 2. Brick update, 3. Brick respawn
  hero.Move(control.getJoyX(), control.getJoyY());
  for (size_t i = 0; i < MAX_BRICKS; i++)
  {
    if (brick1[i].working == true)
    {
      brick1[i].Fall();

      if (brick1[i].Collision(hero.GetX(), hero.GetY()))
      {
        hero.life--;
      }
    }
  }
  // Brick respawn
  if (random(0, LEVEL) == 0)
  {
    for (size_t i = 0; i < MAX_BRICKS; i++)
    {
      if (brick1[i].working == false)
      {
        brick1[i].working = true;
        break;
      }
    }
  }

  score++;
  // GRAPHIC SETUP
  oled.clear();
  oled.gotoXY(hero.GetX(), hero.GetY()); //calc and set hero
  oled.print(">");
  for (size_t i = 0; i < MAX_BRICKS; i++)
  {
    if (brick1[i].working == true)
    {
      oled.gotoXY(brick1[i].GetX(), brick1[i].GetY()); //calc and set brick1
      oled.print("#");
    }
  }
  oled.renderAll(); // OLED end loop

  // HUD SETUP
  lcd.clear();
  lcd.print("Score: ");
  lcd.print(score);
  lcd.setCursor(0, 1);
  lcd.print("X:");
  lcd.print(hero.GetX());
  lcd.print(" Y:");
  lcd.print(hero.GetY());

  lc.setLed(0, hero.life, false);
  while (hero.life == 0)
  {
    gameOver();
while(1);
  }
  gameDelay();
}
