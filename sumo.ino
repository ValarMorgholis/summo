// declaration of IR pins
#define fIrRP A0
#define fIrLP A1
#define bIrRP A2
#define bIrLP A3
unsigned long long int cu = 0;

void setup()
{

    pinMode(fIrRP, INPUT);
    pinMode(fIrLP, INPUT);
    pinMode(bIrRP, INPUT);
    pinMode(bIrLP, INPUT);

    cu = millis();
    Serial.begin(9600);
}

void loop()
{

    if (millis() - cu >= 500)
    {
        }
}

bool irR(int irPin)
{
    bool irV = 0;
    irV = digitalRead(irPin);
    return irV;
}
