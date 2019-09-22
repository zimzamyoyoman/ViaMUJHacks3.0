int trigPin=13;
int echoPin=9;
int piezoPin=7;
int ledPin=8;
float pingTime;
float targetDistance;
float speedOfSound = 776.5; //Speed of sound in meters per second
float notes[]={493.883,349.228,261.626,};
 
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(piezoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);

  pingTime=pulseIn(echoPin, HIGH);
//  Serial.println(pingTime);  
  pingTime=pingTime/1000000.0; //Converts microseconds to seconds
  pingTime=pingTime/3600;
//  Serial.println(pingTime); 
  targetDistance=63360*speedOfSound*pingTime/2; //Store target distance in inches

  if (targetDistance < 5) {
      tone(piezoPin,notes[0],100);
      digitalWrite(ledPin, HIGH);
      delay(25);
      digitalWrite(ledPin, LOW);
    }
  else if (targetDistance < 10) {
      tone(piezoPin,notes[1],100);
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
    }
  else if (targetDistance < 15) {
      tone(piezoPin,notes[2],100);
      digitalWrite(ledPin, HIGH);
      delay(400);
      digitalWrite(ledPin, LOW);         
  }
  else if (targetDistance < 20) {
      tone(piezoPin, notes[3], 100);
  }

  else if (targetDistance < 25) {
    tone(piezoPin,notes[3],100);
  }
  Serial.println(targetDistance);
  delay(350);
}

