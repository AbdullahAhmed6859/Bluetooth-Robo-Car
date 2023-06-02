#include <SoftwareSerial.h>

const int leftFwd = 9;
const int leftBwd = 8;
const int rightFwd = 7;
const int rightBwd = 6;

const int rxPin = 0;
const int txPin = 1;

SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(rightBwd, OUTPUT);
  pinMode(leftBwd, OUTPUT);
  pinMode(rightFwd, OUTPUT);
  pinMode(leftFwd, OUTPUT);
  mySerial.begin(9600);
}

void loop() {
  char state = 'S';
  unsigned long currentTime = millis();
  unsigned long timeAvaialble;

  if (mySerial.available() > 0) {
    state = mySerial.read();
    timeAvaialble = millis();

  } else {

    if (((currentTime - timeAvaialble) > 500) && state != 'S') {
      state = 'S';
    }
  }

  if (state == 'F') {
    forward();
  } else if (state == 'B') {
    backward();
  } else if (state == 'L') {
    left();
  } else if (state == 'R') {
    right();
  } else if (state == 'S') {
    stop();
  }
}

void forward() {
  digitalWrite(rightBwd, LOW);
  digitalWrite(leftBwd, LOW);
  digitalWrite(rightFwd, HIGH);
  digitalWrite(leftFwd, HIGH);
}

void backward() {
  digitalWrite(rightFwd, LOW);
  digitalWrite(leftFwd, LOW);
  digitalWrite(rightBwd, HIGH);
  digitalWrite(leftBwd, HIGH);
}

void right() {
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightBwd, LOW);
  digitalWrite(leftBwd, LOW);
  digitalWrite(leftFwd, HIGH);
}

void left() {
  digitalWrite(rightBwd, LOW);
  digitalWrite(leftBwd, LOW);
  digitalWrite(leftFwd, LOW);
  digitalWrite(rightFwd, HIGH);
}

void stop() {
  digitalWrite(rightFwd, LOW);
  digitalWrite(rightBwd, LOW);
  digitalWrite(leftBwd, LOW);
  digitalWrite(leftFwd, LOW);
}