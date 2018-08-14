#define datain 13
#define ledPin 12

unsigned int temp = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop() {
  temp = digitalRead(datain);

  if (temp == 1)
  {
    digitalWrite(ledPin, LOW);
  }

  else if (temp == 0)
  {
    digitalWrite(ledPin, HIGH);
  }
}

