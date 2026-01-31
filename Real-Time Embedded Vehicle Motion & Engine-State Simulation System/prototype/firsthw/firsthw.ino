
#define IN1 26  
#define IN2 27  
#define IN3 25  
#define IN4 33 
#define ENGINE_LED 2 

int speedPWM = 170; 
bool engineON = false;
void setup() {
  Serial.begin(115200);

  pinMode(IN2, OUTPUT);
  pinMode(IN4, OUTPUT);
  ledcAttach(IN1, 20000, 8);   
  ledcAttach(IN3, 20000, 8);
  pinMode(ENGINE_LED, OUTPUT);
  digitalWrite(ENGINE_LED, LOW);
  stopMotors();

  Serial.println("\n=== ESP32 + L298N CAR CONTROL ===");
  Serial.println("1 - Engine ON");
  Serial.println("2 - Forward (Accelerate)");
  Serial.println("3 - Brake");
  Serial.println("4 - Stop");
  Serial.println("5 - Turn Left");
  Serial.println("6 - Turn Right");
  Serial.println("================================");
}

// ================= LOOP =================
void loop() {
  if (Serial.available()) {
    int cmd = Serial.parseInt();
    Serial.read();

    switch (cmd) {
      case 1: engineOn(); break;
      case 2: forward(); break;
      case 3: brake(); break;
      case 4: stopMotors(); break;
      case 5: turnLeft(); break;
      case 6: turnRight(); break;
      default:
        Serial.println("Invalid command");
        break;
    }
  }
}

// ================= FUNCTIONS =================

void engineOn() {
  engineON = true;
  digitalWrite(ENGINE_LED, HIGH);
  Serial.println("ENGINE ON");
}



void forward() {
  if (!engineON) {
    Serial.println("ENGINE OFF - CANNOT MOVE");
    return;
  }
  speedPWM += 30;

  if (speedPWM > 255) speedPWM = 255;
  

  // Forward direction
  digitalWrite(IN2, LOW);   // left forward
  digitalWrite(IN4, LOW);   // right forward

  // Speed
  ledcWrite(IN1, speedPWM);
  ledcWrite(IN3, speedPWM);

  Serial.println("FORWARD | SPEED = increased by +10 ");
}




void brake() {
  if (!engineON) return;

  speedPWM -= 20;
  if (speedPWM < 0) speedPWM = 0;

  ledcWrite(IN1, speedPWM);
  ledcWrite(IN3, speedPWM);

  Serial.println("BRAKE | SPEED = decreadsed by -10  ");
  //Serial.println(speedPWM);

  if (speedPWM == 0) stopMotors();
}

void stopMotors() {
  engineON = false;
  speedPWM = 0;

  ledcWrite(IN1, 0);
  ledcWrite(IN3, 0);

  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
   digitalWrite(ENGINE_LED, LOW);

  Serial.println("CAR STOPPED");
}

void turnLeft() {
  if (!engineON) return;

  // Left backward, right forward
  digitalWrite(IN2, HIGH);   // left backward
  digitalWrite(IN4, LOW);    // right forward

  ledcWrite(IN1, speedPWM);
  ledcWrite(IN3, speedPWM);

  Serial.println("TURN LEFT");
}

void turnRight() {
  if (!engineON) return;

  // Left forward, right backward
  digitalWrite(IN2, LOW);    // left forward
  digitalWrite(IN4, HIGH);   // right backward

  ledcWrite(IN1, speedPWM);
  ledcWrite(IN3, speedPWM);

  Serial.println("TURN RIGHT");
}
