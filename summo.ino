// Declaration of IR pins
#define fIrRP A0
#define fIrLP A1
#define bIrRP A2
#define bIrLP A3

// Declaration of R motor controller pins
#define eR 11
#define in2 12
#define in1 13
// Declaration of L motor controller pins
#define eL 10
#define in4 9
#define in3 8

unsigned long int T1 = 0, T2 = 0;
unsigned long int E1 = 0, E2 = 0;
unsigned long int D1 = 0, D2 = 0;
unsigned long int c1 = 0, c2 = 0;

uint8_t TimeInterval = 100;

void setup()
{
    pinMode(fIrRP, INPUT);
    pinMode(fIrLP, INPUT);
    pinMode(bIrRP, INPUT);
    pinMode(bIrLP, INPUT);

    pinMode(eR, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in1, OUTPUT);

    pinMode(eL, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(2, INPUT);

    Serial.begin(115200);
    setSpeed(eL, 100);
    setSpeed(eR, 100);
}

void loop()
{
    // Serial.println(irCh('f', 'l'));
    T2 = millis();
    c2 = millis();
    delay(500);
    turnL(10);
    turnR(10);
}

bool irCh(char forb, char side)
{
    if (forb == 'f' && side == 'r')
        return !(digitalRead(fIrRP));
    else if (forb == 'f' && side == 'l')
        return !(digitalRead(fIrLP));
    else if (forb == 'b' && side == 'r')
        return !(digitalRead(bIrRP));
    else if (forb == 'b' && side == 'l')
        return !(digitalRead(fIrRP));
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
    if ((T2 - T1) >= deg * TimeInterval)
    {
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        T1 = millis();
    }
    c2 = millis();
    if ((c2 - c1) >= deg * TimeInterval)
    {
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        c1 = millis();
    }
}

void turnL(int deg)
{
    E2 = millis();
    if ((E2 - E1) >= deg * TimeInterval)
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in4, HIGH);
        E1 = millis();
    }
    D2 = millis();
    if ((D2 - D1) >= deg * TimeInterval)
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
