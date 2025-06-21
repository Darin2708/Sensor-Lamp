const int pirPin = 4;     
const int buttonPin = 5;   
const int ledPin = 11;     

bool systemEnabled = false;
bool motionDetected = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(buttonPin, INPUT); 
  
  Serial.begin(9600);
  Serial.println("System initialized");
  Serial.println("Press button to enable/disable system");
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    delay(50); 
    if (digitalRead(buttonPin) == HIGH) { 
      systemEnabled = !systemEnabled;
      Serial.print("System ");
      Serial.println(systemEnabled ? "ENABLED" : "DISABLED");
      digitalWrite(ledPin, LOW); 
      while (digitalRead(buttonPin) == HIGH);
    }
  }
  
  if (systemEnabled) {
    if (digitalRead(pirPin) == HIGH) {
      if (!motionDetected) {
        motionDetected = true;
        digitalWrite(ledPin, HIGH);
        Serial.println("Motion detected - Light ON");
      }
    } else {
      if (motionDetected) {
        motionDetected = false;
        digitalWrite(ledPin, LOW);
        Serial.println("Motion ended - Light OFF");
      }
    }
  } else {
   
    if (digitalRead(ledPin) == HIGH) {
      digitalWrite(ledPin, LOW);
    }
  }

  delay(100); 
}