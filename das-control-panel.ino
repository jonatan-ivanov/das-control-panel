//http://www.pjrc.com/teensy/td_libs_Encoder.html
//https://github.com/PaulStoffregen/Encoder
#include <Encoder.h>
#include <Keyboard.h>

int ENCODER_BUTTON_PIN = 4;
int ACCELERATION = 4; //Accelerationeration factor for volume, use between 1 and 8

int K1 = 8;
int K2 = 7;
int K3 = 6;
int K4 = 5;

int DELAY_BEFORE_KEY_RELEASE = 100;

//Pins 2,3 are the interrupt pins on a Leonardo/Uno, which give best performance with a rotary encoder
//Use other pins if you wish, but performance may suffer. Avoid using pins that have LEDs attached
Encoder encoder(2, 3);
long lastPosition = 0;

void setup() {
  pinMode(ENCODER_BUTTON_PIN, INPUT);
  pinMode(K1, INPUT);
  pinMode(K2, INPUT);
  pinMode(K3, INPUT);
  pinMode(K4, INPUT);

  //Activate internal pull-up resistors
  digitalWrite(ENCODER_BUTTON_PIN, HIGH);
  digitalWrite(K1, HIGH);
  digitalWrite(K2, HIGH);
  digitalWrite(K3, HIGH);
  digitalWrite(K4, HIGH);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  long currentPosition = encoder.read() / ACCELERATION;
  if (currentPosition != lastPosition) {
    Serial.println(currentPosition);
    if (lastPosition < currentPosition)
      volumeUp();
    else
      volumeDown();

    lastPosition = currentPosition;
  }

  handleKeyPress(ENCODER_BUTTON_PIN, playOrPause, "PLAY_OR_PAUSE");
  handleKeyPress(K1, lock, "LOCK");
  handleKeyPress(K2, mute, "MUTE");
  handleKeyPress(K3, next, "NEXT");
  handleKeyPress(K4, prev, "PREV");

  delay(50);
}

int handleKeyPress(int pin, void (*action)(), String actionName) {
  int state = digitalRead(pin);
  if (!state) {
    Serial.println(actionName);
    (*action)();
  }
  do { state = digitalRead(pin); } while (!state);

  return state;
}

void mute() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F7);
  releaseAll();
}

void prev() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F8);
  releaseAll();
}

void playOrPause() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F9);
  releaseAll();
}

void next() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F10);
  releaseAll();
}

void volumeDown() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F11);
  releaseAll();
}

void volumeUp() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F12);
  releaseAll();
}

void lock() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  releaseAll();
}

void releaseAll() {
  delay(DELAY_BEFORE_KEY_RELEASE);
  Keyboard.releaseAll();
}
