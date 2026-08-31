#include <Arduboy2.h>
#include "image.h"

Arduboy2 arduboy;

int x = 3;
int y = 3;
int oldx = x;
int oldy = y;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
}

void loop() {
  if (!arduboy.nextFrame()) return;
  arduboy.pollButtons();
  arduboy.clear();
  arduboy.drawBitmap(0, 0, border, 128, 64, WHITE);
  generateMaze();
  player(1);
  arduboy.display();
}


void player(int speed) {
  if (arduboy.pressed(UP_BUTTON)) {
    y = y - speed;
  }
  if (arduboy.getPixel(x, y) == WHITE) {
    y = oldy;
  } else {
    if (arduboy.pressed(DOWN_BUTTON)) {
      y = y + speed;
    }
    if (arduboy.getPixel(x, y) == WHITE) {
      y = oldy;
    }
  }
  if (arduboy.pressed(LEFT_BUTTON)) {
    x = x - speed;
  }
  if (arduboy.getPixel(x, y) == WHITE) {
    x = oldx;
  } else {
    if (arduboy.pressed(RIGHT_BUTTON)) {
      x = x + speed;
    }
    if (arduboy.getPixel(x, y) == WHITE) {
      x = oldx;
    }
  }
  x = constrain(x, 0, 127);
  y = constrain(y, 1, 63);
  arduboy.drawPixel(x, y, WHITE);
  oldx = x;
  oldy = y;
}


void generateMaze() {
  random(4);
}