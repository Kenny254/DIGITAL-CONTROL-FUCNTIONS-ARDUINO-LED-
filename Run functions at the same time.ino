void loop() {

    lights1(); 
    lights2();
    motor();

}

void lights1() {

  static unsigned long lastTime = 0;
  const long interval = 3000;
  static bool state = 0;

  unsigned long now = millis();

  if ( now - lastTime > interval && state == 0) {
    state = 1;
    lastTime = now;
    digitalWrite(enablePWMPin, HIGH);
    digitalWrite(controlPinA, HIGH);
    digitalWrite(controlPinB, LOW);
  }

  if ( now - lastTime > interval && state == 1) {
    state = 0;
    lastTime = now;
    digitalWrite(controlPinA, LOW);
    digitalWrite(controlPinB, HIGH);
  }
}

void lights2() {

  static unsigned long lastTime = 0;
  const long interval = 250;
  static bool state = 0;

  unsigned long now = millis();

  if ( now - lastTime > interval && state == 0) {
    state = 1;
    lastTime = now;
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(blue1, LOW);
    digitalWrite(blue2, LOW);
  }

  if ( now - lastTime > interval && state == 1) {
    state = 0;
    lastTime = now;
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue1, HIGH);
    digitalWrite(blue2, HIGH);
  }

}

void motor() {
  int directionA = digitalRead(controlPinA);
  int directionB = digitalRead(controlPinB);
  if (directionA == HIGH && directionB == LOW) {
    digitalWrite(front1, HIGH);
    digitalWrite(front2, HIGH);
    digitalWrite(back1, LOW);
    digitalWrite(back2, LOW);
  } else if (directionA == LOW && directionB == HIGH) {
    digitalWrite(back1, HIGH);
    digitalWrite(back2, HIGH);
    digitalWrite(front1, LOW);
    digitalWrite(front2, LOW);
  } else {
    digitalWrite(front1, LOW);
    digitalWrite(front2, LOW);
    digitalWrite(back1, LOW);
    digitalWrite(back2, LOW);
  }
}
