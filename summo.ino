#include <Arduino.h>
// Declaration of IR pins
<<<<<<< HEAD
#define FRir A0
#define FLir A1
#define BRir A2
#define BLir A3
=======
#define fIrRP A0
#define fIrLP A1
#define bIrRP A2
#define bIrLP A3
>>>>>>> 35a46b3d06658f9c4a1de927f7088270393a15fa

// Declaration of R motor controller pins
#define eR 11
#define in2 12
#define in1 13
// Declaration of L motor controller pins
#define eL 10
#define in4 9
#define in3 8

<<<<<<< HEAD
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
=======
unsigned long long int cu = 0;
// int p1000 = 1000;
// unsigned long long int time_now1 = 0;
// unsigned long long int time_now2 = 0;
>>>>>>> 35a46b3d06658f9c4a1de927f7088270393a15fa

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
    setSpeed(eL, 255);
    setSpeed(eR, 255);
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
int sonicF()
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
        return -1;
    else
        return duration / 29 / 2;
}
int sonicB()
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
void setSpeed(char Motor, int speed)
{
    analogWrite(Motor, speed); // eL and eR
}
void forward()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
}
void rev()
{
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
void turnR(int deg)
{

    T2 = millis();
    if ((T2 - T1) >= (deg * TimeInterval))
    {
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        T1 = millis();
        Serial.print("HIGH:");
        Serial.println(millis());
        Serial.print("T1: ");

        Serial.println(T1);
        Serial.print("T2: ");

        Serial.println(T2);
    }
    c2 = millis();
    if ((c2 - c1) >= (deg * TimeInterval))
    {
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        c1 = millis();
        Serial.print("LOW:");
        Serial.println(millis());
        Serial.print("c1: ");
        Serial.println(c1);

        Serial.print("c2: ");
        Serial.println(c2);
    }
}

void turnL(int deg)
{
    E2 = millis();
    if ((E2 - E1) >= (deg * TimeInterval))
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in4, HIGH);
        E1 = millis();
    }
    D2 = millis();
    if ((D2 - D1) >= (deg * TimeInterval))
    {
        digitalWrite(in1, LOW);
        digitalWrite(in4, LOW);
        D1 = millis();
    }
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
// void fight()
// {
//     if digitalRead ()
//         ;
// }