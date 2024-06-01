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

unsigned long long int cu = 0;

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

    cu = millis();
    Serial.begin(9600);
    setSpeed(eL, 255);
    setSpeed(eR, 255);
    // forward();
    // delay(5000);
    // stopF();

    turn('r');
    delay(2000);
    allOff();
    turn('l');
    delay(2000);
    allOff();
}

void loop()
{

    // if (millis() - cu >= 500)
    // {
    // }
}

bool irR(int irPin)
{
    bool irV = 0;
    irV = digitalRead(irPin);
    return irV;
}
void setSpeed(char Motor, int speed)
{

    analogWrite(Motor, speed);
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
    digitalWrite(in1, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in4, HIGH);
    delay(100);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
}
void turn(char dir)
{
    if (dir == 'r')
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in4, HIGH);
    }
    else if (dir == 'l')
    {
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
    }
}
void allOff()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}