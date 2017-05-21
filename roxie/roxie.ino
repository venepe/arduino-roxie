#include <SoftwareSerial.h>
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5

SoftwareSerial mySerial(8, 7); // RX, TX  
// Connect HM10      Arduino Uno
//     Pin 1/TXD          Pin 8
//     Pin 2/RXD          Pin 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // If the baud rate of the HM-10 module has been updated,
  // you may need to change 9600 by another value
  // Once you have found the correct baudrate,
  // you can update it using AT+BAUDx command 
  // e.g. AT+BAUD0 for 9600 bauds
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String c;
  if (mySerial.available()) {
    String s = "";
    char c;
    while((c = mySerial.read()) != -1) {
      s += c;
      delay(10);
    }
    if (s == "0")
    {
      // Non-zero input means "turn on LED".
      Serial.println("  0");
      digitalWrite(LED_PIN2, HIGH);
      digitalWrite(LED_PIN3, LOW);
      digitalWrite(LED_PIN4, LOW);
      digitalWrite(LED_PIN5, LOW);
    }
    else if (s == "1")
    {
      // Non-zero input means "turn on LED".
      Serial.println("  1");
      digitalWrite(LED_PIN2, HIGH);
      digitalWrite(LED_PIN3, HIGH);
      digitalWrite(LED_PIN4, LOW);
      digitalWrite(LED_PIN5, LOW);
    }
    else if (s == "2")
    {
      // Non-zero input means "turn on LED".
      Serial.println("  2");
      digitalWrite(LED_PIN2, HIGH);
      digitalWrite(LED_PIN3, HIGH);
      digitalWrite(LED_PIN4, HIGH);
      digitalWrite(LED_PIN5, LOW);
    }
    else if (s == "3")
    {
      // Non-zero input means "turn on LED".
      Serial.println("  3");
      digitalWrite(LED_PIN2, HIGH);
      digitalWrite(LED_PIN3, HIGH);
      digitalWrite(LED_PIN4, HIGH);
      digitalWrite(LED_PIN5, HIGH);
    }
    else
    {
      Serial.println("  -1");
      digitalWrite(LED_PIN2, LOW);
      digitalWrite(LED_PIN3, LOW);
      digitalWrite(LED_PIN4, LOW);
      digitalWrite(LED_PIN5, LOW);
    }
  }
}
