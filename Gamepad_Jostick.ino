#include <Servo.h>

int Xpin = A0;
int Ypin = A1;
int btnPin = 7;
int buzzPin = 9;
int xVal;
int yVal;
int btnVal;
Servo servoX;
Servo servoY;

//n

void setup() {
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(btnPin, INPUT_PULLUP); // Usar resistencia pull-up interna
  pinMode(buzzPin, OUTPUT);
  servoX.attach(8);
  servoY.attach(11);
  Serial.begin(9600);
}

void loop() {
  xVal = analogRead(Xpin);
  yVal = analogRead(Ypin);
  btnVal = digitalRead(btnPin);

  // int servoXAngle = map(xVal, 0, 1023, 0, 180);
  int servoYAngle = map(yVal, 0, 1023, 0, 180);

  // servoX.write(servoXAngle);
  servoY.write(servoYAngle);

  // Controlar ambos servo motores para movimiento bidireccional
  if (xVal < 450) {
    // Mover a la izquierda
    servoX.write(0); // Ángulo para mover a la izquierda
  } else if (xVal > 600) {
    // Mover a la derecha
    servoX.write(180); // Ángulo para mover a la derecha
  }

  if (yVal < 450) {
    // Mover hacia adelante
    servoY.write(0); // Ángulo para mover hacia adelante
  } else if (yVal > 600) {
    // Mover hacia atrás
    servoY.write(180); // Ángulo para mover hacia atrás
  }

  // Detener ambos servo motores cuando el botón central está presionado
  if (btnVal == LOW) {
    servoX.write(30); // Ángulo neutral
    servoY.write(30); // Ángulo neutral
    digitalWrite(buzzPin, HIGH);
  } else {
    digitalWrite(buzzPin, LOW);
  }

  delay(100);
}