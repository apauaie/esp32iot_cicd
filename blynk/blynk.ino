#include <ESP32Servo.h>

int speed = 55;
int ldr;

#define BLYNK_TEMPLATE_ID           "TMPLxpx1_aY-"
#define BLYNK_DEVICE_NAME           "Kereta Remote"
#define BLYNK_AUTH_TOKEN            "V3qK7ZA8a2-MF0Qnaod1m2bGxebA2_PC"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Mindspark";
char pass[] = "SparkMe1";
BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
  // Turn on RGB based on LDR value. Here Red if LDR reading is less than 100. otherwise will be white

  if (pinValue == 1) {
	digitalWrite(13,HIGH);
	digitalWrite(14,LOW);
	analogWrite(25,speed);
	digitalWrite(18,HIGH);
	digitalWrite(19,LOW);
	analogWrite(15,speed);

  } else {
	digitalWrite(13,HIGH);
	digitalWrite(14,LOW);
	analogWrite(25,0);
	digitalWrite(18,HIGH);
	digitalWrite(19,LOW);
	analogWrite(15,0);

  }
}

BLYNK_WRITE(V1)
{
int pinValue = param.asInt();
  // Turn on RGB based on LDR value. Here Red if LDR reading is less than 100. otherwise will be white

  if (pinValue == 1) {
	digitalWrite(13,LOW);
	digitalWrite(14,HIGH);
	analogWrite(25,speed);
	digitalWrite(18,LOW);
	digitalWrite(19,HIGH);
	analogWrite(15,speed);

  } else {
	digitalWrite(13,HIGH);
	digitalWrite(14,LOW);
	analogWrite(25,0);
	digitalWrite(18,HIGH);
	digitalWrite(19,LOW);
	analogWrite(15,0);

  }
}

BLYNK_WRITE(V2)
{
int pinValue = param.asInt();
  // Turn on RGB based on LDR value. Here Red if LDR reading is less than 100. otherwise will be white

  if (pinValue == 1) {
	digitalWrite(13,HIGH);
	digitalWrite(14,LOW);
	analogWrite(25,speed);
	digitalWrite(18,LOW);
	digitalWrite(19,HIGH);
	analogWrite(15,speed);

  } else {
	digitalWrite(13,HIGH);
	digitalWrite(14,LOW);
	analogWrite(25,0);
	digitalWrite(18,HIGH);
	digitalWrite(19,LOW);
	analogWrite(15,0);

  }
}

BLYNK_WRITE(V3)
{
int pinValue = param.asInt();
  // Turn on RGB based on LDR value. Here Red if LDR reading is less than 100. otherwise will be white

  if (pinValue == 1) {
	digitalWrite(13,LOW);
	digitalWrite(14,HIGH);
	analogWrite(25,speed);
	digitalWrite(18,HIGH);
	digitalWrite(19,LOW);
	analogWrite(15,speed);

  } else {
	digitalWrite(13,HIGH);
	digitalWrite(14,LOW);
	analogWrite(25,0);
	digitalWrite(18,HIGH);
	digitalWrite(19,LOW);
	analogWrite(15,0);

  }
}

BlynkTimer Timer1;

void Timer1_TimerEvent()
{
  ldr = (int)(analogRead(39));
  Blynk.virtualWrite(V5, ldr);
}

Servo servo_23;
BLYNK_WRITE(V9)
{
int pinValue = param.asInt();
  // Turn on RGB based on LDR value. Here Red if LDR reading is less than 100. otherwise will be white

  if (pinValue == 1) {
	servo_23.write(0);

  } else {

  }
}

BLYNK_WRITE(V6)
{
int pinValue = param.asInt();
  // Turn on RGB based on LDR value. Here Red if LDR reading is less than 100. otherwise will be white

  if (pinValue == 1) {
	servo_23.write(45);

  } else {

  }
}

BLYNK_WRITE(V10)
{
int pinValue = param.asInt();
  speed = (int)(pinValue);
}

Servo servo_5;
BLYNK_WRITE(V11)
{
int pinValue = param.asInt();
  // Turn on RGB based on LDR value. Here Red if LDR reading is less than 100. otherwise will be white

  if (pinValue == 1) {
	servo_5.write(0);

  } else {

  }
}

BLYNK_WRITE(V12)
{
int pinValue = param.asInt();
  // Turn on RGB based on LDR value. Here Red if LDR reading is less than 100. otherwise will be white

  if (pinValue == 1) {
	servo_5.write(45);

  } else {

  }
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(13,OUTPUT);
 pinMode(14,OUTPUT);
 pinMode(25,OUTPUT);
  pinMode(18,OUTPUT);
 pinMode(19,OUTPUT);
 pinMode(15,OUTPUT);
  pinMode(39, INPUT);
  Timer1.setInterval(500, Timer1_TimerEvent);

  servo_23.attach(23);
  servo_5.attach(5);
}

void loop() {
  Blynk.run();
  Timer1.run();
}