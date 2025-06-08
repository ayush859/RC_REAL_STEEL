// Motor direction control pins
const int motorLeftForward = 3;
const int motorLeftBackward = 4;
const int motorRightForward = 5;
const int motorRightBackward = 6;

// Motor speed control pins (PWM)
const int speedControlLeft = 9;
const int speedControlRight = 10;

// Speed levels
const int SPEED_LOW = 100;
const int SPEED_MEDIUM = 180;
const int SPEED_HIGH = 255;

int currentSpeed = SPEED_LOW;

void setup() {
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);
  pinMode(speedControlLeft, OUTPUT);
  pinMode(speedControlRight, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command.equalsIgnoreCase("start")) {
      startMotors();
    } else if (command.equalsIgnoreCase("stop")) {
      stopMotors();
    } else if (command.equalsIgnoreCase("left")) {
      turnLeft();
    } else if (command.equalsIgnoreCase("right")) {
      turnRight();
    } else if (command.equalsIgnoreCase("speed up")) {
      increaseSpeed();
    } else if (command.equalsIgnoreCase("speed down")) {
      decreaseSpeed();
    }
  }
}

void startMotors() {
  analogWrite(speedControlLeft, currentSpeed);
  analogWrite(speedControlRight, currentSpeed);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void stopMotors() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, LOW);
}

void turnLeft() {
  analogWrite(speedControlLeft, currentSpeed / 2);
  analogWrite(speedControlRight, currentSpeed);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void turnRight() {
  analogWrite(speedControlLeft, currentSpeed);
  analogWrite(speedControlRight, currentSpeed / 2);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void increaseSpeed() {
  currentSpeed += 20;
  if (currentSpeed > SPEED_HIGH) {
    currentSpeed = SPEED_HIGH;
  }
  analogWrite(speedControlLeft, currentSpeed);
  analogWrite(speedControlRight, currentSpeed);
}

void decreaseSpeed() {
  currentSpeed -= 20;
  if (currentSpeed < SPEED_LOW) {
    currentSpeed = SPEED_LOW;
  }
  analogWrite(speedControlLeft, currentSpeed);
  analogWrite(speedControlRight, currentSpeed);
}
