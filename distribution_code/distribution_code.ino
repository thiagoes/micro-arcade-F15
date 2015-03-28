#include <gamma.h>
#include <RGBmatrixPanel.h>
#include <Adafruit_GFX.h>

// define the wiring of the LED screen
const uint8_t CLK  = 8;
const uint8_t LAT = A3;
const uint8_t OE = 9;
const uint8_t A = A0;
const uint8_t B = A1;
const uint8_t C = A2;

// define the wiring of the inputs
const int POTENTIOMETER_PIN_NUMBER = 5;
const int BUTTON_PIN_NUMBER = 10;

// global constant for the number of Invaders in the game
const int NUM_ENEMIES = 16;

// a global variable that represents the LED screen
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

class Invader {
  public:
    Invader() {
      x = 0;
      y = 0;
      strength = 0;
    }
  private:
    int x;
    int y;
    int strength;
};

class Cannonball {
  public:
    Cannonball() {
      x = 0;
      y = 0;
    }
  private:
    int x;
    int y;
};

class Player {
  public:
    Player() {
      x = 0;
      y = 0;
      lives = 3;
    }
  private:
    int x;
    int y;
    int lives;
};

class Game {
  public:
    Game() {
      level = 0;
    }

    // Requires: Nothing.
    // Modifies: global variable matrix
    // Effects: sets up a new game of Space Invaders
    void setup() {
    }

    // Requires: Nothing.
    // Modifies: global variable matrix
    // Effects: displays a runs Space Invaders!
    void loop(int potentiometer_value, bool button_pressed) {
    }

  private:
    int level;
    Player player;
    Cannonball ball;
    Invader enemies[NUM_ENEMIES];
};

// a global variable that represents the game Space Invaders
Game game;

// see http://arduino.cc/en/Reference/Setup
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN_NUMBER, INPUT);
  matrix.begin();

  game.setup();
}

// see http://arduino.cc/en/Reference/Loop
void loop() {
  int potentiometer_value = analogRead(POTENTIOMETER_PIN_NUMBER);
  bool button_pressed = (digitalRead(BUTTON_PIN_NUMBER) == HIGH);

  game.loop(potentiometer_value, button_pressed);
}
