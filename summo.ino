#include <Arduino.h>
// Declaration of IR pins
#define FRir A0
#define FLir A1
#define BRir A2
#define BLir A3

// Declaration of R motor controller pins
#define eR 11
#define in2 12
#define in1 13
// Declaration of L motor controller pins
#define eL 10
#define in4 9
#define in3 8

// Declaration of ultrasonic pins
const int trig_echoF = 5;
const int trig_echoB = 6;

// Declaration of lever and blade keys pins
#define u 2
#define d 3

#define uK A4
#define dK A5

unsigned long int T1 = 0, T2 = 0;
unsigned long int E1 = 0, E2 = 0;
unsigned long int D1 = 0, D2 = 0;
unsigned long int c1 = 0, c2 = 0;

uint8_t TimeInterval = 100;

void setup()
{

    pinMode(FRir, INPUT);
    pinMode(FLir, INPUT);
    pinMode(BRir, INPUT);
    pinMode(BLir, INPUT);

    pinMode(eR, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in1, OUTPUT);

    pinMode(eL, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(in3, OUTPUT);

    pinMode(u, OUTPUT);
    pinMode(d, OUTPUT);

    pinMode(uK, INPUT);
    pinMode(dK, INPUT);

    Serial.begin(115200);
}

void loop()
{
    // Serial.println(irCh('f', 'l'));
    // Serial.print(sonicF());
    // Serial.print("cmF");
    // Serial.println();

    // delay(1000);
    // Serial.print(sonicB());
    // Serial.print("cmB");
    // Serial.println();

    // turnR(10);
    // turnR(20);
}
int sonicFR()
{
    long cm, duration;
    pinMode(trig_echoF, OUTPUT);

    digitalWrite(trig_echoF, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_echoF, HIGH);
    delayMicroseconds(5);
    digitalWrite(trig_echoF, LOW);

    pinMode(trig_echoF, INPUT);
    duration = pulseIn(trig_echoF, HIGH);

    if ((duration / 29 / 2) > 250)
        return -1; // Out of range
    else if ((duration / 29 / 2) > 100)
        return -2; // Not detect anything
    else
        return duration / 29 / 2; // Move Mf
}
int sonicFL()
{
    long cm, duration;
    pinMode(trig_echoB, OUTPUT);

    digitalWrite(trig_echoB, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_echoB, HIGH);
    delayMicroseconds(5);
    digitalWrite(trig_echoB, LOW);

    pinMode(trig_echoB, INPUT);
    duration = pulseIn(trig_echoB, HIGH);

    if ((duration / 29 / 2) > 250)
        return -1;
    else
        return duration / 29 / 2;
}
void forward(int speed)
{
    analogWrite(eR, speed);
    analogWrite(eL, speed);

    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
}
void rev(int speed)
{
    analogWrite(eR, speed);
    analogWrite(eL, speed);

    digitalWrite(in2, HIGH);
    digitalWrite(in4, HIGH);
}
void stopF()
{
    digitalWrite(in1, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in4, HIGH);
    delay(100);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
}
void stopR()
{
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
    delay(100);
    digitalWrite(in1, LOW);
    digitalWrite(in3, LOW);
}
void turnR()
{
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);

    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
}

void turnL()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in4, HIGH);

    digitalWrite(in1, LOW);
    digitalWrite(in4, LOW);
}
void off()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void up()
{
    if (analogRead(uK) == 0)
    {
        digitalWrite(d, LOW);
        digitalWrite(u, HIGH);
    }
    else
        digitalWrite(u, LOW);
}
void down()
{
    if (analogRead(dK) == 0)
    {
        digitalWrite(u, LOW);
        digitalWrite(d, HIGH);
    }
    else
        digitalWrite(d, LOW);
}
void checkForMovment()
{
    if (digitalRead(FRir == 0) && digitalRead(FLir == 0) && digitalRead(BRir == 0) && digitalRead(BLir == 0))
    {
        if (sonicFR() == -1 || sonicFL() == -2) // if nothing detected just walk
            nsMovment();
        else if (sonicFR() < sonicFL())
        {
            while (sonicFL() - sonicFR() > 20)
            {
                turnL();
            }
        }
    }
}
void nsMovment()
{
    forward(255);
    if (digitalRead(FRir == 1))
    {
        while ((FRir == 1))
        {
            turnR();
        }
        rev(255);
        //
    }
}
void dontGetOut()
{
}